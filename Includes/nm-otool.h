//
// Created by Robert JONES on 2017/06/20.
//

#ifndef NM_OTOOL_H
#define NM_OTOOL_H

#include <stdint.h>
#include <ntsid.h>
#include <memory.h>
#include <stdio.h>
#include <mach/machine.h>
#include <mach/vm_prot.h>
#include "mach.h"
#include "mach_64.h"


# define TRUE       		1
# define FALSE				0
# define FAT_MAGIC  		0xcafebabe
# define FAT_CIGAM  		0xbebafeca
# define ELF_MAGIC  		0x7f454c46

typedef struct 	s_ofile{
	int lc_segment;
	int lc_symtab;
	int lc_dysymtab;
}				t_ofile;

struct section
{
	char sectname[16];
	char segname[16];
	unsigned long addr;
	unsigned long size;
	unsigned long offset;
	unsigned long align;
	unsigned long reloff;
	unsigned long nreloc;
	unsigned long flags;
	unsigned long reserved1;
	unsigned long reserved2;
};

void print_bytes(const void *object, size_t size);

void ft_extract_file(void *data);
void ft_read_mach(void *data);
void ft_read_mach_64(void *data);
#endif
