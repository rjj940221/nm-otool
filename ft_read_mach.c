//
// Created by Robert JONES on 2017/06/20.
//

#include "Includes/nm-otool.h"

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
		printf("section: %s\n", section.sectname);
		print_bytes(&section, sizeof(section));
		offset += sizeof(struct section_64);
		i++;
	}
}

void ft_lc_dysymtab(void * data, int offset){
	struct dysymtab_command		seg;

	printf("offset: %d\n", offset);
	memcpy(&seg, (data + offset), sizeof(struct dysymtab_command));
	printf("ilocalsym: %d,\nnlocalsym: %d,\niextdefsym: %d,\nnextdefsym: %d,\niundefsym: %d,\nnundefsym: %d,\ntocoff: %d,\nntoc: %d,\nmodtaboff: %d,\nnmodtab: %d,\nextrefsymoff: %d,\nnextrefsyms: %d,\nindirectsymoff: %d,\nnindirectsyms: %d,\nextreloff: %d,\nnextrel: %d,\nlocreloff: %d,\nnlocrel: %d\n\n",
		   seg.ilocalsym, seg.nlocalsym,seg.iextdefsym,seg.nextdefsym,seg.iundefsym,seg.nundefsym,seg.tocoff,seg.ntoc,seg.modtaboff,seg.nmodtab,seg.extrefsymoff,seg.nextrefsyms,seg.indirectsymoff,seg.nindirectsyms,seg.extreloff,seg.nextrel,seg.locreloff,seg.nlocrel);
	print_bytes(&seg, sizeof(struct dysymtab_command));
}

void ft_lc_symtab(void * data, int offset){
	struct symtab_command		seg;
	struct nlist_64				nls;
	uint32_t					i;
	size_t						strsize;
	int 						strarroff;
	int 						nlsoff;

	strarroff = 0;
	nlsoff = 0;
	printf("offset: %d\n", offset);
	memcpy(&seg, (data + offset), sizeof(struct symtab_command));
	printf("nsyms: %d,\nstroff: %d,\nstrsize: %d,\nsymoff: %d\n", seg.nsyms, seg.stroff, seg.strsize, seg.symoff);
	i = 0;
	print_bytes((data + seg.stroff + strarroff), seg.strsize);
	while (*((char*)(data + seg.stroff + strarroff)) == '\0')
		strarroff++;
	while (i < seg.nsyms)
	{
		memcpy(&nls, (data + seg.symoff + nlsoff), sizeof(struct nlist_64));
		printf("n_typ: ");
		print_bytes(&nls.n_type, sizeof(nls.n_type));
		strsize = strlen(data + seg.stroff + strarroff);
		printf("sym: %s, strlen: %zu\n", (char *) (data + seg.stroff + strarroff), strsize);
		print_bytes(&nls, sizeof(nls));
		strarroff += strsize + 1;
		nlsoff += sizeof(struct nlist_64);
		i++;
	}
	print_bytes(&seg, sizeof(struct dysymtab_command));

}

void ft_read_mach_64(void *data){
	struct load_command			load_header;
	struct mach_header_64		header;
	uint32_t					i;
	int							offset;
	int							is_big_end;

	printf("size of vm_prot_t: %lu\nsize of segment header: %lu\n", sizeof(vm_prot_t), sizeof(struct segment_command_64));

	memcpy(&header, data, MACH_64_HEADER_SIZE);
	if (header.magic == MACH_CIGAM_64)
		is_big_end = TRUE;
	else
		is_big_end = FALSE;
	print_bytes(&header.magic, sizeof(header.magic));
	printf("num comd %d\n", header.ncmds);
	print_bytes(&header, sizeof(header));
	if (is_big_end == TRUE)
		puts("is big end in");
	i = 0;
	offset = sizeof(header);
	while (i < header.ncmds)
	{
		memcpy(&load_header, (data + offset), sizeof(struct load_command));
		printf("load cmd: %u\t load size: %u\n", load_header.cmd, load_header.cmdsize);
		print_bytes(&load_header, sizeof(load_header));
		if (load_header.cmd == 0x02)
			ft_lc_symtab(data, offset);
		if (load_header.cmd == 0x0b)
			ft_lc_dysymtab(data, offset);
		if (load_header.cmd == 0x19)
			ft_lc_segment(data, offset);
		offset += load_header.cmdsize;
		i++;
	}
}