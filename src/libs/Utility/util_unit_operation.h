#pragma once
#include "util_include_all.h"

namespace utility_function
{
//all metric 
#define EARTH_RADIUS 6371000
#define PI 3.141592658
#define E 2.718281828459
#define GRAVITY_ACC 9.8

	enum LENGTH_UNIT
	{
		CENTEMETER,
		METER,
		KILOMETER,
		FOOT,
		INCH,
		MILE
	};

	enum WEIGHT_UNIT
	{
		GRAM,
		KILOGRAM,
		POUND
	};

	enum SPEED_UNIT
	{
		METER_PER_SECOND,
		FOOT_PER_SECOND,
		MILE_PER_HOUR,
		KILOMIETER_PER_HOUR
	};

	enum ACCELERATION_UNIT
	{
		FOOT_PER_SECOND_SQUARE,
		METER_PER_SECOND_SQUARE
	};

	enum  PLANE_ANGLE
	{
		DEGREE,
		RADIAN
	};

	enum TIME_UNIT
	{
		SECOND,
		SUBSECOND
	};

	template<class T>
	inline T convert_unit(T input, SPEED_UNIT from_unit, SPEED_UNIT to_unit)
	{
		T output = input;
		if (from_unit != to_unit)
		{
			if (from_unit == MILE_PER_HOUR && to_unit == METER_PER_SECOND)
			{
				output = input * 0.44704;
			}
			else if (from_unit == METER_PER_SECOND && to_unit == MILE_PER_HOUR)
			{
				output = input / 0.44704;
			}
			else if (from_unit == MILE_PER_HOUR && to_unit == FOOT_PER_SECOND)
			{
				output = input * 1.46667;
			}
			else if (to_unit == FOOT_PER_SECOND && from_unit == MILE_PER_HOUR)
			{
				output = input / 1.46667;
			}
		}
		return output;
	};

	template<class T>
	inline T convert_unit(T input, WEIGHT_UNIT from_unit, WEIGHT_UNIT to_unit)
	{
		T output = input;
		if (from_unit != to_unit)
		{
			if (from_unit == KILOGRAM && to_unit == POUND)
			{
				output = input * 2.20462;
			}
			else if (from_unit == POUND && to_unit == KILOGRAM)
			{
				output = input / 2.20462;
			}
		}
		return output;
	};

	template<class T>
	inline T convert_unit(T input, LENGTH_UNIT from_unit, LENGTH_UNIT to_unit)
	{
		T output = input;
		if (from_unit != to_unit)
		{
			if (from_unit == FOOT && to_unit == METER)
			{
				output = input * 0.3048;
			}
			else if (from_unit == METER && to_unit == FOOT)
			{
				output = input / 0.3048;
			}
			else if (from_unit == FOOT && to_unit == MILE)
			{
				output = input / 5280;
			}
			else if (from_unit == MILE && to_unit == FOOT)
			{
				output = input * 5280;
			}
		}
		return output;
	};

	template<class T>
	inline T convert_unit(T input, PLANE_ANGLE from_unit, PLANE_ANGLE to_unit)
	{
		T output = input;
		if (from_unit != to_unit)
		{
			switch (from_unit)
			{
			case DEGREE:
				output = input * PI / 180;
				break;
			case RADIAN:
				output = input * 180 / PI;
				break;
			default:
				break;
			}
		}
		return output;
	};

	template<class T>
	inline T lat_degree_to_meter(T lat_degree)
	{
		double lat_rad = lat_degree / 180.0f * M_PI;
		return 6378137.0f * log((sin(lat_rad) + 1) / cos(lat_rad));
	};

	template<class T>
	inline T long_degree_to_meter(T lon_degree)
	{
		return (lon_degree) / 180.0f * PI * 6378137.0f;
	};
}