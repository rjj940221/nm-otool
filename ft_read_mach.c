//
// Created by Robert JONES on 2017/06/20.
//

#include <ctype.h>
#include "Includes/nm-otool.h"
#include "Includes/mach_64.h"

void ft_section_header(){

}

void ft_read_mach(void *data){
	struct mach_header header;

	memcpy(&header, data, MACH_HEADER_SIZE);
	printf("num comd %d\n", header.ncmds);
}

void ft_lc_segment(void * data, int offset){
	struct segment_command_64	seg;
	struct section_64			section;
	uint32_t					i;

	i = 0;
	memcpy(&seg, (data + offset), sizeof(struct segment_command_64));
	offset += sizeof(struct segment_command_64);
	while (i < seg.nsects){
		memcpy(&section, (data + offset), sizeof(struct section_64));
		offset += sizeof(struct section_64);
		i++;
	}
}

void ft_lc_dysymtab(void * data, int offset){
	struct dysymtab_command		seg;

	memcpy(&seg, (data + offset), sizeof(struct dysymtab_command));
}

void ft_lc_symtab(void * data, int offset, t_ofile ofile){
	struct symtab_command		seg;
	struct nlist_64				nls;
	struct section_64			section;
	uint32_t					i;
	char 						sym;
	int 						strarroff;
	int 						nlsoff;
	int							ntype;
	int 						next;

	strarroff = 0;
	nlsoff = 0;
	memcpy(&seg, (data + offset), sizeof(struct symtab_command));
	i = 0;
	while (*((char*)(data + seg.stroff + strarroff)) == '\0')
		strarroff++;
	while (i < seg.nsyms)
	{
		sym = ' ';
		memcpy(&nls, (data + seg.symoff + nlsoff), sizeof(struct nlist_64));
		ntype = (nls.n_type & 0x0e);
		next = (nls.n_type & 0x01);
		//ndes = (nls.n_desc & 0x07);
		printf ("offset: %lu\n", (ofile.lc_segment + sizeof(struct segment_command_64) + ((nls.n_sect - 1) * sizeof(struct section_64))));
		if (ntype == 0x0e && nls.n_sect - 1 >= 0 && ofile.lc_segment != -1){
			memcpy(&section, (data + ofile.lc_segment + sizeof(struct segment_command_64) + ((nls.n_sect - 1) * sizeof(struct section_64))), sizeof(struct section_64));
			if (strcmp(section.sectname,"__text") == 0)
				sym = 't';
			else if (strcmp(section.sectname,"__data") == 0)
				sym = 'd';
			else if (strcmp(section.sectname,"__bss") == 0)
				sym = 'b';
			else if (strcmp(section.sectname,"__common") == 0)
				sym = 'c';
			else
				sym = 's';
			if (strcmp(section.sectname,"__picsymbol_stub") == 0||strcmp(section.sectname,"__symbol_stub") == 0)
				sym = 'i';
		}
		if (ntype == 0x02)
				sym = 'a';
		if (ntype == 0x00)
			sym = 'u';
		if (next == 1)
			sym = (char) toupper(sym);
		printf("\t %c %s\n", sym, (char *)(data + seg.stroff + nls.n_un.n_strx));
		puts("realocation enries:");
		print_bytes((data + section.reloff), 8);
		printf("section off: %d\n", section.offset);
		puts("========");
		print_bytes(&section, sizeof(section));
		nlsoff += sizeof(struct nlist_64);
		i++;
	}
}

void ft_read_mach_64(void *data){
	struct load_command			load_header;
	struct mach_header_64		header;
	uint32_t					i;
	int							offset;
	int							is_big_end;
	t_ofile						ofile;

	ofile = (t_ofile){-1,-1,-1};
	memcpy(&header, data, MACH_64_HEADER_SIZE);
	if (header.magic == MACH_CIGAM_64)
		is_big_end = TRUE;
	else
		is_big_end = FALSE;
	if (is_big_end == TRUE)
		puts("is big end in");
	i = 0;
	offset = sizeof(header);
	while (i < header.ncmds)
	{
		memcpy(&load_header, (data + offset), sizeof(struct load_command));
		if (load_header.cmd == 0x02) {
			ft_lc_symtab(data, offset, ofile);
			ofile.lc_symtab=offset;
		}
		if (load_header.cmd == 0x0b) {
			ft_lc_dysymtab(data, offset);
			ofile.lc_dysymtab = offset;
		}
		if (load_header.cmd == 0x19) {
			//ft_lc_segment(data, offset);
			ofile.lc_segment = offset;
		}
		offset += load_header.cmdsize;
		i++;
	}
}