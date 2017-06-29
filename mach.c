//
// Created by Robert JONES on 2017/06/29.
//

#include <stdlib.h>
#include <memory.h>
#include "Includes/mach.h"
#include "Includes/mach_64.h"
#include "Includes/mach_32.h"

static int	ft_iswhite(char s)
{
	if (s == ' ' || s == '\t' || s == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*re;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = (int) (strlen(s) - 1);
	while (ft_iswhite(s[i]) == 1)
		i++;
	while (ft_iswhite(s[length]) == 1)
		length--;
	if (!(re = (char *)malloc(sizeof(char) * ((length - i) + 1))))
		return (NULL);
	while (i <= length)
		re[j++] = s[i++];
	re[j] = '\0';
	return (re);
}

int ft_get_section_offset_64(void *data, int is_big_end, t_nlist_64 *nls)
{
	int 			sec_count;
	int				offset;
	t_seg_cmd_64	seg;

	sec_count = 0;
	offset = sizeof(t_mach_64);
	while(sec_count < nls->n_sect)
	{
		memcpy(&seg, (data + offset), sizeof(t_seg_cmd_64));
		if (is_big_end == FALSE)
			ft_revirce_segment_64(&seg);
		sec_count += seg.nsects;
		if (sec_count < nls->n_sect)
			offset += seg.cmdsize;
		else
			offset += sizeof(t_seg_cmd_64);
	}
	return (offset + ((nls->n_sect - (sec_count - seg.nsects) - 1) * sizeof(t_section_64)));
}

int ft_get_section_offset_32(void *data, int is_big_end, t_nlist_32 *nls)
{
	int 			sec_count;
	int				offset;
	t_seg_cmd_32	seg;

	sec_count = 0;
	offset = sizeof(t_mach_32);
	while(sec_count < nls->n_sect)
	{
		memcpy(&seg, (data + offset), sizeof(t_seg_cmd_32));
		if (is_big_end == FALSE)
			ft_revirce_segment_32(&seg);
		sec_count += seg.nsects;
		if (sec_count < nls->n_sect)
			offset += seg.cmdsize;
		else
			offset += sizeof(t_seg_cmd_32);
	}
	return (offset + ((nls->n_sect - (sec_count - seg.nsects) - 1) * sizeof(t_section_32)));
}

void revirce_bytes(void *data, size_t size)
{
	char    tmp;
	char    *st;
	char    *end;

	if (size == 0)
		return ;
	st = data;
	end = data + (size - 1);
	while (end > st){
		tmp = *st;
		*st = *end;
		*end = tmp;
		st++;
		end--;
	}
}

void    ft_revirce_symtab(t_symtab_cmd *symtab)
{
	revirce_bytes(&symtab->cmd, sizeof(uint32_t));
	revirce_bytes(&symtab->cmdsize, sizeof(uint32_t));
	revirce_bytes(&symtab->symoff, sizeof(uint32_t));
	revirce_bytes(&symtab->nsyms, sizeof(uint32_t));
	revirce_bytes(&symtab->stroff, sizeof(uint32_t));
	revirce_bytes(&symtab->strsize, sizeof(uint32_t));
}

void	ft_revirce_ld_cmd(t_ld_cmd *ld)
{
	revirce_bytes(&ld->cmd, sizeof(uint32_t));
	revirce_bytes(&ld->cmdsize, sizeof(uint32_t));

}