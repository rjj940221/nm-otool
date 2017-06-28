#include "libft/libft.h"
#include "Includes/nm-otool.h"
#include <sys/mman.h>

uint32_t get_magic(void *data){
	uint32_t magic;

	memcpy(&magic, data, sizeof(uint32_t));
	return magic;
}

void choose_method(void *data){
	uint32_t magic;
	t_ofile		ofile;

	magic = get_magic(data);
	if (magic == FAT_CIGAM || magic == FAT_MAGIC) {
		puts("fat file");
		return ;
	}
	if (magic == MACH_CIGAM || magic == MACH_MAGIC) {
		puts("mach file");
		//ft_read_mach(data);
		return ;
	}
	if (magic == MACH_CIGAM_64 || magic == MACH_MAGIC_64) {
		ft_read_mach_64(data, &ofile);
		return ;
	}
	if (strncmp(data, "!<arch>", 7) == 0) {
		puts("got archve");
		return ;
	}
	puts("unkowen file type");
}

void ft_printnm(t_ofile *ofile){
	int	i;

	i = -1;
	while (++i < ofile->num_sym)
	{
		if (ofile->sym_tab[i].symbol == 'u' || ofile->sym_tab[i].symbol == 'U')
			printf("\t\t %c %s\n", ofile->sym_tab[i].symbol, ofile->sym_tab[i].symname);
		else
			printf("%016x %c %s\n", (unsigned int) ofile->sym_tab[i].ofset, ofile->sym_tab[i].symbol, ofile->sym_tab[i].symname);
	}
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
				ft_printnm(&ofile);
			}
		}
		close(fd);
	}
	else
		printf("ft_nm: '%s': No such file", file);
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
