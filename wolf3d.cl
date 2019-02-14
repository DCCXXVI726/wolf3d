void	put_square(__global char* string, char* map, int i, int width)
{
	int x;
	int y;
	int color;
	int put_x;
	int put_y;

	x = i % width;
	y = i / width;
	if (*(map + i) == '0')
		color = 0xFFFFFF;
	else
		color = 0xAAAAAA;
	put_y = 0;
	while (put_y < 50)
	{
		put_x = 0;
		while (put_x < 50)
		{
			((__global unsigned int*) string)[(y * 50 + put_y) * 1000 + (x * 50 + put_x)] = color;
			put_x++;
		}
		put_y++;
	}
}

__kernel void wolf(__global char* string, char* map, int width)
{
	int i;

	i = get_global_id(0);
	put_square(string, map, i, width);
}
