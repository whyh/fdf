cmake_minimum_required(VERSION 3.13)

project(fdf)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

AUX_SOURCE_DIRECTORY(libft LIBFT)
AUX_SOURCE_DIRECTORY(ffdf FFDF)
AUX_SOURCE_DIRECTORY(minilibx_macos MLX)

add_executable( ffdf ${LIBFT}
                ffdf ${FFDF}
                ffdf ${MLX}
                ffdf/fdf.c
                libft/ft_gnl/ft_gnl.c
                libft/ft_gnl/ft_gnl.h
                libft/ft_gnl/ft_gnl_typedefs.h
                libft/ft_printf/ft_printf.c
                libft/ft_printf/ft_printf_cspf.c
                libft/ft_printf/ft_printf_diouxx.c
                libft/ft_printf/ft_printf_fill_funs.c
                libft/ft_printf/ft_printf_hash_zero_blank_plus.c
                libft/ft_printf/ft_printf_parse.c
                libft/ft_printf/ft_printf_prec.c
                libft/ft_printf/ft_printf_width.c
                libft/ft_printf/ft_printf_mod0_b_cap_udo.c
                libft/ft_printf/ft_printf_0_base.c
                libft/ft_printf/ft_printf_lhllhhl.c
                libft/ft_printf/ft_printf_zjt.c
                libft/ft_printf/ft_printf_r.c
                libft/ft_printf/ft_printf_unicode.c
                libft/ft_printf/ft_printf_parce_funs.c
                libft/ft_printf/ft_printf_collor.c
                libft/ft_printf/ft_printf.h
                ffdf/fdf.h
                ffdf/fdf_parse.c
                ffdf/fdf_typedefs.h
                ffdf/fdf_draw.c
                ffdf/fdf_projections.c
        ffdf/fdf_gradient.c
                ffdf/fdf_interact.c
                ffdf/fdf_help_menu.c
                ffdf/fdf_interface.c
                ffdf/fdf_mouse_control.c
                ffdf/fdf_key_control.c
        ffdf/fdf_inits.c ffdf/fdf_complete_map.c)

link_libraries(libft/libft.a)