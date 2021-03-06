#include <stdio.h>
#include <stdlib.h>
#include <mach-o/loader.h>
#include <mach-o/swap.h>
#include <mach-o/fat.h>

void dump_segments(FILE *obj_file);

int main(int argc, char *argv[]) {
	const char *filename = argv[1];
	FILE *obj_file = fopen(filename, "rb");
	dump_segments(obj_file);
	fclose(obj_file);

	return 0;
}

uint32_t read_magic(FILE *obj_file, int offset) {
	uint32_t magic;
	fseek(obj_file, offset, SEEK_SET);
	fread(&magic, sizeof(uint32_t), 1, obj_file);
	return magic;
}

int is_magic_64(uint32_t magic) {
	return magic == MH_MAGIC_64 || magic == MH_CIGAM_64;
}

int should_swap_bytes(uint32_t magic) {
	return magic == MH_CIGAM || magic == MH_CIGAM_64 || magic == FAT_CIGAM;
}

int is_fat(uint32_t magic) {
	return magic == FAT_MAGIC || magic == FAT_CIGAM;
}

struct _cpu_type_names {
	cpu_type_t cputype;
	const char *cpu_name;
};

static struct _cpu_type_names cpu_type_names[] = {
	{ CPU_TYPE_I386, "i386" },
	{ CPU_TYPE_X86_64, "x86_64" },
	{ CPU_TYPE_ARM, "arm" },
	{ CPU_TYPE_ARM64, "arm64" }
};

static const char *cpu_type_name(cpu_type_t cpu_type) {
	static int cpu_type_names_size = sizeof(cpu_type_names) / sizeof(struct _cpu_type_names);
	for (int i = 0; i < cpu_type_names_size; i++ ) {
		if (cpu_type == cpu_type_names[i].cputype) {
			return cpu_type_names[i].cpu_name;
		}
	}

	return "unknown";
}

void *load_bytes(FILE *obj_file, int offset, int size) {
	void *buf = calloc(1, size);
	fseek(obj_file, offset, SEEK_SET);
	fread(buf, size, 1, obj_file);
	return buf;
}

void dump_segment_commands(FILE *obj_file, int offset, int is_swap, uint32_t ncmds) {
	int actual_offset = offset;
	for (int  i = 0; i < ncmds; i++) {
		struct load_command *cmd = load_bytes(obj_file, actual_offset, sizeof(struct load_command));
		if (is_swap) {
			swap_load_command(cmd, 0);
		}

		if (cmd->cmd == LC_SEGMENT_64) {
			struct segment_command_64 *segment = load_bytes(obj_file, actual_offset, sizeof(struct segment_command_64));
			if (is_swap) {
				swap_segment_command_64(segment, 0);
			}

			printf("segname: %s\n", segment->segname);

			free(segment);
		} else if (cmd->cmd == LC_SEGMENT) {
			struct segment_command *segment = load_bytes(obj_file, actual_offset, sizeof(struct segment_command));
			if (is_swap) {
				swap_segment_command(segment, 0);
			}

			printf("segname: %s\n", segment->segname);

			free(segment);
		}

		actual_offset += cmd->cmdsize;

		free(cmd);
	}
}

void dump_mach_header(FILE *obj_file, int offset, int is_64, int is_swap) {
	uint32_t ncmds;
	int load_commands_offset = offset;

	if (is_64) {
		int header_size = sizeof(struct mach_header_64);
		struct mach_header_64 *header = load_bytes(obj_file, offset, header_size);
		if (is_swap) {
			swap_mach_header_64(header, 0);
		}
		ncmds = header->ncmds;
		load_commands_offset += header_size;

		printf("%s\n", cpu_type_name(header->cputype));

		free(header);
	} else {
		int header_size = sizeof(struct mach_header);
		struct mach_header *header = load_bytes(obj_file, offset, header_size);
		if (is_swap) {
			swap_mach_header(header, 0);
		}

		ncmds = header->ncmds;
		load_commands_offset += header_size;

		printf("%s\n", cpu_type_name(header->cputype));

		free(header);
	}

	dump_segment_commands(obj_file, load_commands_offset, is_swap, ncmds);
}

void dump_fat_header(FILE *obj_file, int is_swap) {
	int header_size = sizeof(struct fat_header);
	int arch_size = sizeof(struct fat_arch);

	puts("dump fat header");
	struct fat_header *header = load_bytes(obj_file, 0, header_size);
	if (is_swap) {
		swap_fat_header(header, 0);
	}

	int arch_offset = header_size;
	for (int i = 0; i < header->nfat_arch; i++) {
		struct fat_arch *arch = load_bytes(obj_file, arch_offset, arch_size);

		if (is_swap) {
			swap_fat_arch(arch, 1, 0);
		}

		int mach_header_offset = arch->offset;
		free(arch);
		arch_offset += arch_size;

		uint32_t magic = read_magic(obj_file, mach_header_offset);
		int is_64 = is_magic_64(magic);
		int is_swap_mach = should_swap_bytes(magic);
		dump_mach_header(obj_file, mach_header_offset, is_64, is_swap_mach);
	}
	free(header); 
}

void dump_segments(FILE *obj_file) {
	uint32_t magic = read_magic(obj_file, 0);
	int is_64 = is_magic_64(magic);
	int is_swap = should_swap_bytes(magic);
	int fat = is_fat(magic);
	if (fat) {
		dump_fat_header(obj_file, is_swap);
	} else {
		dump_mach_header(obj_file, 0, is_64, is_swap);
	}
}
