void	put_square(__global char* string, char *map, int i, int width)
{
	
}

__kernel void wolf(__global char* string, char *map, int width)
{
	int i;

	i = get_global_id(0);
	put_square(string, map, i, width);
}
