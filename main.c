#include <stdlib.h>
#include "mlx/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int 	bpp;
	int 	line;
	int 	endian;
}	t_data;

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(r * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(b * 255) << 16;
	return (color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1280, 720, "FDF");
	img.img = mlx_new_image(mlx_ptr, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0xFF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
