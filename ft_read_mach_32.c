/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_mach_32.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 07:13:10 by rojones           #+#    #+#             */
/*   Updated: 2017/06/30 08:22:01 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/mach_32.h"

void	ft_lc_segment_32(void *data, int offset, t_ofile *ofile)
{
	t_seg_cmd_32	seg;
	t_section_32	section;
	uint32_t		i;

	i = 0;
	memcpy(&seg, (data + offset), sizeof(struct s_segment_command_32));
	if (ofile->is_big_end == FALSE)
		ft_revirce_segment_32(&seg);
	offset += sizeof(struct s_segment_command_32);
	while (i < seg.nsects)
	{
		memcpy(&section, (data + offset), sizeof(struct s_section_32));
		if (ofile->is_big_end == FALSE)
			ft_revirce_section_32(&section);
		if (strcmp(section.sectname, "__text") == 0 &&
			strcmp(section.segname, "__TEXT") == 0)
		{
			ofile->text_sections = (data + offset);
			ofile->text_section_size = section.size;
		}
		offset += sizeof(struct s_section_32);
		i++;
	}
}

void	ft_get_sct_sym_32(void *dt, t_ofile *of, t_nlist_32 *nls, uint32_t i)
{
	t_section_32	section;

	memcpy(&section, (dt + ft_get_section_offset_32(dt,
					of->is_big_end, nls)), sizeof(t_section_32));
	if (of->is_big_end == FALSE)
		ft_revirce_section_32(&section);
	if (strcmp(section.sectname, "__text") == 0)
		of->sym_tab[i].symbol = 't';
	else if (strcmp(section.sectname, "__data") == 0)
		of->sym_tab[i].symbol = 'd';
	else if (strcmp(section.sectname, "__bss") == 0)
		of->sym_tab[i].symbol = 'b';
	else if (strcmp(section.sectname, "__common") == 0)
		of->sym_tab[i].symbol = 'c';
	else
		of->sym_tab[i].symbol = 's';
	if (strcmp(section.sectname, "__picsymbol_stub") == 0 ||
			strcmp(section.sectname, "__symbol_stub") == 0)
		of->sym_tab[i].symbol = 'i';
}

void	ft_unmask_ntype_32(t_nlist_32 *nls, t_ofile *of, uint32_t i, void *dt)
{
	int				tmp;

	tmp = (nls->n_type & 0x0e);
	if (tmp == 0x0e && nls->n_sect - 1 >= 0)
		ft_get_sct_sym_32(dt, of, nls, i);
	if (tmp == 0x02)
		of->sym_tab[i].symbol = 'a';
	if (tmp == 0x00)
		of->sym_tab[i].symbol = 'u';
	tmp = (nls->n_type & 0x01);
	if (tmp == 1)
		of->sym_tab[i].symbol = (char)toupper(of->sym_tab[i].symbol);
}

void	ft_lc_symtab_32(void *data, int offset, t_ofile *ofile)
{
	t_symtab_cmd	symtab;
	t_nlist_32		nls;
	uint32_t		i;
	int				nlsoff;

	nlsoff = 0;
	memcpy(&symtab, (data + offset), sizeof(struct s_symtab_command));
	if (ofile->is_big_end == FALSE)
		ft_revirce_symtab(&symtab);
	i = 0;
	if ((ofile->sym_tab = malloc(sizeof(t_sym_tab) * symtab.nsyms)) == NULL)
		return ;
	ofile->num_sym = symtab.nsyms;
	while (i < symtab.nsyms)
	{
		memcpy(&nls, (data + symtab.symoff + nlsoff), sizeof(t_nlist_32));
		if (ofile->is_big_end == FALSE)
			ft_revirce_nlist_32(&nls);
		ft_unmask_ntype_32(&nls, ofile, i, data);
		ofile->sym_tab[i].ofset = nls.n_value;
		ofile->sym_tab[i].symname = (char *)
			(data + symtab.stroff + nls.n_un.n_strx);
		nlsoff += sizeof(t_nlist_32);
		i++;
	}
}

void	ft_read_mach_32(void *data, t_ofile *ofile)
{
	t_ld_cmd	load_header;
	t_mach_32	header;
	uint32_t	i;
	int			offset;

	memcpy(&header, data, MACH_32_HEADER_SIZE);
	if (header.magic == MACH_MAGIC_32)
		ofile->is_big_end = TRUE;
	if (ofile->is_big_end == FALSE)
		ft_revirce_mach_heder_32(&header);
	i = 0;
	offset = sizeof(header);
	while (i < header.ncmds)
	{
		memcpy(&load_header, (data + offset), sizeof(t_ld_cmd));
		if (ofile->is_big_end == FALSE)
			ft_revirce_ld_cmd(&load_header);
		if (load_header.cmd == LC_SYMTAB)
			ft_lc_symtab_32(data, offset, ofile);
		if (load_header.cmd == 0x19)
			ft_lc_segment_32(data, offset, ofile);
		offset += load_header.cmdsize;
		i++;
	}
}
