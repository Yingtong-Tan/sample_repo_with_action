#pragma once
#include "util_include_all.h"

namespace utility_function
{
	template <class T>
	struct Point
	{
		T x = 0;
		T y = 0;
		T z = 0;
	};

	double point_to_line_distance(double x, double y, double x1, double y1, double x2, double y2);
	
	template <class T> 
	Point<T> outer_product(const Point<T> & point1, const Point<T> & point2)
	{
		Point<T> result;
		result.x = point1.y*point2.z - point2.y*point1.z;
		result.y = -(point1.x*point2.z - point2.x*point1.z);
		result.z = (point1.x*point2.y - point2.x*point1.y);
		return result;
	}
	
	template <class T> 
	Point<T> operator-(const Point<T> & point)
	{
		Point<T> result_point;
		result_point.x = 0 - point.x;
		result_point.y = 0 - point.y;
		result_point.z = 0 - point.z;
		return result_point;
	};

	template <class T>
	Point<T> operator-(const Point<T> & head_point, const Point<T> & tail_point)
	{
		Point<T> result_point;
		result_point.x = head_point.x - tail_point.x;
		result_point.y = head_point.y - tail_point.y;
		result_point.z = head_point.z - tail_point.z;
		return result_point;
	};

	template <class T>
	Point<T> operator+(const Point<T> & head_point, const Point<T> & tail_point)
	{
		Point<T> result_point;
		result_point.x = head_point.x + tail_point.x;
		result_point.y = head_point.y + tail_point.y;
		result_point.z = head_point.z + tail_point.z;
		return result_point;
	};

	template <class T>
	Point<T> operator*(const Point<T> & head_point, const T & ratio)
	{
		Point<T> result_point;
		result_point.x = head_point.x * ratio;
		result_point.y = head_point.y * ratio;
		result_point.z = head_point.z * ratio;
		return result_point;
	};

	template <class T>
	Point<T> operator*( const T & ratio, const Point<T> & head_point)
	{
		Point<T> result_point;
		result_point.x = head_point.x * ratio;
		result_point.y = head_point.y * ratio;
		result_point.z = head_point.z * ratio;
		return result_point;
	};

	template <class T>
	vector<Point<T>> operator*(const vector<Point<T>> & head_points, const T & ratio)
	{
		vector<Point<T>> point_vector(head_points.size());
		for(int point_index = 0; point_index < head_points.size(); point_index++)
		{
			point_vector[point_index] = head_points[point_index] * ratio;
		}
		return point_vector;
	};

	template <class T>
	vector<Point<T>> operator*(const T & ratio, const vector<Point<T>> & head_points)
	{
		vector<Point<T>> point_vector(head_points.size());
		for (int point_index = 0; point_index < head_points.size(); point_index++)
		{
			point_vector[point_index] = head_points[point_index] * ratio;
		}
		return point_vector;
	};

	template <class T>
	vector<Point<T>> operator*(const vector<Point<T>> & left_points, const vector<Point<T>> & right_points)
	{
		vector<Point<T>> point_vector(head_point.size());
		for (int point_index = 0; point_index < right_points.size(); point_index++)
		{
			point_vector[point_index] = right_points[point_index] * left_points[point_index];
		}
		return point_vector;
	};

	template <class T>
	Point<T> operator/(const Point<T> & head_point, const T ratio)
	{
		Point<T> result_point;
		result_point.x = head_point.x / ratio;
		result_point.y = head_point.y / ratio;
		result_point.z = head_point.z / ratio;
		return result_point;
	};

	template <class T>
	vector<Point<T>> operator/(const vector<Point<T>> &  head_points, const T ratio)
	{
		vector<Point<T>> point_vector(head_point.size());
		for (int point_index = 0; point_index < head_points.size(); point_index++)
		{
			point_vector[point_index] = head_points[point_index] / ratio;
		}			
		return 	point_vector;
	};

	template <class T>
	vector<Point<T>> operator-(const vector<Point<T>> & head_point, const vector<Point<T>> & tail_point)
	{
		int number_of_points = head_point.size();
		vector<Point<T>> result_points(number_of_points);
		for (int point_index = 0; point_index< number_of_points;point_index++)
		{
			Point<T> & result_point = result_points[point_index];
			result_point.x = head_point[point_index].x - tail_point[point_index].x;
			result_point.y = head_point[point_index].y - tail_point[point_index].y;
			result_point.z = head_point[point_index].z - tail_point[point_index].z;
		}
		return result_points;
	};

