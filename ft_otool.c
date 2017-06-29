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

void ft_printotool(t_filegroup *gfile){
	int	i;

	i = -1;
	while (++i < gfile->num_ofiles)
	{
		//printf("%s:\n", file);
		printf("(__Text, __text) section\n");
		ft_print_line_byts(gfile[i].ofiles->text_sections, gfile[i].ofiles->text_section_size);
	}
}

void ft_otool_archive_print(void *data,  char *archive, char *file){
	t_filegroup	gfile;

	gfile = (t_filegroup){0, NULL};
	ft_extract_file(data, &gfile);
	printf("%s(%s):\n",archive, file);
	ft_printotool(&gfile);
}

void ft_otool_archive(char *archive, void *data, size_t size){
	size_t      offset;
	t_ar_header header;
	char        *file;
	int         file_name_size;

	offset = 8;
	printf("Archive : %s\n", archive);
	while (offset < size)
	{
		file_name_size = 0;
		memcpy(&header, data + offset, sizeof(header));
		offset += sizeof(header);
		if (strncmp(header.file_id, "#1/", 3) == 0)
		{
			file_name_size = atoi(header.file_id+ 3);
			file = ft_strtrim(data + offset);
			offset += file_name_size;
		}
		else
			file = ft_strtrim(header.file_id);
		if (strcmp(file, "__.SYMDEF SORTED"))
			ft_otool_archive_print(data + offset, archive, file);
		free(file);
		offset += (atoi(header.size) - file_name_size);
	}
}

void ft_otool(char *file){
	void    	*data;
	t_filegroup	gfile;
	size_t  	size;

	if((data = get_file_data(file, &size)) != NULL)
	{
		if (strncmp(data, "!<arch>", 7) == 0)
			ft_otool_archive(file, data, size);
		else
		{
			ft_extract_file(data, &gfile);
			printf("%s:\n", file);
			ft_printotool(&gfile);
		}
	}
}

int main (int ac, char **av){
	int	i;

	if (ac == 1)
		ft_otool("a.out");
	else
	{
		i = 0;
		while (++i < ac)
			ft_otool(av[i]);
	}
}
