//
// Created by Robert JONES on 2017/06/20.
//

#ifndef MACH_64_H
#define MACH_64_H

#include <stdint.h>
#include <mach/machine.h>
#include <mach/vm_prot.h>

# define MACH_MAGIC_64			0xfeedfacf
# define MACH_CIGAM_64			0xcffaedfe
# define MACH_64_HEADER_SIZE	32

struct load_command
{
	uint32_t cmd;
	uint32_t cmdsize;
};

struct nlist_64 {
	union {
		uint32_t  n_strx; /* index into the string table */
	} n_un;
	uint8_t n_type;        /* type flag, see below */
	uint8_t n_sect;        /* section number or NO_SECT */
	uint16_t n_desc;       /* see <mach-o/stab.h> */
	uint64_t n_value;      /* value of this symbol (or stab offset) */
};

struct mach_header_64 {
	uint32_t	magic;		/* mach magic number identifier */
	cpu_type_t	cputype;	/* cpu specifier */
	cpu_subtype_t	cpusubtype;	/* machine specifier */
	uint32_t	filetype;	/* type of file */
	uint32_t	ncmds;		/* number of load commands */
	uint32_t	sizeofcmds;	/* the size of all the load commands */
	uint32_t	flags;		/* flags */
	uint32_t	reserved;	/* reserved */
};

struct segment_command_64 { /* for 64-bit architectures */
	uint32_t	cmd;		/* LC_SEGMENT_64 */
	uint32_t	cmdsize;	/* includes sizeof section_64 structs */
	char		segname[16];	/* segment name */
	uint64_t	vmaddr;		/* memory address of this segment */
	uint64_t	vmsize;		/* memory size of this segment */
	uint64_t	fileoff;	/* file offset of this segment */
	uint64_t	filesize;	/* amount to map from the file */
	vm_prot_t	maxprot;	/* maximum VM protection */
	vm_prot_t	initprot;	/* initial VM protection */
	uint32_t	nsects;		/* number of sections in segment */
	uint32_t	flags;		/* flags */
};

struct section_64 { /* for 64-bit architectures */
	char		sectname[16];	/* name of this section */
	char		segname[16];	/* segment this section goes in */
	uint64_t	addr;		/* memory address of this section */
	uint64_t	size;		/* size in bytes of this section */
	uint32_t	offset;		/* file offset of this section */
	uint32_t	align;		/* section alignment (power of 2) */
	uint32_t	reloff;		/* file offset of relocation entries */
	uint32_t	nreloc;		/* number of relocation entries */
	uint32_t	flags;		/* flags (section type and attributes)*/
	uint32_t	reserved1;	/* reserved (for offset or index) */
	uint32_t	reserved2;	/* reserved (for count or sizeof) */
	uint32_t	reserved3;	/* reserved */
};

struct symtab_command {
	uint32_t	cmd;		/* LC_SYMTAB */
	uint32_t	cmdsize;	/* sizeof(struct symtab_command) */
	uint32_t	symoff;		/* symbol table offset */
	uint32_t	nsyms;		/* number of symbol table entries */
	uint32_t	stroff;		/* string table offset */
	uint32_t	strsize;	/* string table size in bytes */
};

struct dysymtab_command {
	uint32_t	cmd;			/* LC_DYSYMTAB */
	uint32_t	cmdsize;		/* sizeof(struct dysymtab_command) */
	uint32_t	ilocalsym;		/* index to local symbols */
	uint32_t	nlocalsym;		/* number of local symbols */
	uint32_t	iextdefsym;		/* index to externally defined symbols */
	uint32_t	nextdefsym;		/* number of externally defined symbols */
	uint32_t	iundefsym;		/* index to undefined symbols */
	uint32_t	nundefsym;		/* number of undefined symbols */
	uint32_t	tocoff;			/* file offset to table of contents */
	uint32_t	ntoc;			/* number of entries in table of contents */
	uint32_t	modtaboff;		/* file offset to module table */
	uint32_t	nmodtab;		/* number of module table entries */
	uint32_t	extrefsymoff;	/* offset to referenced symbol table */
	uint32_t	nextrefsyms;	/* number of referenced symbol table entries */
	uint32_t	indirectsymoff; /* file offset to the indirect symbol table */
	uint32_t	nindirectsyms;  /* number of indirect symbol table entries */
	uint32_t	extreloff;		/* offset to external relocation entries */
	uint32_t	nextrel;		/* number of external relocation entries */
	uint32_t	locreloff;		/* offset to local relocation entries */
	uint32_t	nlocrel;		/* number of local relocation entries */

};
#endif