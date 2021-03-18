#pragma once
#include "util_include_all.h"
#include "util_point_operation.h"
#include "util_unit_operation.h"

namespace utility_function
{
#define PI 3.14159265359
#define EARTH_RADIUS 6378137
#define MECATOR_CORRECT 1.001120232

	double calculate_distance_earth_meter_wgs84(double lat1d, double lon1d, double lat2d, double lon2d);
	double calculate_distance_earth_meter_mecator(double lat1d, double lon1d, double lat2d, double lon2d);

	template<typename T>
	void convert_mecator_to_WGS84(Point<T> & mecator_coordinate)
	{
		mecator_coordinate.x = MECATOR_CORRECT * mecator_coordinate.x / (PI / 180) / EARTH_RADIUS;
		mecator_coordinate.y = (2 * atan(exp(MECATOR_CORRECT * mecator_coordinate.y / EARTH_RADIUS)) - PI / 2) / (PI / 180);
	};
	
	template<typename T>
	void convert_WGS84_to_mecator(Point<T> & WGS_coordinate)
	{
		WGS_coordinate.x = WGS_coordinate.x * EARTH_RADIUS* (PI / 180) / MECATOR_CORRECT;
		WGS_coordinate.y = tan((WGS_coordinate.y * (PI / 180) + PI / 2) / 2);
	};

	template<typename T>
	void convert_mecator_to_matrix(Point<T> & mecator_coordinate, T x_refNet, T y_refNet, T x_refMap, T y_refMap)
	{
		T reference_latitude = (2 * atan(exp(y_refMap * MECATOR_CORRECT / EARTH_RADIUS)) - PI / 2) / (PI / 180);
		T local_scale = 1 / cos(reference_latitude / (180 / PI));
		
		T x = (mecator_coordinate.x - x_refMap) / local_scale;
		T y = (mecator_coordinate.y - y_refMap) / local_scale;
		mecator_coordinate.x = x;
		mecator_coordinate.y = y;
	}

	template<typename T>
	void convert_matrix_to_mecator(Point<T> & point, T x_refNet, T y_refNet, T x_refMap, T y_refMap)
	{
		T reference_latitude = (2 * atan(exp(y_refMap * MECATOR_CORRECT / EARTH_RADIUS)) - PI / 2) / (PI / 180);
		T local_scale = 1 / cos(reference_latitude / (180 / PI));
		T x = (point.x - x_refNet) * local_scale + x_refMap;
		T y = (point.y - y_refNet) * local_scale + y_refMap;
		point.x = x;
		point.y = y;
	}
}