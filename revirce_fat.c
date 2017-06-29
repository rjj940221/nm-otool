//
// Created by Robert JONES on 2017/06/29.
//

#include "Includes/fat.h"

void ft_revirce_fat_header(t_fat_header *heder)
{
	revirce_bytes(&heder->nfat_arch, sizeof(uint32_t));
}

void ft_revirce_fat_arch(t_fat_arch *arch)
{
	revirce_bytes(&arch->cputype, sizeof(cpu_type_t));
	revirce_bytes(&arch->cpusubtype, sizeof(cpu_subtype_t));
	revirce_bytes(&arch->offset, sizeof(uint32_t));
	revirce_bytes(&arch->size, sizeof(uint32_t));
	revirce_bytes(&arch->align, sizeof(uint32_t));
}