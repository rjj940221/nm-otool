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
include CMakeFiles/ft_otool.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ft_otool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ft_otool.dir/flags.make

CMakeFiles/ft_otool.dir/ft_extract_file.c.o: CMakeFiles/ft_otool.dir/flags.make
CMakeFiles/ft_otool.dir/ft_extract_file.c.o: ../ft_extract_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ft_otool.dir/ft_extract_file.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_otool.dir/ft_extract_file.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_extract_file.c

CMakeFiles/ft_otool.dir/ft_extract_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_otool.dir/ft_extract_file.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_extract_file.c > CMakeFiles/ft_otool.dir/ft_extract_file.c.i

CMakeFiles/ft_otool.dir/ft_extract_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_otool.dir/ft_extract_file.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_extract_file.c -o CMakeFiles/ft_otool.dir/ft_extract_file.c.s

CMakeFiles/ft_otool.dir/ft_extract_file.c.o.requires:

.PHONY : CMakeFiles/ft_otool.dir/ft_extract_file.c.o.requires

CMakeFiles/ft_otool.dir/ft_extract_file.c.o.provides: CMakeFiles/ft_otool.dir/ft_extract_file.c.o.requires
	$(MAKE) -f CMakeFiles/ft_otool.dir/build.make CMakeFiles/ft_otool.dir/ft_extract_file.c.o.provides.build
.PHONY : CMakeFiles/ft_otool.dir/ft_extract_file.c.o.provides

CMakeFiles/ft_otool.dir/ft_extract_file.c.o.provides.build: CMakeFiles/ft_otool.dir/ft_extract_file.c.o


CMakeFiles/ft_otool.dir/ft_otool.c.o: CMakeFiles/ft_otool.dir/flags.make
CMakeFiles/ft_otool.dir/ft_otool.c.o: ../ft_otool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ft_otool.dir/ft_otool.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_otool.dir/ft_otool.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_otool.c

CMakeFiles/ft_otool.dir/ft_otool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_otool.dir/ft_otool.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_otool.c > CMakeFiles/ft_otool.dir/ft_otool.c.i

CMakeFiles/ft_otool.dir/ft_otool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_otool.dir/ft_otool.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_otool.c -o CMakeFiles/ft_otool.dir/ft_otool.c.s

CMakeFiles/ft_otool.dir/ft_otool.c.o.requires:

.PHONY : CMakeFiles/ft_otool.dir/ft_otool.c.o.requires

CMakeFiles/ft_otool.dir/ft_otool.c.o.provides: CMakeFiles/ft_otool.dir/ft_otool.c.o.requires
	$(MAKE) -f CMakeFiles/ft_otool.dir/build.make CMakeFiles/ft_otool.dir/ft_otool.c.o.provides.build
.PHONY : CMakeFiles/ft_otool.dir/ft_otool.c.o.provides

CMakeFiles/ft_otool.dir/ft_otool.c.o.provides.build: CMakeFiles/ft_otool.dir/ft_otool.c.o


CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o: CMakeFiles/ft_otool.dir/flags.make
CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o: ../ft_read_mach_64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_mach_64.c

CMakeFiles/ft_otool.dir/ft_read_mach_64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_otool.dir/ft_read_mach_64.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_mach_64.c > CMakeFiles/ft_otool.dir/ft_read_mach_64.c.i

CMakeFiles/ft_otool.dir/ft_read_mach_64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_otool.dir/ft_read_mach_64.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_mach_64.c -o CMakeFiles/ft_otool.dir/ft_read_mach_64.c.s

CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o.requires:

.PHONY : CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o.requires

CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o.provides: CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o.requires
	$(MAKE) -f CMakeFiles/ft_otool.dir/build.make CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o.provides.build
.PHONY : CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o.provides

CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o.provides.build: CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o


CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o: CMakeFiles/ft_otool.dir/flags.make
CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o: ../ft_read_mach_32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_mach_32.c

CMakeFiles/ft_otool.dir/ft_read_mach_32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_otool.dir/ft_read_mach_32.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_mach_32.c > CMakeFiles/ft_otool.dir/ft_read_mach_32.c.i

CMakeFiles/ft_otool.dir/ft_read_mach_32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_otool.dir/ft_read_mach_32.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/ft_read_mach_32.c -o CMakeFiles/ft_otool.dir/ft_read_mach_32.c.s

CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o.requires:

.PHONY : CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o.requires

CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o.provides: CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o.requires
	$(MAKE) -f CMakeFiles/ft_otool.dir/build.make CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o.provides.build
.PHONY : CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o.provides

CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o.provides.build: CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o


CMakeFiles/ft_otool.dir/revirce_mach_32.c.o: CMakeFiles/ft_otool.dir/flags.make
CMakeFiles/ft_otool.dir/revirce_mach_32.c.o: ../revirce_mach_32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ft_otool.dir/revirce_mach_32.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_otool.dir/revirce_mach_32.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/revirce_mach_32.c

