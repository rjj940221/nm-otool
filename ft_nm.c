#include "libft/libft.h"
#include "Includes/nm-otool.h"
#include <sys/mman.h>

void ft_nm(char *file)
{
	int fd;
	struct stat buf;
	void *data;

	
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if (fstat(fd, &buf) == -1 || buf.st_size == 0)
			puts("Could not get file propertys.\n");
		else
		{
			if ((data = mmap(0, (size_t)buf.st_size, PROT_READ, MAP_SHARED, fd, 0))
				== MAP_FAILED)
			{
				puts("Could not read file.\n");
			}
			else {
				//ft_offset(data, (size_t)buf.st_size);
				//ft_process(data, (size_t)buf.st_size);
				ft_extract_file(data);
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
