__kernel void wolf( __global char* string,
                    __global char* map,
                    int width,
                    double player_x,
                    double player_y, double angle)
{
	int i;
	int	x_wall;
	int	y_wall;
	int start_x;
	int start_y;
	int put_x;
	int put_y;
	int coor;
	int color;

	i = get_global_id(0);
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
	{
		put_x = 0;
		while (put_x < 50)
		{
			coor = ((int)(((start_y + put_y) * cos(angle) - (start_x + put_x) * sin(angle)) + 500)) * 1000 + (int)((start_x + put_x) * cos(angle) + (start_y + put_y)* sin(angle) + 500);
			((__global unsigned int*)string)[coor] = color;
			put_x++;
		}
		put_y++;
	}
}
