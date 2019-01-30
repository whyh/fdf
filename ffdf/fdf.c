#include <stdio.h>
#include <mlx.h>

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 215);
	mlx_pixel_put(mlx_ptr, win_ptr, 251, 250, 1215);
	mlx_pixel_put(mlx_ptr, win_ptr, 252, 250, 17215);
	mlx_pixel_put(mlx_ptr, win_ptr, 253, 250, 16215);
	mlx_loop(mlx_ptr);
	return 0;
}