	template <class T>
	T operator*(const Point<T> v1, const Point<T> v2)
	{
		return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	}

	template <class T>
	Point<T> cross_product(const Point<T> a, const Point<T> b)
	{
		Point<T> result_point;
		result_point.x = a.y*b.z - a.z*b.y;
		result_point.y = a.z*b.x - a.x*b.z;
		result_point.z = a.x*b.y - a.y*b.x;
		return result_point;
	}

	template <class T>
	vector<Point<T>> operator+(const vector<Point<T>> & head_point, const vector<Point<T>> & tail_point)
	{
		int number_of_points = head_point.size();
		vector<Point<T>> result_points(number_of_points);
		for (int point_index = 0; point_index< number_of_points;point_index++)
		{
			Point<T> & result_point = result_points[point_index];
			result_point.x = head_point[point_index].x + tail_point[point_index].x;
			result_point.y = head_point[point_index].y + tail_point[point_index].y;
			result_point.z = head_point[point_index].z + tail_point[point_index].z;
		}
		return result_points;
	};

	template<class T> 
	T abs(const Point<T> & head_point)
	{
		return sqrt(head_point.x * head_point.x + head_point.y * head_point.y + head_point.z * head_point.z);
	};

	template<class T>
	T abs2D(const Point<T> & head_point)
	{
		return sqrt(head_point.x * head_point.x + head_point.y * head_point.y);
	};

	template<class T>
	Point<T> normalize(const Point<T> & head_point)
	{
		return head_point/sqrt(head_point.x * head_point.x + head_point.y * head_point.y + head_point.z * head_point.z);
	};

	template<class T>
	Point<T> normalize2D(const Point<T> & head_point)
	{
		return head_point / sqrt(head_point.x * head_point.x + head_point.y * head_point.y);
	}

	template<class T>
	vector<Point<T>> normalize(const vector<Point<T>> & head_points)
	{
		int number_of_points = head_points.size();
		vector<Point<T>> result_points(number_of_points);
		for(int point_index=0; point_index<number_of_points; point_index++)
		{
			const Point<T> & head_point = head_points[point_index];
			result_points[point_index] = head_point/sqrt(head_point.x * head_point.x + head_point.y * head_point.y + head_point.z * head_point.z);
		}
		return 	result_points;
	};


	template<class T>
	Point<T> average(vector<Point<T>> & points)
	{
		Point<T> point;
		point.x = 0;
		point.y = 0;
		point.z = 0;
		
		for (int point_index = 0; point_index < points.size(); point_index++)
		{
			point = point + points[point_index];
		}
		point = point / T(points.size());
		return point;
	};

	template<class T> 
	Point<T> calculate_projected_endpoint_on_rightmost_boundary(const Point<T> & tail_point, const Point<T> & head_point, const T & distance_to_head_point)
	{
		Point<T> tail_to_head_direction = head_point - tail_point;
		Point<T> perpendicular_direction;
		perpendicular_direction.x = -tail_to_head_direction.y;
		perpendicular_direction.y = tail_to_head_direction.x;
		perpendicular_direction = perpendicular_direction / abs(perpendicular_direction);

		Point<T> boundary_Point_1 = head_point + distance_to_head_point * perpendicular_direction;
		Point<T> boundary_Point_2 = head_point - distance_to_head_point * perpendicular_direction;

		Point<T> head_to_boundary_direction = boundary_Point_1 - head_point;

		if (tail_to_head_direction.x*head_to_boundary_direction.y - tail_to_head_direction.y*head_to_boundary_direction.x < 0)
		{
			return boundary_Point_1;
		}
		else
		{
			return boundary_Point_2;
		}
	};

