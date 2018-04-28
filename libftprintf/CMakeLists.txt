cmake_minimum_required(VERSION 3.10)
project(libftprintf C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(libftprintf
        inc/printf.h
        src/field_width.c
        src/flags.c
        src/ft_atoi.c
        src/ft_atoi_base.c
        src/ft_bzero.c
        src/ft_check.c
        src/ft_check_pers.c
        src/ft_itoa.c
        src/ft_itoa_base.c
        src/ft_itoa_base_l.c
        src/ft_lcs_unicode.c
        src/ft_lstadd.c
        src/ft_lstdel.c
        src/ft_lstdelone.c
        src/ft_lstnew.c
        src/ft_memalloc.c
        src/ft_memccpy.c
        src/ft_memchr.c
        src/ft_memcmp.c
        src/ft_memcpy.c
        src/ft_memdel.c
        src/ft_memmove.c
        src/ft_memset.c
        src/ft_output.c
        src/ft_printf.c
        src/ft_putchar.c
        src/ft_putchar_fd.c
        src/ft_putendl.c
        src/ft_putendl_fd.c
        src/ft_putnbr.c
        src/ft_putnbr_fd.c
        src/ft_putstr.c
        src/ft_putstr_fd.c
        src/ft_strchr.c
        src/ft_strcpy.c
        src/ft_strdel.c
        src/ft_strdup.c
        src/ft_strjoin.c
        src/ft_strlen.c
        src/ft_strncmp.c
        src/ft_strnew.c
        src/ft_strrchr.c
        src/ft_strstr.c
        src/ft_strsub.c
        src/ft_toupper.c
        src/function_pointers.c
        src/get_next_line.c
        src/modifiers.c
        src/nbr_hex.c
        src/precision.c
        src/specifiers.c
        src/specifiers2.c)
