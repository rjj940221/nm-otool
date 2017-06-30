/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_32.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 09:04:22 by rojones           #+#    #+#             */
/*   Updated: 2017/06/30 10:03:12 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACH_32_H
# define MACH_32_H

# include <stdlib.h>
# include <ctype.h>
# include <stdint.h>
# include <mach/machine.h>
# include "mach.h"
# include "nm_otool.h"

# define MACH_MAGIC_32		0xfeedface
# define MACH_CIGAM_32		0xcefaedfe
# define MACH_32_HEADER_SIZE	28

typedef struct		s_nlist_32
{
	union
	{
		uint32_t	n_strx;
	}				n_un;
	uint8_t			n_type;
	uint8_t			n_sect;
	uint16_t		n_desc;
	uint32_t		n_value;
}					t_nlist_32;

typedef struct		s_mach_header_32
{
	uint32_t		magic;
	cpu_type_t		cputype;
	cpu_subtype_t	cpusubtype;
	uint32_t		filetype;
	uint32_t		ncmds;
	uint32_t		sizeofcmds;
	uint32_t		flags;
}					t_mach_32;

typedef struct		s_segment_command_32
{
	uint32_t		cmd;
	uint32_t		cmdsize;
	char			segname[16];
	uint32_t		vmaddr;
	uint32_t		vmsize;
	uint32_t		fileoff;
	uint32_t		filesize;
	vm_prot_t		maxprot;
	vm_prot_t		initprot;
	uint32_t		nsects;
	uint32_t		flags;
}					t_seg_cmd_32;

typedef struct		s_section_32
{
	char			sectname[16];
	char			segname[16];
	uint32_t		addr;
	uint32_t		size;
	uint32_t		offset;
	uint32_t		align;
	uint32_t		reloff;
	uint32_t		nreloc;
	uint32_t		flags;
	uint32_t		reserved1;
	uint32_t		reserved2;
}					t_section_32;

void				ft_revirce_nlist_32(t_nlist_32 *nls);
void				ft_revirce_mach_heder_32(t_mach_32 *header);
void				ft_revirce_segment_32(t_seg_cmd_32 *seg);
void				ft_revirce_section_32(t_section_32 *sec);
int					ft_get_section_offset_32(void *data, int is_big_end,
					t_nlist_32 *nls);
#endif
