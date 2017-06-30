/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:56:46 by rojones           #+#    #+#             */
/*   Updated: 2017/06/30 08:57:43 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_FAT_H
# define NM_OTOOL_FAT_H

# include <stdint.h>
# include <mach/machine.h>
# include "nm_otool.h"

# define FAT_MAGIC			0xcafebabe
# define FAT_CIGAM			0xbebafeca

typedef struct	s_fat_header
{
	uint32_t	magic;
	uint32_t	nfat_arch;
}				t_fat_header;

typedef struct	s_fat_arch
{
	cpu_type_t		cputype;
	cpu_subtype_t	cpusubtype;
	uint32_t		offset;
	uint32_t		size;
	uint32_t		align;
}				t_fat_arch;

void			ft_read_fat(void *data, t_filegroup *gfile);
void			ft_revirce_fat_header(t_fat_header *heder);
void			ft_revirce_fat_arch(t_fat_arch *arch);
#endif
