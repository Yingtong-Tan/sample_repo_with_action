#include "util_geo_operation.h"

double utility_function::calculate_distance_earth_meter_wgs84(double lat1d, double lon1d, double lat2d, double lon2d)
{
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = convert_unit<double>(lat1d, DEGREE, RADIAN);
	lon1r = convert_unit<double>(lon1d, DEGREE, RADIAN);
	lat2r = convert_unit<double>(lat2d, DEGREE, RADIAN);
	lon2r = convert_unit<double>(lon2d, DEGREE, RADIAN);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * EARTH_RADIUS * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

double utility_function::calculate_distance_earth_meter_mecator(double lat1d, double lon1d, double lat2d, double lon2d)
{
	double distance = 0.0;

	return distance;
}