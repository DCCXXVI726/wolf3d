#include "wolf3d.h"

void	move_menu_string(t_wolf *wolf)
{
	int part;
	int y;
	int x;

	part = wolf->win_heidth / 8 * (wolf->menu_string + 1);
	y = 0;
	while (y < (wolf->win_heidth / 8))
	{
		x = 0;
		while (x < wolf->win_width / 1.5)
		{
			((int*)wolf->start_img)[(int)(((y + part) * wolf->win_width) + (x + wolf->win_width / 6))] = 0xff6666;
			x++;
		}
		y++;
	}
}

void	draw_square(t_wolf *wolf, double part, int color, int shift)
{
	int y;
	int x;
	int x_shift;
	int y_shift;

	if (shift == 0)
	{
		x_shift = 0;
		y_shift = 0;
	}
	else
	{
		x_shift = wolf->win_width / shift;
		y_shift = wolf->win_heidth / shift;
	}
	y = -1;
	while (++y < (wolf->win_heidth / part))
	{
		x = -1;
		while (++x < (wolf->win_width / part))
		{
			((int*)wolf->start_img)[(int)(((y + y_shift) *
				wolf->win_width) + (x + x_shift))] = color;
		}
	}
}

int		add_text(t_wolf *wolf)
{
	if (wolf->menu == 1)
	{
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 2, wolf->win_heidth / 100 * 20, 0x000000, "Menu:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 3, wolf->win_heidth / 100 * 30, 0x000000, "Change FOV:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 100 * 42, wolf->win_heidth / 100 * 30, 0x000000, ft_itoa(wolf->fov[(int)(wolf->fov[0])] / 3.14 * 180));
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 3, wolf->win_heidth / 100 * 42, 0x000000, "SRAKA:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 3, wolf->win_heidth / 100 * 55, 0x000000, "SRAKA:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 3, wolf->win_heidth / 100 * 68, 0x000000, "SRAKA:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 100 * 45, wolf->win_heidth / 100 * 78, 0x000000, "made by SRAKA 2019");
	}
	return (0);
}

void	menu(t_wolf *wolf)
{
	draw_square(wolf, 1, 0xff3333, 0);
	draw_square(wolf, 1.5, 0xff0000, 6);
	move_menu_string(wolf);
}
