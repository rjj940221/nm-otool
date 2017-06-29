//
// Created by Robert JONES on 2017/06/20.
//

#ifndef MACH_H
#define MACH_H

#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <mach/machine.h>
#include "mach.h"
#include "nm-otool.h"

# define MACH_MAGIC_32 		0xfeedface
# define MACH_CIGAM_32 		0xcefaedfe
# define MACH_32_HEADER_SIZE	28

typedef struct s_nlist_32 {
	union {
		uint32_t  n_strx; /* index into the string table */
	} n_un;
	uint8_t n_type;        /* type flag, see below */
	uint8_t n_sect;        /* section number or NO_SECT */
	uint16_t n_desc;       /* see <mach-o/stab.h> */
	uint32_t n_value;      /* value of this symbol (or stab offset) */
}               t_nlist_32;

typedef struct s_mach_header_32 {
	uint32_t	magic;		/* mach magic number identifier */
	cpu_type_t	cputype;	/* cpu specifier */
	cpu_subtype_t	cpusubtype;	/* machine specifier */
	uint32_t	filetype;	/* type of file */
	uint32_t	ncmds;		/* number of load commands */
	uint32_t	sizeofcmds;	/* the size of all the load commands */
	uint32_t	flags;		/* flags */
}               t_mach_32;

typedef struct s_segment_command_32 { /* for 32-bit architectures */
	uint32_t	cmd;		/* LC_SEGMENT */
	uint32_t	cmdsize;	/* includes sizeof section structs */
	char		segname[16];	/* segment name */
	uint32_t	vmaddr;		/* memory address of this segment */
	uint32_t	vmsize;		/* memory size of this segment */
	uint32_t	fileoff;	/* file offset of this segment */
	uint32_t	filesize;	/* amount to map from the file */
	vm_prot_t	maxprot;	/* maximum VM protection */
	vm_prot_t	initprot;	/* initial VM protection */
	uint32_t	nsects;		/* number of sections in segment */
	uint32_t	flags;
}               t_seg_cmd_32;

typedef struct  s_section_32 { /* for 64-bit architectures */
	char		sectname[16];	/* name of this section */
	char		segname[16];	/* segment this section goes in */
	uint32_t	addr;		/* memory address of this section */
	uint32_t	size;		/* size in bytes of this section */
	uint32_t	offset;		/* file offset of this section */
	uint32_t	align;		/* section alignment (power of 2) */
	uint32_t	reloff;		/* file offset of relocation entries */
	uint32_t	nreloc;		/* number of relocation entries */
	uint32_t	flags;		/* flags (section type and attributes)*/
	uint32_t	reserved1;	/* reserved (for offset or index) */
	uint32_t	reserved2;
}               t_section_32;

void    ft_revirce_nlist_32(t_nlist_32 *nls);
void    ft_revirce_mach_heder_32(t_mach_32 *header);
void    ft_revirce_segment_32(t_seg_cmd_32 *seg);
void    ft_revirce_section_32(t_section_32 *sec);
int		ft_get_section_offset_32(void *data, int is_big_end, t_nlist_32 *nls);
#endif
