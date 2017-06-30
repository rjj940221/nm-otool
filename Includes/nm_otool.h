/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm-otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 07:53:58 by rojones           #+#    #+#             */
/*   Updated: 2017/06/30 08:53:13 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include <sys/stat.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <zconf.h>
# include <stdint.h>
# include <ntsid.h>
# include <memory.h>
# include <stdio.h>
# include <mach/machine.h>
# include <mach/vm_prot.h>
# include "../libft/libft.h"

# define TRUE			1
# define FALSE			0

# define ELF_MAGIC		0x7f454c46

typedef struct	s_sym_tab
{
	char		*symname;
	char		symbol;
	uint64_t	ofset;
}				t_sym_tab;

typedef struct	s_ofile{
	void		*text_sections;
	uint64_t	text_section_size;
	t_sym_tab	*sym_tab;
	int			num_sym;
	uint8_t		is_big_end;
}				t_ofile;

typedef struct	s_filegroup
{
	int		num_ofiles;
	t_ofile	*ofiles;
}				t_filegroup;

typedef struct	s_ar_header{
	char	file_id[16];
	char	file_mod_time[12];
	char	owner_id[6];
	char	group_id[6];
	char	file_mode[8];
	char	size[10];
	char	end[2];
}				t_ar_header;

void			print_bytes(const void *object, size_t size);
void			revirce_bytes(void *data, size_t size);
void			ft_extract_file(void *data, t_filegroup *gfile);
void			ft_read_mach_32(void *data, t_ofile *ofile);
void			ft_read_mach_64(void *data, t_ofile *ofile);
void			*get_file_data(char *file, size_t *size);
uint32_t		get_magic(void *data);
void			ft_print_line_byts(void *data, size_t size);
#endif
