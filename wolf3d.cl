__kernel void wolf( __global char* string,
                    __global char* map,
                    int width,
                    double player_x,
                    double player_y, double angle)
{
	int i;
	int x;
    int y;
    int color;
    int put_x;
    int put_y;
	int x0;
	int y0;
	int corr;
	
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
			corr = (-1 * (int)((y * 50 + put_y) * sin(angle)) + (int)((x * 50 + put_x) * cos(angle)) + y0) * 1000 + (int)((x * 50 + put_x) * cos(angle)) + (int)((y * 50 + put_y) * sin(angle)) + x0;
            if (put_x == (int)player_x || put_y == (int)player_y || put_x == (int)player_x + 49 || put_y == (int)player_y + 49)
                ((__global unsigned int*) string)[corr] = 0;
            else
                ((__global unsigned int*) string)[corr] = color;
            put_x++;
        }
        put_y++;
    }
}
