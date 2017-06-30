/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_64.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:38:21 by rojones           #+#    #+#             */
/*   Updated: 2017/06/30 09:03:57 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACH_64_H
# define MACH_64_H

# include <stdint.h>
# include <mach/machine.h>
# include <mach/vm_prot.h>
# include "mach.h"

# define MACH_MAGIC_64			0xfeedfacf
# define MACH_CIGAM_64			0xcffaedfe
# define MACH_64_HEADER_SIZE	32

typedef struct		s_nlist_64
{
	union
	{
		uint32_t	n_strx;
	}				n_un;
	uint8_t			n_type;
	uint8_t			n_sect;
	uint16_t		n_desc;
	uint64_t		n_value;
}					t_nlist_64;

typedef struct		s_mach_header_64
{
	uint32_t		magic;
	cpu_type_t		cputype;
	cpu_subtype_t	cpusubtype;
	uint32_t		filetype;
	uint32_t		ncmds;
	uint32_t		sizeofcmds;
	uint32_t		flags;
	uint32_t		reserved;
}					t_mach_64;

typedef struct		s_segment_command_64
{
	uint32_t		cmd;
	uint32_t		cmdsize;
	char			segname[16];
	uint64_t		vmaddr;
	uint64_t		vmsize;
	uint64_t		fileoff;
	uint64_t		filesize;
	vm_prot_t		maxprot;
	vm_prot_t		initprot;
	uint32_t		nsects;
	uint32_t		flags;
}					t_seg_cmd_64;

typedef struct		s_section_64
{
	char			sectname[16];
	char			segname[16];
	uint64_t		addr;
	uint64_t		size;
	uint32_t		offset;
	uint32_t		align;
	uint32_t		reloff;
	uint32_t		nreloc;
	uint32_t		flags;
	uint32_t		reserved1;
	uint32_t		reserved2;
	uint32_t		reserved3;
}					t_section_64;

void				ft_revirce_nlist_64(t_nlist_64 *nls);
void				ft_revirce_mach_heder_64(t_mach_64 *header);
void				ft_revirce_segment_64(t_seg_cmd_64 *seg);
void				ft_revirce_section_64(t_section_64 *sec);
void				ft_revirce_symtab(t_symtab_cmd *symtab);
int					ft_get_section_offset_64(void *data,
						int is_big_end, t_nlist_64 *nls);

#endif
