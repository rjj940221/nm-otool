# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/zfs-student-6/users/rojones/year2/nm-otool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/nm_otool.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nm_otool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nm_otool.dir/flags.make

CMakeFiles/nm_otool.dir/ft_nm.c.o: CMakeFiles/nm_otool.dir/flags.make
CMakeFiles/nm_otool.dir/ft_nm.c.o: ../ft_nm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/nm_otool.dir/ft_nm.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm_otool.dir/ft_nm.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_nm.c

CMakeFiles/nm_otool.dir/ft_nm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm_otool.dir/ft_nm.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_nm.c > CMakeFiles/nm_otool.dir/ft_nm.c.i

CMakeFiles/nm_otool.dir/ft_nm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm_otool.dir/ft_nm.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_nm.c -o CMakeFiles/nm_otool.dir/ft_nm.c.s

CMakeFiles/nm_otool.dir/ft_nm.c.o.requires:

.PHONY : CMakeFiles/nm_otool.dir/ft_nm.c.o.requires

CMakeFiles/nm_otool.dir/ft_nm.c.o.provides: CMakeFiles/nm_otool.dir/ft_nm.c.o.requires
	$(MAKE) -f CMakeFiles/nm_otool.dir/build.make CMakeFiles/nm_otool.dir/ft_nm.c.o.provides.build
.PHONY : CMakeFiles/nm_otool.dir/ft_nm.c.o.provides

CMakeFiles/nm_otool.dir/ft_nm.c.o.provides.build: CMakeFiles/nm_otool.dir/ft_nm.c.o


CMakeFiles/nm_otool.dir/ft_extract_file.c.o: CMakeFiles/nm_otool.dir/flags.make
CMakeFiles/nm_otool.dir/ft_extract_file.c.o: ../ft_extract_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/nm_otool.dir/ft_extract_file.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm_otool.dir/ft_extract_file.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_extract_file.c

CMakeFiles/nm_otool.dir/ft_extract_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm_otool.dir/ft_extract_file.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_extract_file.c > CMakeFiles/nm_otool.dir/ft_extract_file.c.i

CMakeFiles/nm_otool.dir/ft_extract_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm_otool.dir/ft_extract_file.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_extract_file.c -o CMakeFiles/nm_otool.dir/ft_extract_file.c.s

CMakeFiles/nm_otool.dir/ft_extract_file.c.o.requires:

.PHONY : CMakeFiles/nm_otool.dir/ft_extract_file.c.o.requires

CMakeFiles/nm_otool.dir/ft_extract_file.c.o.provides: CMakeFiles/nm_otool.dir/ft_extract_file.c.o.requires
	$(MAKE) -f CMakeFiles/nm_otool.dir/build.make CMakeFiles/nm_otool.dir/ft_extract_file.c.o.provides.build
.PHONY : CMakeFiles/nm_otool.dir/ft_extract_file.c.o.provides

CMakeFiles/nm_otool.dir/ft_extract_file.c.o.provides.build: CMakeFiles/nm_otool.dir/ft_extract_file.c.o


CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o: CMakeFiles/nm_otool.dir/flags.make
CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o: ../ft_read_mach_64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_mach_64.c

CMakeFiles/nm_otool.dir/ft_read_mach_64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm_otool.dir/ft_read_mach_64.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_mach_64.c > CMakeFiles/nm_otool.dir/ft_read_mach_64.c.i

CMakeFiles/nm_otool.dir/ft_read_mach_64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm_otool.dir/ft_read_mach_64.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_mach_64.c -o CMakeFiles/nm_otool.dir/ft_read_mach_64.c.s

CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o.requires:

.PHONY : CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o.requires

CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o.provides: CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o.requires
	$(MAKE) -f CMakeFiles/nm_otool.dir/build.make CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o.provides.build
.PHONY : CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o.provides

CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o.provides.build: CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o


CMakeFiles/nm_otool.dir/ft_read_march_32.c.o: CMakeFiles/nm_otool.dir/flags.make
CMakeFiles/nm_otool.dir/ft_read_march_32.c.o: ../ft_read_march_32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/nm_otool.dir/ft_read_march_32.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm_otool.dir/ft_read_march_32.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_march_32.c

CMakeFiles/nm_otool.dir/ft_read_march_32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm_otool.dir/ft_read_march_32.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_march_32.c > CMakeFiles/nm_otool.dir/ft_read_march_32.c.i

CMakeFiles/nm_otool.dir/ft_read_march_32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm_otool.dir/ft_read_march_32.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_march_32.c -o CMakeFiles/nm_otool.dir/ft_read_march_32.c.s

CMakeFiles/nm_otool.dir/ft_read_march_32.c.o.requires:

.PHONY : CMakeFiles/nm_otool.dir/ft_read_march_32.c.o.requires

CMakeFiles/nm_otool.dir/ft_read_march_32.c.o.provides: CMakeFiles/nm_otool.dir/ft_read_march_32.c.o.requires
	$(MAKE) -f CMakeFiles/nm_otool.dir/build.make CMakeFiles/nm_otool.dir/ft_read_march_32.c.o.provides.build
.PHONY : CMakeFiles/nm_otool.dir/ft_read_march_32.c.o.provides

CMakeFiles/nm_otool.dir/ft_read_march_32.c.o.provides.build: CMakeFiles/nm_otool.dir/ft_read_march_32.c.o


