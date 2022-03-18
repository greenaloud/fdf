#include "mlx/mlx.h"

typedef struct	s_prog
{
	void	*mlx;
	void	*window;
}	t_prog;

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(r * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(b * 255) << 16;
	return (color);
}

int	main(int argc, char **argv)
{
	t_prog	prog;

	(void) argc;
	(void) argv;

	prog.mlx = mlx_init();
	prog.window = mlx_new_window(prog.mlx, 1280, 720, "FDF of Wocho");

	mlx_pixel_put(prog.mlx, prog.window, 1280 / 2, 720 / 2, rgb_to_int(0.9, 0.9, 0.3));

	mlx_loop(prog.mlx);
}
