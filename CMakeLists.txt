cmake_minimum_required(VERSION 3.13)
project(fdf C)

set(CMAKE_C_STANDARD 99)

add_executable(fdf main.c libft/ft_gnl/ft_gnl.h fdf/fdf.h ffdf/fdf2.c)