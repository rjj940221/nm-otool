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

typedef struct	s_sym_tab
{
	char		*symname;
	char 		symbol;
	uint64_t	ofset;
}				t_sym_tab;

typedef struct 	s_ofile{
	void		*text_sections;
	uint64_t	text_section_size;
	//void		*ptr_lc_segment;
	//void		*ptr_lc_symtab;
	//void 		*ptr_lc_dysymtab;
	int			lc_segment;
	//int			lc_symtab;
	//int 		lc_dysymtab;
	t_sym_tab	*sym_tab;
	int 		num_sym;
	uint8_t 	is_big_end;
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

void ft_extract_file(void *data, t_ofile *ofile);
void ft_read_mach(void *data);
void ft_read_mach_64(void *data, t_ofile *ofile);
#endif
