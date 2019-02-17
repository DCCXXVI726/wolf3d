__kernel void wolf( __global char* string,
                    __global char* map,
                    int width,
                    double x,
                    double y, double main_angle, double fov, int iteration)
{
	int i;
	int flag;
	double x1;
	double y1;
	double x2;
	double y2;
	double x_step;
	double y_step;
	double x_longstep;
	double y_longstep;
	double angle;
	double dx;
	double dy;
	double deltax;
	double deltay;
	double p;
	int height;
	int m;
	int k;
	int color;

	i = get_global_id(0);
<<<<<<< HEAD
	flag = 0;
	angle = main_angle + (i - ((double)iteration) / 2) / iteration * fov;
	if (sin(angle) > 0)
	{
		dy = (int)(y) - y;
		if (cos(angle) != 0)
			y_step = (-1) * tan(angle);
		else
			y_step = -1;
		y_longstep = -1;
	}
	else
	{
		dy = 1 + (int)(y) - y;
        if (cos(angle) != 0)
            y_step = tan(angle);
        else
            y_step = 1;
		y_longstep = 1;
	}
	if (cos(angle) > 0)
	{
		dx = 1 - x + (int)x;
		if (sin(angle) == 0)
			x_step = 1;
		else if (cos(angle) == 0)
			x_step = 0;
		else
			x_step = 1 / tan(angle);
		x_longstep = 1;
	}
	else
    {
        dx = (int)x - x;
        if (sin(angle) == 0)
            x_step = -1;
        else if (cos(angle) == 0)
            x_step = 0;
        else
        	x_step = (-1) / tan(angle);
        x_longstep = -1;
    }
	x1 = x + dx;
	if (cos(angle) == 0)
		y1 = y + dy;
	else
		y1 = y - dx * tan(angle);
	if (cos(angle) == 0)
		x2 = x;
	else if (sin(angle) == 0)
		x2 = x + dx;
	else
		x2 = x - dy / tan(angle);
	y2 = y + dy;
	m = 0;
	while (flag == 0 && m < 1000)
	{
		while (x1 <= x2 && m < 1000)
		{
			if (*(map + (int)(y1) * width + (int)(x1)) != '0')
			{
				if (*(map + (int)(y1) * width + (int)(x1)) == '2')
                    color = 0xFF0000;
                else
                    color = 0x00FF00;
				deltax = x1 - x;
				deltay = y1 - y;
				flag = 1;
				break;
			}
			x1 = x1 + x_longstep;
			y1 = y1 + y_step;
			m++;
		}
		if (flag == 1)
			break;
		while (x2 < x1 && m < 1000)
		{
			if (*(map + (int)(y2) * width + (int)(x2)) != '0')
			{
				if (*(map + (int)(y2) * width + (int)(x2)) == '2')
					color = 0xFF0000;
				else
					color = 0x00FF00;
				deltax = x2 - x;
                deltay = y2 - y;
                flag = 1;
                break;
			}
			x2 = x2 + x_step;
			y2 = y2 + y_longstep;
			m++;
		}
		m++;
	}
	if (m == 1000)
		p = 1;
	else
		p = fabs(fabs(deltax) * cos(main_angle) + fabs(deltay) * sin(main_angle));
	height = (int)(100 / p);
	m = (int)(i / iteration * 1000);
	while (m < (int)((i + 1) / iteration * 1000))
=======
	x_wall = i % width;
	y_wall = i / width;
	if (*(map + i) == '0')
		color = 0xC0C0C0;
	else
		color = 0x808080;
	angle = angle + 3.14 / 2;
	start_x = x_wall * 50 - (int)player_x;
	start_y = y_wall * 50 - (int)player_y;
	put_y = 0;
	while (put_y < 50)
>>>>>>> a138af8ce0ee29ab28cd79a7dd836e6db5f3964c
	{
		k = (-1) * height / 2;
		while (k < height / 2)
		{
			((__global int*)string)[(k + 500) * 1000 + m] = color;
			k++;
		}
		m++;
	}
}
