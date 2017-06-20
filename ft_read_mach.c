//
// Created by Robert JONES on 2017/06/20.
//

#include "Includes/nm-otool.h"

void ft_read_mach(void *data){
	struct mach_header header;

	memcpy(&header, data, MACH_HEADER_SIZE);
	printf("num comd %d\n", header.ncmds);
}

void ft_read_mach_64(void *data){
	struct mach_header_64		header;
	struct segment_command_64	seg;
	uint32_t					i;
	int							offset;
	int							is_big_end;
	uint32_t 					cmp;

	cmp = 0xcffaedfe;
	memcpy(&header, data, MACH_64_HEADER_SIZE);
	if (memcmp(&header.magic, &cmp, 4) == 0)
		is_big_end = TRUE;
	else
		is_big_end = FALSE;
	print_bytes(&header.magic, sizeof(header.magic));
	print_bytes(&cmp, sizeof(cmp));
	printf("num comd %d\n", header.ncmds);
	if (is_big_end == TRUE)
		puts("is big end in");
	i = 0;
	offset = MACH_64_HEADER_SIZE;
	while (i < header.ncmds)
	{
		memcpy(&seg, (data + offset), sizeof(struct segment_command_64));
		printf("seg name: %s\t seg cmd: %d\n", seg.segname, seg.cmd);
		i++;
	}
}