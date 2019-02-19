double ft_abs(double x)
{
	if (x < 0)
		return ((-1) * x);
	return (x);
}

int	ft_round(double x)
{
	if (x - (int)x >= 0.5)
		return ((int)x + 1);
	return ((int)x);
}

void	put_line(__global char* string, double x1, double y1, double x2, double y2, int color)
{
	double for_swap;
	double grad;

	if (x1 == x2)
	{
        if (y2 < y1)
        {
            for_swap = y1;
            y1 = y2;
            y2 = for_swap;
        }
		while (y1 < y2)
		{
			((__global unsigned int*)string)[ft_round(y1) * 1000 + ft_round(x1)] = color;
			y1++;
		}
	} else if (y1 == y2)
    {
        if (x2 < x1)
        {
            for_swap = x1;
            x1 = x2;
            x2 = for_swap;
        }
        while (x1 < x2)
        {
            ((__global unsigned int*)string)[ft_round(y1) * 1000 + ft_round(x1)] = color;
            x1++;
        }
    } else if (y2 - y1 > x2 - x1)
	{
		if (y2 < y1)
        {
            for_swap = x1;
            x1 = x2;
            x2 = for_swap;
			for_swap = y1;
            y1 = y2;
            y2 = for_swap;
        }
		grad = (x2 - x1) / (y2 - y1);
		while (y1 < y2)
		{
			((__global unsigned int*)string)[ft_round(y1) * 1000 + ft_round(x1)] = color;
			y1++;
			x1 = x1 + grad;
		}
	}
	else
    {
		if (x2 < x1)
        {
            for_swap = x1;
            x1 = x2;
            x2 = for_swap;
            for_swap = y1;
            y1 = y2;
            y2 = for_swap;
        }
        grad = (y2 - y1) / (x2 - x1);
        while (x1 < x2)
        {
            ((__global unsigned int*)string)[ft_round(y1) * 1000 + ft_round(x1)] = color;
            x1++;
            y1 = y1 + grad;
        }
    }
}

__kernel void wolf(__global char* string,
                    __global char* map,
                    int width,
                    double player_x,
                    double player_y, double main_angle, double fov, int iteration, int heigth)
{
	int i;
	double x1;
	double x2;
	double y1;
	double y2;
	double old_x1;
    double old_x2;
    double old_y1;
    double old_y2;
	double angle;
	double x_step;
	double y_step;
	int color;
	
	i = get_global_id(0);
	if (i < width * heigth)
	{
		main_angle = main_angle - 3.14 / 2;
	    old_x1 = i % width * 50 - player_x * 50;
	    old_y1 = i / width / 2 * 50 - player_y * 50;
		if ((i / width) % 2 == 0)
		{
			old_x2 = old_x1 + 50;
			old_y2 = old_y1;
		}
		else
		{
			old_x2 = old_x1;
			old_y2 = old_y1 + 50;
		}
		x1 = old_x1 * cos(main_angle) - old_y1 * sin(main_angle);
		y1 = old_x1 * sin(main_angle) + old_y1 * cos(main_angle);
		x2 = old_x2 * cos(main_angle) - old_y2 * sin(main_angle);
	    y2 = old_x2 * sin(main_angle) + old_y2 * cos(main_angle);
		if (*(map + i) != '0')
			put_line(string, x1 + 500, y1 + 500, x2 + 500, y2 + 500, 0xFF0000);
	}
	else
	{
		i = i - width * heigth;
		angle = main_angle + fov * (((double)(iteration)) / 2 - i) / iteration;
		if (cos(angle) != 0)
		{
			if (cos(angle) > 0)
			{
				x1 = 1 + (int)(player_x);
				x_step = 1;
				y1 = player_y - (1 + (int)(player_x) - player_x) * tan(angle);
			}
			else
			{
				x1 = (int)player_x;
				x_step = -1;
				y1 = player_y + (player_x - (int)(player_x)) * tan(angle);
			}
			y_step = x_step * tan(angle);
			while (x1 >= 0 && x1 < width && y1 >= 0 && y1 < heigth / 2)
			{
				if (*(map + (int)x1 + (((int)y1) * 2 + 1) * width) != '0')
					break ;
				y1 = y1 - y_step;
				x1 = x1 + x_step;
			}
		}
		else
		{
			x1 = -1;
			y1 = -1;
		}
		if (sin(angle) != 0)
		{
			if (sin(angle) > 0)
			{
				y2 = (int)player_y;
				y_step = 1;
				if (cos(angle) != 0)
				{
					x2 = player_x + (player_y - (int)(player_y)) / tan(angle);
					x_step = y_step / tan(angle);
				}
				else
				{
					x2 = (int)player_x;
					x_step = 0;
				}
			}
			else
			{
				y2 = 1 + (int)player_y;
				y_step = -1;
				if (cos(angle) != 0)
				{
					x2 = player_x - (1 - player_y + (int)(player_y)) / tan(angle);
					x_step = y_step / tan(angle);
				}
				else
				{
					x2 = 1 + (int)player_x;
					x_step = 0;
				}
			}
			while (x2 >= 0 && x2 < width - 1 && y2 >= 0 && y2 < heigth / 2)
        	{
        	    if (*(map + (int)x2 + ((int)y2) * 2 * width) != '0')
            	    break ;
            	y2 = y2 - y_step;
            	x2 = x2 + x_step;
        	}
		}
		else
		{
			y2 = -1;
			x2 = -1;
		}
		if ((x2 >= 0 && x2 < width - 1 && y2 >= 0 && y2 < heigth / 2) || (x1 >= 0 && x1 < width && y1 >= 0 && y1 < heigth / 2))
		{
			color = 0xFFFF00;
			if (!(x2 >= 0 && x2 < width - 1 && y2 >= 0 && y2 < heigth / 2))
			{
				x2 = x1;
				y2 = x1;
				color = 0x0000FF;
			}
			else if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < heigth / 2)
			{
				if (ft_abs(player_x - x1) < ft_abs(player_x - x2))
				{
					x2 = x1;
					y2 = y1;
					color = 0x0000FF;
				}
			}
			main_angle = main_angle - 3.14 / 2;
			old_x2 = (x2 - player_x) * 50;
			old_y2 = (y2 - player_y) * 50;
			x2 = old_x2 * cos(main_angle) - old_y2 * sin(main_angle);
        	y2 = old_x2 * sin(main_angle) + old_y2 * cos(main_angle);
			put_line(string, 500, 500, x2 + 500, y2 + 500, color);
		}
	}
}