CMakeFiles/nm_otool.dir/ft_otool.c.o: CMakeFiles/nm_otool.dir/flags.make
CMakeFiles/nm_otool.dir/ft_otool.c.o: ../ft_otool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/nm_otool.dir/ft_otool.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm_otool.dir/ft_otool.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_otool.c

CMakeFiles/nm_otool.dir/ft_otool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm_otool.dir/ft_otool.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_otool.c > CMakeFiles/nm_otool.dir/ft_otool.c.i

CMakeFiles/nm_otool.dir/ft_otool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm_otool.dir/ft_otool.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_otool.c -o CMakeFiles/nm_otool.dir/ft_otool.c.s

CMakeFiles/nm_otool.dir/ft_otool.c.o.requires:

.PHONY : CMakeFiles/nm_otool.dir/ft_otool.c.o.requires

CMakeFiles/nm_otool.dir/ft_otool.c.o.provides: CMakeFiles/nm_otool.dir/ft_otool.c.o.requires
	$(MAKE) -f CMakeFiles/nm_otool.dir/build.make CMakeFiles/nm_otool.dir/ft_otool.c.o.provides.build
.PHONY : CMakeFiles/nm_otool.dir/ft_otool.c.o.provides

CMakeFiles/nm_otool.dir/ft_otool.c.o.provides.build: CMakeFiles/nm_otool.dir/ft_otool.c.o


CMakeFiles/nm_otool.dir/ft_archive.c.o: CMakeFiles/nm_otool.dir/flags.make
CMakeFiles/nm_otool.dir/ft_archive.c.o: ../ft_archive.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/nm_otool.dir/ft_archive.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm_otool.dir/ft_archive.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_archive.c

CMakeFiles/nm_otool.dir/ft_archive.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm_otool.dir/ft_archive.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_archive.c > CMakeFiles/nm_otool.dir/ft_archive.c.i

CMakeFiles/nm_otool.dir/ft_archive.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm_otool.dir/ft_archive.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_archive.c -o CMakeFiles/nm_otool.dir/ft_archive.c.s

CMakeFiles/nm_otool.dir/ft_archive.c.o.requires:

.PHONY : CMakeFiles/nm_otool.dir/ft_archive.c.o.requires

CMakeFiles/nm_otool.dir/ft_archive.c.o.provides: CMakeFiles/nm_otool.dir/ft_archive.c.o.requires
	$(MAKE) -f CMakeFiles/nm_otool.dir/build.make CMakeFiles/nm_otool.dir/ft_archive.c.o.provides.build
.PHONY : CMakeFiles/nm_otool.dir/ft_archive.c.o.provides

CMakeFiles/nm_otool.dir/ft_archive.c.o.provides.build: CMakeFiles/nm_otool.dir/ft_archive.c.o


# Object files for target nm_otool
nm_otool_OBJECTS = \
"CMakeFiles/nm_otool.dir/ft_nm.c.o" \
"CMakeFiles/nm_otool.dir/ft_extract_file.c.o" \
"CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o" \
"CMakeFiles/nm_otool.dir/ft_read_march_32.c.o" \
"CMakeFiles/nm_otool.dir/ft_otool.c.o" \
"CMakeFiles/nm_otool.dir/ft_archive.c.o"

# External object files for target nm_otool
nm_otool_EXTERNAL_OBJECTS =

nm_otool: CMakeFiles/nm_otool.dir/ft_nm.c.o
nm_otool: CMakeFiles/nm_otool.dir/ft_extract_file.c.o
nm_otool: CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o
nm_otool: CMakeFiles/nm_otool.dir/ft_read_march_32.c.o
nm_otool: CMakeFiles/nm_otool.dir/ft_otool.c.o
nm_otool: CMakeFiles/nm_otool.dir/ft_archive.c.o
nm_otool: CMakeFiles/nm_otool.dir/build.make
nm_otool: CMakeFiles/nm_otool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable nm_otool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nm_otool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nm_otool.dir/build: nm_otool

.PHONY : CMakeFiles/nm_otool.dir/build

CMakeFiles/nm_otool.dir/requires: CMakeFiles/nm_otool.dir/ft_nm.c.o.requires
CMakeFiles/nm_otool.dir/requires: CMakeFiles/nm_otool.dir/ft_extract_file.c.o.requires
CMakeFiles/nm_otool.dir/requires: CMakeFiles/nm_otool.dir/ft_read_mach_64.c.o.requires
CMakeFiles/nm_otool.dir/requires: CMakeFiles/nm_otool.dir/ft_read_march_32.c.o.requires
CMakeFiles/nm_otool.dir/requires: CMakeFiles/nm_otool.dir/ft_otool.c.o.requires
CMakeFiles/nm_otool.dir/requires: CMakeFiles/nm_otool.dir/ft_archive.c.o.requires

.PHONY : CMakeFiles/nm_otool.dir/requires

CMakeFiles/nm_otool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nm_otool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nm_otool.dir/clean

CMakeFiles/nm_otool.dir/depend:
	cd /nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/zfs-student-6/users/rojones/year2/nm-otool /nfs/zfs-student-6/users/rojones/year2/nm-otool /nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug /nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug /nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles/nm_otool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nm_otool.dir/depend

