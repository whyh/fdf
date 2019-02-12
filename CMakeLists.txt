cmake_minimum_required(VERSION 3.13)

project(fdf_clion)

set(CMAKE_C_STANDARD 99)

link_directories(fdf mlx)

AUX_SOURCE_DIRECTORY(libft LIBFT)
AUX_SOURCE_DIRECTORY(libft/ft_printf FT_PRINTF)
AUX_SOURCE_DIRECTORY(libft/ft_gnl FT_GNL)
AUX_SOURCE_DIRECTORY(ffdf FFDF)

add_executable(fdf_clion
        ${LIBFT}
        ${FFDF}
        ${FT_PRINTF}
        ${FT_GNL})

target_link_libraries(fdf_clion "-framework OpenGL" "-framework AppKit" "-lmlx")