	template<class T>
	vector<Point<T>> calculate_projected_endpoints_on_rightmost_boundary(const vector<Point<T>> & reference_points, const T & distance_to_head_point)
	{
		int nubmer_of_points = reference_points.size();
		vector<Point<T>> result_points(nubmer_of_points);
		for (int point_index = 0; point_index < nubmer_of_points-1; point_index++)
		{
			result_points[point_index + 1] = calculate_projected_endpoint_on_rightmost_boundary(reference_points[point_index], reference_points[point_index + 1], distance_to_head_point);
		}	 
		result_points[0] = result_points[1] + (reference_points[0] - reference_points[1]);
		return result_points;
	};

	template<class T>
	vector<Point<T>> calculate_projected_endpoints_from_reference_points(const vector<Point<T>> & reference_points, const vector<Point<T>> & direction_points, const T & distance_to_head_point)
	{
		int nubmer_of_points = reference_points.size();
		vector<Point<T>> result_points(nubmer_of_points);
		for (int point_index = 0; point_index < nubmer_of_points; point_index++)
		{
			Point<T> calculated_direction = direction_points[point_index] / abs(direction_points[point_index]) * distance_to_head_point;
			result_points[point_index] = reference_points[point_index] + calculated_direction;
		}
		
		return result_points;
	};

	template<class T>
	Point<T> convert_longitudinal_postion_to_points(const Point<T> start_point, const vector<Point<T>> & referece_ponit_array, const T & position_from_start)
	{
		Point<T> Point3D_result;
		int next_reference_Point3D_index_from_Point3D_result = 0;
		vector<Point<T> > direction_between_two_Point3D_array;
		float cumulative_segment_length = 0;
		int	 Point3D_index = 0;
		for (Point3D_index = 0; Point3D_index < referece_ponit_array.size() - 1; Point3D_index++)
		{
			Point<T> direction_between_two_Point3D = referece_ponit_array[Point3D_index + 1] - referece_ponit_array[Point3D_index];
			T direction_length = abs(direction_between_two_Point3D);

			if (cumulative_segment_length + direction_length < position_from_start)
			{
				direction_between_two_Point3D_array.push_back(direction_between_two_Point3D);
			}
			else
			{
				direction_between_two_Point3D = direction_between_two_Point3D/ direction_length *(position_from_start - cumulative_segment_length);
				direction_between_two_Point3D_array.push_back(direction_between_two_Point3D);
				break;
			}
			cumulative_segment_length += direction_length;
		}
		next_reference_Point3D_index_from_Point3D_result = Point3D_index + 1;

		Point3D_result = start_point;
		for (int Point3D_index = 0; Point3D_index < direction_between_two_Point3D_array.size(); Point3D_index++)
		{
			Point3D_result = Point3D_result + direction_between_two_Point3D_array[Point3D_index];
		}
		return Point3D_result;
	}

	template<class T>
	int find_nearest_next_point(const vector<Point<T>> & point_array, const T & position_from_start)
	{
		int next_reference_Point3D_index_from_Point3D_result = 0;
		float cumulative_segment_length = 0;
		int Point3D_index = 0;
		for ( Point3D_index = 0; Point3D_index < point_array.size() - 1; Point3D_index++)
		{
			Point<T> direction_between_two_Point3D = point_array[Point3D_index + 1] - point_array[Point3D_index];
			T direction_length = abs(direction_between_two_Point3D);
			cumulative_segment_length += direction_length;
			if (cumulative_segment_length > position_from_start)
				break;
		}
		next_reference_Point3D_index_from_Point3D_result = Point3D_index +1;
		return next_reference_Point3D_index_from_Point3D_result;
	}

	template<class T>
	int find_nearest_next_point_2D(const vector<Point<T>> & point_array, const T & position_from_start)
	{
		int next_reference_Point3D_index_from_Point3D_result = 0;
		float cumulative_segment_length = 0;
		int Point3D_index = 0;
		for (Point3D_index = 0; Point3D_index < point_array.size() - 1; Point3D_index++)
		{
			Point<T> direction_between_two_Point3D = point_array[Point3D_index + 1] - point_array[Point3D_index];
			T direction_length = abs2D(direction_between_two_Point3D);
			cumulative_segment_length += direction_length;
			if (cumulative_segment_length > position_from_start)
				break;
		}
		next_reference_Point3D_index_from_Point3D_result = Point3D_index + 1;
		return next_reference_Point3D_index_from_Point3D_result;
	}
}