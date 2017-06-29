//
// Created by Robert JONES on 2017/06/29.
//

#ifndef NM_OTOOL_FAT_H
#define NM_OTOOL_FAT_H

#include <stdint.h>
#include <mach/machine.h>
#include "nm-otool.h"

# define FAT_MAGIC  		0xcafebabe
# define FAT_CIGAM  		0xbebafeca

typedef struct	s_fat_header
{
	uint32_t	magic;		/* FAT_MAGIC */
	uint32_t	nfat_arch;	/* number of structs that follow */
}				t_fat_header;

typedef struct	s_fat_arch
{
	cpu_type_t		cputype;	/* cpu specifier (int) */
	cpu_subtype_t	cpusubtype;	/* machine specifier (int) */
	uint32_t		offset;		/* file offset to this object file */
	uint32_t		size;		/* size of this object file */
	uint32_t		align;		/* alignment as a power of 2 */
}				t_fat_arch;

void ft_read_fat(void *data, t_filegroup *gfile);
void ft_revirce_fat_header(t_fat_header *heder);
void ft_revirce_fat_arch(t_fat_arch *arch);
#endif //NM_OTOOL_FAT_H
