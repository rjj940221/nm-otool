cmake_minimum_required(VERSION 3.7)
project(nm_otool)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")
set(NM_SOURCE_FILES
        Includes/mach.h
        Includes/mach_32.h
        Includes/mach_64.h
        Includes/nm-otool.h
        Includes/fat.h
        ft_extract_file.c
        ft_nm.c
        ft_read_mach_64.c
        ft_read_mach_32.c
        revirce_mach_32.c
        revirce_mach_64.c
        mach.c
        fat.c
        revirce_fat.c)

set(OTOOL_SOURCE_FILES
        Includes/mach.h
        Includes/mach_32.h
        Includes/mach_64.h
        Includes/nm-otool.h
        Includes/fat.h
        ft_extract_file.c
        ft_otool.c
        ft_read_mach_64.c
        ft_read_mach_32.c
        revirce_mach_32.c
        revirce_mach_64.c
        mach.c
        fat.c
        revirce_fat.c)

add_executable(ft_nm ${NM_SOURCE_FILES})
add_executable(ft_otool ${OTOOL_SOURCE_FILES})