CMakeFiles/ft_otool.dir/revirce_mach_32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_otool.dir/revirce_mach_32.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/revirce_mach_32.c > CMakeFiles/ft_otool.dir/revirce_mach_32.c.i

CMakeFiles/ft_otool.dir/revirce_mach_32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_otool.dir/revirce_mach_32.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/revirce_mach_32.c -o CMakeFiles/ft_otool.dir/revirce_mach_32.c.s

CMakeFiles/ft_otool.dir/revirce_mach_32.c.o.requires:

.PHONY : CMakeFiles/ft_otool.dir/revirce_mach_32.c.o.requires

CMakeFiles/ft_otool.dir/revirce_mach_32.c.o.provides: CMakeFiles/ft_otool.dir/revirce_mach_32.c.o.requires
	$(MAKE) -f CMakeFiles/ft_otool.dir/build.make CMakeFiles/ft_otool.dir/revirce_mach_32.c.o.provides.build
.PHONY : CMakeFiles/ft_otool.dir/revirce_mach_32.c.o.provides

CMakeFiles/ft_otool.dir/revirce_mach_32.c.o.provides.build: CMakeFiles/ft_otool.dir/revirce_mach_32.c.o


CMakeFiles/ft_otool.dir/revirce_mach_64.c.o: CMakeFiles/ft_otool.dir/flags.make
CMakeFiles/ft_otool.dir/revirce_mach_64.c.o: ../revirce_mach_64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ft_otool.dir/revirce_mach_64.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_otool.dir/revirce_mach_64.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/revirce_mach_64.c

CMakeFiles/ft_otool.dir/revirce_mach_64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_otool.dir/revirce_mach_64.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/revirce_mach_64.c > CMakeFiles/ft_otool.dir/revirce_mach_64.c.i

CMakeFiles/ft_otool.dir/revirce_mach_64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_otool.dir/revirce_mach_64.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/revirce_mach_64.c -o CMakeFiles/ft_otool.dir/revirce_mach_64.c.s

CMakeFiles/ft_otool.dir/revirce_mach_64.c.o.requires:

.PHONY : CMakeFiles/ft_otool.dir/revirce_mach_64.c.o.requires

CMakeFiles/ft_otool.dir/revirce_mach_64.c.o.provides: CMakeFiles/ft_otool.dir/revirce_mach_64.c.o.requires
	$(MAKE) -f CMakeFiles/ft_otool.dir/build.make CMakeFiles/ft_otool.dir/revirce_mach_64.c.o.provides.build
.PHONY : CMakeFiles/ft_otool.dir/revirce_mach_64.c.o.provides

CMakeFiles/ft_otool.dir/revirce_mach_64.c.o.provides.build: CMakeFiles/ft_otool.dir/revirce_mach_64.c.o


CMakeFiles/ft_otool.dir/mach.c.o: CMakeFiles/ft_otool.dir/flags.make
CMakeFiles/ft_otool.dir/mach.c.o: ../mach.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ft_otool.dir/mach.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_otool.dir/mach.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/mach.c

CMakeFiles/ft_otool.dir/mach.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_otool.dir/mach.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/mach.c > CMakeFiles/ft_otool.dir/mach.c.i

CMakeFiles/ft_otool.dir/mach.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_otool.dir/mach.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/mach.c -o CMakeFiles/ft_otool.dir/mach.c.s

CMakeFiles/ft_otool.dir/mach.c.o.requires:

.PHONY : CMakeFiles/ft_otool.dir/mach.c.o.requires

CMakeFiles/ft_otool.dir/mach.c.o.provides: CMakeFiles/ft_otool.dir/mach.c.o.requires
	$(MAKE) -f CMakeFiles/ft_otool.dir/build.make CMakeFiles/ft_otool.dir/mach.c.o.provides.build
.PHONY : CMakeFiles/ft_otool.dir/mach.c.o.provides

CMakeFiles/ft_otool.dir/mach.c.o.provides.build: CMakeFiles/ft_otool.dir/mach.c.o


CMakeFiles/ft_otool.dir/fat.c.o: CMakeFiles/ft_otool.dir/flags.make
CMakeFiles/ft_otool.dir/fat.c.o: ../fat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/ft_otool.dir/fat.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_otool.dir/fat.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/fat.c

CMakeFiles/ft_otool.dir/fat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_otool.dir/fat.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/fat.c > CMakeFiles/ft_otool.dir/fat.c.i

CMakeFiles/ft_otool.dir/fat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_otool.dir/fat.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/fat.c -o CMakeFiles/ft_otool.dir/fat.c.s

CMakeFiles/ft_otool.dir/fat.c.o.requires:

.PHONY : CMakeFiles/ft_otool.dir/fat.c.o.requires

CMakeFiles/ft_otool.dir/fat.c.o.provides: CMakeFiles/ft_otool.dir/fat.c.o.requires
	$(MAKE) -f CMakeFiles/ft_otool.dir/build.make CMakeFiles/ft_otool.dir/fat.c.o.provides.build
.PHONY : CMakeFiles/ft_otool.dir/fat.c.o.provides

