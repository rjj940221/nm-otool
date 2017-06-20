cmake_minimum_required(VERSION 3.7)
project(nm_otool)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ft_nm.c ft_extract_file.c Includes/nm-otool.h Includes/mach.h Includes/mach_64.h ft_read_mach.c)

add_executable(nm_otool ${SOURCE_FILES})