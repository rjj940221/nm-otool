//
// Created by rojones on 2017/06/28.
//

#ifndef NM_OTOOL_MACH_H
#define NM_OTOOL_MACH_H

#define FAT_MAGIC	0xcafebabe
#define FAT_CIGAM	0xbebafeca
#define	LC_SYMTAB	0x2

#include <stdint.h>
#include "nm-otool.h"

typedef struct  s_load_command
{
	uint32_t cmd;
	uint32_t cmdsize;
}               t_ld_cmd;

typedef struct  s_symtab_command
{
	uint32_t	cmd;		/* LC_SYMTAB */
	uint32_t	cmdsize;	/* sizeof(struct s_symtab_command) */
	uint32_t	symoff;		/* symbol table offset */
	uint32_t	nsyms;		/* number of symbol table entries */
	uint32_t	stroff;		/* string table offset */
	uint32_t	strsize;	/* string table size in bytes */
}               t_symtab_cmd;

typedef struct	s_dysymtab_command
{
	uint32_t	cmd;	/* LC_DYSYMTAB */
	uint32_t	cmdsize;	/* sizeof(struct dysymtab_command) */
	uint32_t	ilocalsym;	/* index to local symbols */
	uint32_t	nlocalsym;	/* number of local symbols */
	uint32_t	iextdefsym;/* index to externally defined symbols */
	uint32_t	nextdefsym;/* number of externally defined symbols */
	uint32_t	iundefsym;	/* index to undefined symbols */
	uint32_t	nundefsym;	/* number of undefined symbols */
	uint32_t	tocoff;	/* file offset to table of contents */
	uint32_t	ntoc;	/* number of entries in table of contents */
	uint32_t	modtaboff;	/* file offset to module table */
	uint32_t	nmodtab;	/* number of module table entries */
	uint32_t	extrefsymoff;	/* offset to referenced symbol table */
	uint32_t	nextrefsyms;	/* number of referenced symbol table entries */
	uint32_t	indirectsymoff; /* file offset to the indirect symbol table */
	uint32_t	nindirectsyms;  /* number of indirect symbol table entries */
	uint32_t	extreloff;	/* offset to external relocation entries */
	uint32_t	nextrel;	/* number of external relocation entries */
	uint32_t	locreloff;	/* offset to local relocation entries */
	uint32_t	nlocrel;	/* number of local relocation entries */
}				t_dysymtab_cmd;

void	revirce_bytes(void *data, size_t size);
void	ft_revirce_symtab(t_symtab_cmd *symtab);
void	ft_revirce_ld_cmd(t_ld_cmd *symtab);


#endif //NM_OTOOL_MACH_H
