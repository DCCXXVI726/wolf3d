__kernel void wolf(__global char* string, __global char* map, int width, double player_x, double player_y)
{
	int i;
	int x;
    int y;
    int color;
    int put_x;
    int put_y;

	i = get_global_id(0);
	x = i % width + player_x;
    y = i / width + player_y;
    put_y = player_y;
    if (*(map + i)  == '0')
                color = 255;
            else
                color = 255 * 256;
    while (put_y < 50 + y)
    {
        put_x = player_x;
        while (put_x < 50 + player_x)
        {
            if (put_x == player_x || put_y == player_y || put_x == player_x + 49 || put_y == player_y + 49)
                ((__global unsigned int*) string)[(y * 50 + put_y) * 1000 + (x * 50 + put_x)] = 0;
            else
                ((__global unsigned int*) string)[(y * 50 + put_y) * 1000 + (x * 50 + put_x)] = color;
            put_x++;
        }
        put_y++;
    }
}
