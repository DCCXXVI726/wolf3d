__kernel void wolf(__global char* string)
{
	int i;
	double x;

	i = get_global_id(0);
	x = sin((double)i);
	((__global unsigned int*) string)[i] = round(x * 256);
}
