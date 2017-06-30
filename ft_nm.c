/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 07:00:46 by rojones           #+#    #+#             */
/*   Updated: 2017/06/30 07:51:18 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "Includes/nm_otool.h"

void	ft_printnm(t_filegroup *gfile)
{
	int	i;
	int	j;

	j = -1;
	while (++j < gfile->num_ofiles)
	{
		i = -1;
		while (++i < gfile->ofiles[j].num_sym)
		{
			if (gfile->ofiles[j].sym_tab[i].symbol == 'u' ||
					gfile->ofiles[j].sym_tab[i].symbol == 'U')
				printf("                 %c %s\n", gfile->ofiles[j].sym_tab[i].
						symbol, gfile->ofiles[j].sym_tab[i].symname);
			else
				printf("%016x %c %s\n", (unsigned int)gfile->ofiles[j].
						sym_tab[i].ofset, gfile->ofiles[j].sym_tab[i].symbol,
						gfile->ofiles[j].sym_tab[i].symname);
		}
	}
}

void	ft_nm_archive_print(void *data, char *archive, char *file)
{
	t_filegroup	gfile;

	gfile = (t_filegroup){0, NULL};
	ft_extract_file(data, &gfile);
	printf("%s(%s):\n", archive, file);
	ft_printnm(&gfile);
}

void	ft_nm_archive(char *archive, void *data, size_t size)
{
	size_t		offset;
	t_ar_header	header;
	char		*file;
	int			file_name_size;

	offset = 8;
	while (offset < size)
	{
		file_name_size = 0;
		memcpy(&header, data + offset, sizeof(header));
		offset += sizeof(header);
		if (strncmp(header.file_id, "#1/", 3) == 0)
		{
			file_name_size = atoi(header.file_id + 3);
			file = ft_strtrim(data + offset);
			offset += file_name_size;
		}
		else
			file = ft_strtrim(header.file_id);
		if (strcmp(file, "__.SYMDEF SORTED"))
			ft_nm_archive_print(data + offset, archive, file);
		free(file);
		offset += (atoi(header.size) - file_name_size);
	}
}

void	ft_nm(char *file, int print_file)
{
	void		*data;
	t_filegroup	gfile;
	size_t		size;

	if ((data = get_file_data(file, &size)) != NULL)
	{
		if (strncmp(data, "!<arch>", 7) == 0)
			ft_nm_archive(file, data, size);
		else
		{
			ft_extract_file(data, &gfile);
			if (print_file != 0)
				printf("%s:\n", file);
			ft_printnm(&gfile);
		}
	}
}

int		main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		ft_nm("a.out", 0);
	else
	{
		i = 0;
		while (++i < ac)
			ft_nm(av[i], ac - 1);
	}
}
