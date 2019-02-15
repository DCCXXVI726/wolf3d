__kernel void wolf( __global char* string,
                    __global char* map,
                    int width,
                    double player_x,
                    double player_y)
{
	int i;
	int x;
    int y;
    int color;
    int put_x;
    int put_y;
	int x0;
	int y0;

	x0 = 250;
	y0 = 250;
	i = get_global_id(0);
	x = i % width + (int)player_x;
    y = i / width + (int)player_y;
    put_y = (int)player_y;
    if (*(map + i)  == '0')
                color = 255;
            else
                color = 255 * 256;
    while (put_y < 50 + (int)player_y)
    {
        put_x = player_x;
        while (put_x < 50 + (int)player_x)
        {
            if (put_x == (int)player_x || put_y == (int)player_y || put_x == (int)player_x + 49 || put_y == (int)player_y + 49)
                ((__global unsigned int*) string)[(y * 50 + put_y + y0) * 1000 + (x * 50 + put_x) + x0] = 0;
            else
                ((__global unsigned int*) string)[(y * 50 + put_y + y0) * 1000 + (x * 50 + put_x) + x0] = color;
            put_x++;
        }
        put_y++;
    }
}
