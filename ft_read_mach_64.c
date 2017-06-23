//
// Created by Robert JONES on 2017/06/20.
//

#include <ctype.h>
#include <stdlib.h>
#include "Includes/nm-otool.h"
#include "Includes/mach_64.h"

void ft_lc_segment(void * data, int offset, t_ofile *ofile){
	struct segment_command_64	seg;
	struct section_64			section;
	uint32_t					i;

	i = 0;
	memcpy(&seg, (data + offset), sizeof(struct segment_command_64));
	ofile->lc_segment = offset;
	offset += sizeof(struct segment_command_64);
	while (i < seg.nsects){
		memcpy(&section, (data + offset), sizeof(struct section_64));
		if (strcmp(section.sectname, "__text") == 0 && strcmp(section.segname, "__TEXT") == 0) {
			ofile->text_sections = (data + offset);
			ofile->text_section_size = section.size;
		}
		offset += sizeof(struct section_64);
		i++;
	}
}

/*void ft_lc_dysymtab(void * data, int offset, t_ofile *ofile){
	struct dysymtab_command		seg;

	memcpy(&seg, (data + offset), sizeof(struct dysymtab_command));
}*/

void ft_get_section_symbole(void * data, t_ofile *ofile, struct nlist_64 *nls, uint32_t i){
	struct section_64			section;

	memcpy(&section, (data + (ofile->lc_segment + sizeof(struct segment_command_64) + ((nls->n_sect - 1) * sizeof(struct section_64)))), sizeof(struct section_64));
	if (strcmp(section.sectname,"__text") == 0)
		ofile->sym_tab[i].symbol = 't';
	else if (strcmp(section.sectname,"__data") == 0)
		ofile->sym_tab[i].symbol = 'd';
	else if (strcmp(section.sectname,"__bss") == 0)
		ofile->sym_tab[i].symbol = 'b';
	else if (strcmp(section.sectname,"__common") == 0)
		ofile->sym_tab[i].symbol = 'c';
	else
		ofile->sym_tab[i].symbol = 's';
	if (strcmp(section.sectname,"__picsymbol_stub") == 0||strcmp(section.sectname,"__symbol_stub") == 0)
		ofile->sym_tab[i].symbol = 'i';
}

void ft_lc_symtab(void * data, int offset, t_ofile *ofile){
	struct symtab_command		seg;
	struct nlist_64				nls;
	uint32_t					i;
	int 						nlsoff;
	int							tmp;

	nlsoff = 0;
	memcpy(&seg, (data + offset), sizeof(struct symtab_command));
	i = 0;
	if ((ofile->sym_tab = malloc(sizeof(t_sym_tab) * seg.nsyms)) == NULL)
		return ;
	ofile->num_sym = seg.nsyms;
	while (i < seg.nsyms)
	{
		memcpy(&nls, (data + seg.symoff + nlsoff), sizeof(struct nlist_64));
		tmp = (nls.n_type & 0x0e);
		if (tmp == 0x0e && nls.n_sect - 1 >= 0 && ofile->lc_segment != -1)
			ft_get_section_symbole(data, ofile, &nls, i);
		if (tmp == 0x02)
			ofile->sym_tab[i].symbol = 'a';
		if (tmp == 0x00)
			ofile->sym_tab[i].symbol = 'u';
		tmp = (nls.n_type & 0x01);
		if (tmp == 1)
			ofile->sym_tab[i].symbol = (char) toupper(ofile->sym_tab[i].symbol);
		ofile->sym_tab[i].ofset = nls.n_value;
		ofile->sym_tab[i].symname = (char *)(data + seg.stroff + nls.n_un.n_strx);
		nlsoff += sizeof(struct nlist_64);
		i++;
	}
}

void ft_read_mach_64(void *data, t_ofile *ofile){
	struct load_command			load_header;
	struct mach_header_64		header;
	uint32_t					i;
	int							offset;

	memcpy(&header, data, MACH_64_HEADER_SIZE);
	if (header.magic == MACH_MAGIC_64)
		ofile->is_big_end = TRUE;
	i = 0;
	offset = sizeof(header);
	while (i < header.ncmds)
	{
		memcpy(&load_header, (data + offset), sizeof(struct load_command));
		if (load_header.cmd == 0x02)
			ft_lc_symtab(data, offset, ofile);
/*
		if (load_header.cmd == 0x0b)
			ft_lc_dysymtab(data, offset, ofile);
*/

		if (load_header.cmd == 0x19)
			ft_lc_segment(data, offset, ofile);
		offset += load_header.cmdsize;
		i++;
	}
}