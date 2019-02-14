__kernel void wolf(__global char* string, char map, int width)
{
	int i;
	int x;
    int y;
    int color;
    int put_x;
    int put_y;

	i = get_global_id(0);
	x = i % width;
    y = i / width;
    if (map  == '0')
        color = 255;
    else
        color = 255 * 256;
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
