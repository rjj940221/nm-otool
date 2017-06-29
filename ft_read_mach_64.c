//
// Created by Robert JONES on 2017/06/20.
//

#include <ctype.h>
#include <stdlib.h>
#include "Includes/nm-otool.h"
#include "Includes/mach_64.h"

void ft_lc_segment_64(void *data, int offset, t_ofile *ofile){
	t_seg_cmd_64    seg;
	t_section_64    section;
	uint32_t		i;

	i = 0;
	memcpy(&seg, (data + offset), sizeof(struct s_segment_command_64));
	if (ofile->is_big_end == FALSE)
		ft_revirce_segment_64(&seg);
	offset += sizeof(struct s_segment_command_64);
	while (i < seg.nsects){
		memcpy(&section, (data + offset), sizeof(struct s_section_64));
		if (ofile->is_big_end == FALSE)
			ft_revirce_section_64(&section);
		if (strcmp(section.sectname, "__text") == 0 && strcmp(section.segname, "__TEXT") == 0) {
			ofile->text_sections = (data + offset);
			ofile->text_section_size = section.size;
		}
		offset += sizeof(struct s_section_64);
		i++;
	}
}

void ft_get_section_symbole_64(void *data, t_ofile *ofile, t_nlist_64 *nls, uint32_t i){

	t_section_64    section;

	memcpy(&section, (data + ft_get_section_offset_64(data, ofile->is_big_end, nls)), sizeof(t_section_64));
	if (ofile->is_big_end == FALSE)
		ft_revirce_section_64(&section);
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
	if (strcmp(section.sectname,"__picsymbol_stub") == 0 || strcmp(section.sectname,"__symbol_stub") == 0)
		ofile->sym_tab[i].symbol = 'i';
}

void ft_unmask_ntype_64(t_nlist_64 *nls, t_ofile *ofile, uint32_t i, void *data)
{
	int				tmp;

	tmp = (nls->n_type & 0x0e);
	if (tmp == 0x0e && nls->n_sect - 1 >= 0 )
		ft_get_section_symbole_64(data, ofile, nls, i);
	if (tmp == 0x02)
		ofile->sym_tab[i].symbol = 'a';
	if (tmp == 0x00)
		ofile->sym_tab[i].symbol = 'u';
	tmp = (nls->n_type & 0x01);
	if (tmp == 1)
		ofile->sym_tab[i].symbol = (char) toupper(ofile->sym_tab[i].symbol);
}

void ft_lc_symtab_64(void *data, int offset, t_ofile *ofile){
	t_symtab_cmd    symtab;
	t_nlist_64		nls;
	uint32_t		i;
	int 			nlsoff;

	nlsoff = 0;
	memcpy(&symtab, (data + offset), sizeof(struct s_symtab_command));
	if (ofile->is_big_end == FALSE)
		ft_revirce_symtab(&symtab);
	i = 0;
	if ((ofile->sym_tab = malloc(sizeof(t_sym_tab) * symtab.nsyms)) == NULL)
		return ;
	ofile->num_sym = symtab.nsyms;
	while (i < symtab.nsyms)
	{
		memcpy(&nls, (data + symtab.symoff + nlsoff), sizeof(t_nlist_64));
		if (ofile->is_big_end == FALSE)
			ft_revirce_nlist_64(&nls);
		ft_unmask_ntype_64(&nls, ofile, i, data);
		ofile->sym_tab[i].ofset = nls.n_value;
		ofile->sym_tab[i].symname = (char *)(data + symtab.stroff + nls.n_un.n_strx);
		nlsoff += sizeof(t_nlist_64);
		i++;
	}
}


void ft_read_mach_64(void *data, t_ofile *ofile){
	t_ld_cmd    load_header;
	t_mach_64   header;
	uint32_t	i;
	int			offset;

	memcpy(&header, data, MACH_64_HEADER_SIZE);
	if (header.magic == MACH_MAGIC_64)
		ofile->is_big_end = TRUE;
	if (ofile->is_big_end == FALSE)
		ft_revirce_mach_heder_64(&header);
	i = 0;
	offset = sizeof(header);
	while (i < header.ncmds)
	{
		memcpy(&load_header, (data + offset), sizeof(t_ld_cmd));
		if (ofile->is_big_end == FALSE)
			ft_revirce_ld_cmd(&load_header);
		if (load_header.cmd == LC_SYMTAB)
			ft_lc_symtab_64(data, offset, ofile);
		if (load_header.cmd == 0x19)
			ft_lc_segment_64(data, offset, ofile);
		offset += load_header.cmdsize;
		i++;
	}
}