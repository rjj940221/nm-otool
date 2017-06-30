/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:58:25 by rojones           #+#    #+#             */
/*   Updated: 2017/06/30 09:00:26 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_MACH_H
# define NM_OTOOL_MACH_H

# define FAT_MAGIC	0xcafebabe
# define FAT_CIGAM	0xbebafeca
# define LC_SYMTAB	0x2

# include <stdint.h>
# include "nm_otool.h"

typedef struct	s_load_command
{
	uint32_t	cmd;
	uint32_t	cmdsize;
}				t_ld_cmd;

typedef struct	s_symtab_command
{
	uint32_t	cmd;
	uint32_t	cmdsize;
	uint32_t	symoff;
	uint32_t	nsyms;
	uint32_t	stroff;
	uint32_t	strsize;
}				t_symtab_cmd;

typedef struct	s_dysymtab_command
{
	uint32_t	cmd;
	uint32_t	cmdsize;
	uint32_t	ilocalsym;
	uint32_t	nlocalsym;
	uint32_t	iextdefsym;
	uint32_t	nextdefsym;
	uint32_t	iundefsym;
	uint32_t	nundefsym;
	uint32_t	tocoff;
	uint32_t	ntoc;
	uint32_t	modtaboff;
	uint32_t	nmodtab;
	uint32_t	extrefsymoff;
	uint32_t	nextrefsyms;
	uint32_t	indirectsymoff;
	uint32_t	nindirectsyms;
	uint32_t	extreloff;
	uint32_t	nextrel;
	uint32_t	locreloff;
	uint32_t	nlocrel;
}				t_dysymtab_cmd;

void			revirce_bytes(void *data, size_t size);
void			ft_revirce_symtab(t_symtab_cmd *symtab);
void			ft_revirce_ld_cmd(t_ld_cmd *symtab);

#endif
