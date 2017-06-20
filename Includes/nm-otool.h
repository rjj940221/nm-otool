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



struct s_file_info{
	uint8_t big_endin;
	uint32_t num_comands;
};

void print_bytes(const void *object, size_t size);

void ft_extract_file(void *data);
void ft_read_mach(void *data);
void ft_read_mach_64(void *data);
#endif
