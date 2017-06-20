


#include "Includes/nm-otool.h"

uint32_t get_magic(void *data){
	uint32_t magic;

	memcpy(&magic, data, sizeof(uint32_t));
	return magic;
}

void print_bytes(const void *object, size_t size)
{
	// This is for C++; in C just drop the static_cast<>() and assign.
	const unsigned char * const bytes = (const unsigned char *)(object);
	size_t i;

	printf("[ ");
	for(i = 0; i < size; i++)
	{
		printf("%02x ", bytes[i]);
	}
	printf("]\n");
}

void ft_extract_file(void *data)
{
	uint32_t magic;

	magic = get_magic(data);
	if (magic == ELF_MAGIC) {
		puts("elf file");
		return ;
	}
	if (magic == FAT_CIGAM || magic == FAT_MAGIC) {
		puts("fat file");
		return ;
	}
	if (magic == MACH_CIGAM || magic == MACH_MAGIC) {
		puts("mach file");
		ft_read_mach(data);
		return ;
	}
	if (magic == MACH_CIGAM_64 || magic == MACH_MAGIC_64) {
		puts("mach 64 file");
		ft_read_mach_64(data);
		return ;
	}
	puts("unkowen file type");
}