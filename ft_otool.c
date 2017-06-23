//
// Created by Robert JONES on 2017/06/23.
//
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include "Includes/nm-otool.h"

void ft_print_line_byts(void *data, size_t size){
	unsigned char *bytes;
	int i;

	bytes = (unsigned char *)(data);
	i = -1;
	printf("%016x ", 0);
	while( ++i < (int)size)
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

void ft_printotool(char *file, t_ofile *ofile){
	printf("%s:\n", file);
	printf("(__Text, __text) section\n");
	ft_print_line_byts(ofile->text_sections, ofile->text_section_size);
}

void ft_nm(char *file)
{
	int			fd;
	struct stat	buf;
	void		*data;
	t_ofile		ofile;

	ofile = (t_ofile){NULL, 0, -1, NULL, 0, FALSE};
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if (fstat(fd, &buf) == -1 || buf.st_size == 0)
			puts("Could not get file propertys.\n");
		else
		{
			if ((data = mmap(0, (size_t)buf.st_size, PROT_READ, MAP_SHARED, fd, 0))
				== MAP_FAILED)
				puts("Could not read file.\n");
			else
			{
				ft_extract_file(data, &ofile);
				ft_printotool(file, &ofile);
			}
		}
		close(fd);
	}
	else
		printf("nm: '%s': No such file", file);
}

int main (int ac, char **av){
	int	i;

	if (ac == 1)
		ft_nm("a.out");
	else
	{
		i = 0;
		while (++i < ac)
			ft_nm(av[i]);
	}
}