CMakeFiles/ft_otool.dir/fat.c.o.provides.build: CMakeFiles/ft_otool.dir/fat.c.o


CMakeFiles/ft_otool.dir/revirce_fat.c.o: CMakeFiles/ft_otool.dir/flags.make
CMakeFiles/ft_otool.dir/revirce_fat.c.o: ../revirce_fat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/ft_otool.dir/revirce_fat.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_otool.dir/revirce_fat.c.o   -c /nfs/zfs-student-6/users/rojones/year2/nm-otool/revirce_fat.c

CMakeFiles/ft_otool.dir/revirce_fat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_otool.dir/revirce_fat.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-6/users/rojones/year2/nm-otool/revirce_fat.c > CMakeFiles/ft_otool.dir/revirce_fat.c.i

CMakeFiles/ft_otool.dir/revirce_fat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_otool.dir/revirce_fat.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-6/users/rojones/year2/nm-otool/revirce_fat.c -o CMakeFiles/ft_otool.dir/revirce_fat.c.s

CMakeFiles/ft_otool.dir/revirce_fat.c.o.requires:

.PHONY : CMakeFiles/ft_otool.dir/revirce_fat.c.o.requires

CMakeFiles/ft_otool.dir/revirce_fat.c.o.provides: CMakeFiles/ft_otool.dir/revirce_fat.c.o.requires
	$(MAKE) -f CMakeFiles/ft_otool.dir/build.make CMakeFiles/ft_otool.dir/revirce_fat.c.o.provides.build
.PHONY : CMakeFiles/ft_otool.dir/revirce_fat.c.o.provides

CMakeFiles/ft_otool.dir/revirce_fat.c.o.provides.build: CMakeFiles/ft_otool.dir/revirce_fat.c.o


# Object files for target ft_otool
ft_otool_OBJECTS = \
"CMakeFiles/ft_otool.dir/ft_extract_file.c.o" \
"CMakeFiles/ft_otool.dir/ft_otool.c.o" \
"CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o" \
"CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o" \
"CMakeFiles/ft_otool.dir/revirce_mach_32.c.o" \
"CMakeFiles/ft_otool.dir/revirce_mach_64.c.o" \
"CMakeFiles/ft_otool.dir/mach.c.o" \
"CMakeFiles/ft_otool.dir/fat.c.o" \
"CMakeFiles/ft_otool.dir/revirce_fat.c.o"

# External object files for target ft_otool
ft_otool_EXTERNAL_OBJECTS =

ft_otool: CMakeFiles/ft_otool.dir/ft_extract_file.c.o
ft_otool: CMakeFiles/ft_otool.dir/ft_otool.c.o
ft_otool: CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o
ft_otool: CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o
ft_otool: CMakeFiles/ft_otool.dir/revirce_mach_32.c.o
ft_otool: CMakeFiles/ft_otool.dir/revirce_mach_64.c.o
ft_otool: CMakeFiles/ft_otool.dir/mach.c.o
ft_otool: CMakeFiles/ft_otool.dir/fat.c.o
ft_otool: CMakeFiles/ft_otool.dir/revirce_fat.c.o
ft_otool: CMakeFiles/ft_otool.dir/build.make
ft_otool: CMakeFiles/ft_otool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable ft_otool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ft_otool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ft_otool.dir/build: ft_otool

.PHONY : CMakeFiles/ft_otool.dir/build

CMakeFiles/ft_otool.dir/requires: CMakeFiles/ft_otool.dir/ft_extract_file.c.o.requires
CMakeFiles/ft_otool.dir/requires: CMakeFiles/ft_otool.dir/ft_otool.c.o.requires
CMakeFiles/ft_otool.dir/requires: CMakeFiles/ft_otool.dir/ft_read_mach_64.c.o.requires
CMakeFiles/ft_otool.dir/requires: CMakeFiles/ft_otool.dir/ft_read_mach_32.c.o.requires
CMakeFiles/ft_otool.dir/requires: CMakeFiles/ft_otool.dir/revirce_mach_32.c.o.requires
CMakeFiles/ft_otool.dir/requires: CMakeFiles/ft_otool.dir/revirce_mach_64.c.o.requires
CMakeFiles/ft_otool.dir/requires: CMakeFiles/ft_otool.dir/mach.c.o.requires
CMakeFiles/ft_otool.dir/requires: CMakeFiles/ft_otool.dir/fat.c.o.requires
CMakeFiles/ft_otool.dir/requires: CMakeFiles/ft_otool.dir/revirce_fat.c.o.requires

.PHONY : CMakeFiles/ft_otool.dir/requires

CMakeFiles/ft_otool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ft_otool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ft_otool.dir/clean

CMakeFiles/ft_otool.dir/depend:
	cd /nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/zfs-student-6/users/rojones/year2/nm-otool /nfs/zfs-student-6/users/rojones/year2/nm-otool /nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug /nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug /nfs/zfs-student-6/users/rojones/year2/nm-otool/cmake-build-debug/CMakeFiles/ft_otool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ft_otool.dir/depend

