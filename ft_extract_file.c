/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 06:58:40 by rojones           #+#    #+#             */
/*   Updated: 2017/06/30 07:57:32 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/nm_otool.h"
#include "Includes/mach_32.h"
#include "Includes/mach_64.h"
#include "Includes/fat.h"

void		ft_print_line_byts(void *data, size_t size)
{
	unsigned char	*bytes;
	int				i;

	bytes = (unsigned char *)(data);
	i = -1;
	printf("%016x ", 0);
	while (++i < (int)size)
	{
		printf("%02x ", bytes[i]);
		if ((i + 1) % 16 == 0 && (i + 1) < (int)size)
		{
			putchar('\n');
			printf("%016x ", i);
		}
	}
	putchar('\n');
}

uint32_t	get_magic(void *data)
{
	uint32_t	magic;

	memcpy(&magic, data, sizeof(uint32_t));
	return (magic);
}

void		*get_file_data(char *file, size_t *size)
{
	int			fd;
	struct stat	buf;
	void		*data;

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if (fstat(fd, &buf) == -1)
			puts("Could not get file propertys.\n");
		else
		{
			*size = (size_t)buf.st_size;
			if ((data = mmap(0, (size_t)buf.st_size,
				PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
				puts("Could not read file.\n");
			else
				return (data);
		}
		close(fd);
	}
	else
		printf("%s: does not exist", file);
	return (NULL);
}

void		ft_setgfile(t_filegroup *gfile)
{
	if ((gfile->ofiles = malloc(sizeof(t_ofile))) == NULL)
		return ;
	gfile->num_ofiles = 1;
}

void		ft_extract_file(void *data, t_filegroup *gfile)
{
	uint32_t magic;

	magic = get_magic(data);
	if (magic == FAT_CIGAM || magic == FAT_MAGIC)
		ft_read_fat(data, gfile);
	else if (magic == MACH_CIGAM_32 || magic == MACH_MAGIC_32 ||
			magic == MACH_CIGAM_64 || magic == MACH_MAGIC_64)
	{
		ft_setgfile(gfile);
		if (gfile->ofiles == NULL)
			return ;
		if (magic == MACH_CIGAM_32 || magic == MACH_MAGIC_32)
			ft_read_mach_32(data, gfile->ofiles);
		else
			ft_read_mach_64(data, gfile->ofiles);
	}
	else
		puts("unkowen file type");
}
