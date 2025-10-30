#include "../../includes/cube.h"

double	deg_to_rad(double degrees)
{
	return (degrees * M_PI / 180.0);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int	abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}