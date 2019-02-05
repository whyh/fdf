cmake_minimum_required(VERSION 3.13)

project(fdf)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

LINK_DIRECTORIES(libft/ mlx/)

AUX_SOURCE_DIRECTORY(ffdf FFDF)
AUX_SOURCE_DIRECTORY(libft LIBFT)
AUX_SOURCE_DIRECTORY(libft/ft_printf FT_PRINTF)
AUX_SOURCE_DIRECTORY(libft/ft_gnl FT_GNL)

add_executable(
        fdf_clion ${LIBFT}
        fdf_clion ${FT_GNL}
        fdf_clion ${FT_PRINTF}
        fdf_clion ${FFDF})

target_link_libraries(fdf_clion "-framework OpenGL" "-framework AppKit" "-lmlx" "-lft")
