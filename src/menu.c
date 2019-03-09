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

void	add_text(t_wolf *wolf)
{
	
}

void	menu(t_wolf *wolf)
{
	draw_square(wolf, 1, 0xff3333, 0);
	draw_square(wolf, 1.5, 0xff0000, 6);
	move_menu_string(wolf);
}
