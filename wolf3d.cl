int		ft_round(double x)
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

__kernel void wolf( __global char* string,
                    __global char* map,
                    int width,
                    double player_x,
                    double player_y, double angle)
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

	i = get_global_id(0);
	angle = angle + 3.14 / 2;
    old_x1 = i % width * 50 - player_x;
    old_y1 = i / width / 2 * 50 - player_y;
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
	x1 = old_x1 * cos(angle) + old_y1 * sin(angle);
	y1 = (-1) * old_x1 * sin(angle) + old_y1 * cos(angle);
	x2 = old_x2 * cos(angle) + old_y2 * sin(angle);
    y2 = (-1) * old_x2 * sin(angle) + old_y2 * cos(angle);
	if (*(map + i) != '0')
		put_line(string, x1 + 500, y1 + 500, x2 + 500, y2 + 500, 0xFF0000);
}
