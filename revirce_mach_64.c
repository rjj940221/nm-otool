//
// Created by rojones on 2017/06/28.
//

#include "Includes/mach_64.h"


void    ft_revirce_nlist_64(t_nlist_64 *nls)
{
	revirce_bytes(&nls->n_un.n_strx, sizeof(uint32_t));
	revirce_bytes(&nls->n_type, sizeof(uint8_t));
	revirce_bytes(&nls->n_sect, sizeof(uint8_t));
	revirce_bytes(&nls->n_desc, sizeof(uint16_t));
	revirce_bytes(&nls->n_value, sizeof(uint64_t));
}

void    ft_revirce_mach_heder_64(t_mach_64 *header)
{
	revirce_bytes(&header->cputype, sizeof(cpu_type_t));
	revirce_bytes(&header->cpusubtype, sizeof(cpu_subtype_t));
	revirce_bytes(&header->filetype, sizeof(uint32_t));
	revirce_bytes(&header->ncmds, sizeof(uint32_t));
	revirce_bytes(&header->sizeofcmds, sizeof(uint32_t));
	revirce_bytes(&header->flags, sizeof(uint32_t));
	revirce_bytes(&header->reserved, sizeof(uint32_t));
}

void    ft_revirce_segment_64(t_seg_cmd_64 *seg)
{
	revirce_bytes(&seg->cmd, sizeof(uint32_t));
	revirce_bytes(&seg->cmdsize, sizeof(uint32_t));
	revirce_bytes(&seg->segname, 16);
	revirce_bytes(&seg->vmaddr, sizeof(uint64_t));
	revirce_bytes(&seg->vmsize, sizeof(uint64_t));
	revirce_bytes(&seg->fileoff, sizeof(uint64_t));
	revirce_bytes(&seg->filesize, sizeof(uint64_t));
	revirce_bytes(&seg->maxprot, sizeof(vm_prot_t));
	revirce_bytes(&seg->initprot, sizeof(vm_prot_t));
	revirce_bytes(&seg->nsects, sizeof(uint32_t));
	revirce_bytes(&seg->flags, sizeof(uint32_t));
}

void    ft_revirce_section_64(t_section_64 *sec)
{
	revirce_bytes(&sec->sectname, 16);
	revirce_bytes(&sec->segname, 16);
	revirce_bytes(&sec->addr, sizeof(uint64_t));
	revirce_bytes(&sec->size, sizeof(uint64_t));
	revirce_bytes(&sec->offset, sizeof(uint32_t));
	revirce_bytes(&sec->align, sizeof(uint32_t));
	revirce_bytes(&sec->reloff, sizeof(uint32_t));
	revirce_bytes(&sec->nreloc, sizeof(uint32_t));
	revirce_bytes(&sec->flags, sizeof(uint32_t));
	revirce_bytes(&sec->reserved1, sizeof(uint32_t));
	revirce_bytes(&sec->reserved2, sizeof(uint32_t));
	revirce_bytes(&sec->reserved3, sizeof(uint32_t));
}

