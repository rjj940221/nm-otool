



#include "Includes/nm-otool.h"
#include "Includes/mach_32.h"
#include "Includes/mach_64.h"
#include "Includes/fat.h"

uint32_t get_magic(void *data)
{
	uint32_t magic;

	memcpy(&magic, data, sizeof(uint32_t));
	return magic;
}

void print_bytes(const void *object, size_t size)
{
	// This is for C++; in C just drop the static_cast<>() and assign.
	const unsigned char * const bytes = (const unsigned char *)(object);
	size_t i;

	for(i = 0; i < size; i++)
	{
		printf("%02x ", bytes[i]);
		if ((i + 1) % 8 == 0)
			putchar(' ');
		if ((i + 1) % 16 == 0)
			putchar('\n');
	}
	putchar('\n');
}



void *get_file_data(char *file, size_t *size)
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
			if ((data = mmap(0, (size_t)buf.st_size, PROT_READ, MAP_SHARED, fd, 0))	== MAP_FAILED)
				puts("Could not read file.\n");
			else
				return data;
		}
		close(fd);
	} else
		printf("%s: does not exist", file);
	return NULL;
}

void ft_setgfile(t_filegroup *gfile)
{
	if ((gfile->ofiles = malloc(sizeof(t_ofile))) == NULL)
		return ;
	gfile->num_ofiles = 1;

}

void ft_extract_file(void *data, t_filegroup *gfile)
{
	uint32_t magic;

	magic = get_magic(data);
	if (magic == FAT_CIGAM || magic == FAT_MAGIC)
		ft_read_fat(data, gfile);
	else if (magic == MACH_CIGAM_32 || magic == MACH_MAGIC_32 || magic == MACH_CIGAM_64 || magic == MACH_MAGIC_64)
	{
		ft_setgfile(gfile);
		if (gfile->ofiles == NULL)
			return;
		if (magic == MACH_CIGAM_32 || magic == MACH_MAGIC_32)
			ft_read_mach_32(data, gfile->ofiles);
		else
			ft_read_mach_64(data, gfile->ofiles);
	}
	else
		puts("unkowen file type");
}