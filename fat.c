//
// Created by Robert JONES on 2017/06/29.
//

#include "Includes/nm-otool.h"
#include "Includes/fat.h"
#include "Includes/mach_64.h"
#include "Includes/mach_32.h"

void ft_get_fat_arch(void *data, t_filegroup *gfile, int i, int offset)
{
	t_fat_arch	arch;
	uint32_t 	magic;
	int 		big_end;

	magic = get_magic(data);
	if (magic == FAT_CIGAM)
		big_end = FALSE;
	else
		big_end = TRUE;
	memcpy(&arch, data + offset, sizeof(t_fat_arch));
	if (big_end == FALSE)
		ft_revirce_fat_arch(&arch);
	magic = get_magic(data + arch.offset);
	if (magic == MACH_MAGIC_64 || magic == MACH_CIGAM_64)
		ft_read_mach_64(data + arch.offset, &gfile->ofiles[i]);
	else if (magic == MACH_MAGIC_32 || magic == MACH_CIGAM_32)
		ft_read_mach_32(data + arch.offset, &gfile->ofiles[i]);
	else
		puts("unknown file");
}

void ft_read_fat(void *data, t_filegroup *gfile)
{
	t_fat_header	fat_head;
	int 			offset;
	int 			i;

	offset = sizeof(t_fat_header);
	i = -1;
	memcpy(&fat_head, data, sizeof(t_fat_header));
	if (fat_head.magic == FAT_CIGAM)
		ft_revirce_fat_header(&fat_head);
	if (!(gfile->ofiles = malloc(fat_head.nfat_arch * sizeof(t_ofile))))
		return ;
	gfile->num_ofiles = fat_head.nfat_arch;
	while (++i < gfile->num_ofiles)
	{
		ft_get_fat_arch(data, gfile, i, offset);
		offset += sizeof(t_fat_arch);
	}
}