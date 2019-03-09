#include "wolf3d.h"

void    menu(t_wolf *wolf)
{
    int y1;
	int x1;
	
    y1 = 0;
	while (y1 < wolf->win_heidth)
	{
        x1 = 0; 
		while (x1 < wolf->win_width)
        {
			((int*)wolf->start_img)[(int)((y1 * wolf->win_width) + x1)] = 0xff3333;
		    x1++;
        }
        y1++;
	}
    y1 = 0;
    while (y1 < wolf->win_heidth / 1.5)
	{
        x1 = 0; 
		while (x1 < wolf->win_width / 1.5)
        {
			((int*)wolf->start_img)[(int)(((y1 + wolf->win_heidth / 6) * wolf->win_width) + (x1 + wolf->win_width / 6))] = 0xff0000;
		    x1++;
        }
        y1++;
	}
}
