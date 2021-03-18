#pragma once
#include "util_include_all.h"

namespace utility_function
{
	template <class T>
	T calculate_mean(const vector<T>& data_array)
	{
		T mean;
		int array_size = int(data_array.size());
		if (array_size>1)
		{
			mean = 0.0f;
			for (int i = 0; i<array_size; i++)
			{
				mean += data_array[i];
			}
			mean = float(mean / (float(array_size)));
		}
		else
		{
			if (array_size == 1)
			{
				mean = data_array[0];
			}
			else
			{
				mean = 0.0f;
			}
		}
		return mean;
	};

	template <class T>
	T calculate_mean_standard_deviation( const vector<T>& data_array)
	{
		T standard_deviation;
		int array_size = int(data_array.size());
		if (array_size>1)
		{
			mean = 0.0f;
			for (int i = 0; i<array_size; i++)
			{
				mean += data_array[i];
			}
			mean = T(mean / (T(array_size)));
			standard_deviation = 0.0f;
			for (int i = 0; i<array_size; i++)
			{
				standard_deviation += (data_array[i] - mean)*(data_array[i] - mean);
			}

			standard_deviation = T(sqrt(double(standard_deviation / T(array_size - 1))));
		}
		else
		{
			if (array_size == 1)
			{
				mean = data_array[0];
				standard_deviation = 0.0f;
			}
			else
			{
				mean = 0.0f;
				standard_deviation = 0.0f;
			}
		}
		return T;
	};
	
	template <class T>
	T calculate_rmse( const vector<T> & input_vector, const vector<T> & output_vector)
	{
		T rmse = 0.0;
		if(output_vector.size() == input_vector.size())
		{ 
			int array_size = output_vector.size();
			if(array_size>0)
			{ 
				vector<T> difference_square_vector(array_size, 0);
				for (int i = 0; i < array_size; i++)
				{
					difference_square_vector[i] = (input_vector[i] - output_vector[i])*(input_vector[i] - output_vector[i]);
				}
				rmse = calculate_sum(difference_square_vector);
				rmse = rmse / array_size;
			}
		}
		else
		{
			cout << "Error: the length of input and output vector are different" << endl;
		}
		return rmse;
	}

	template <class T>
	T calculate_sum(const vector<T> & data_array)
	{
		T sum = 0.0;
		int array_size = data_array.size();
		for (int i = 0; i < array_size; i++)
		{
			sum = sum + data_array[i];
		}
		return sum;
	}

	template <class T>
	void construct_uniform_choice_set_cdf_array(vector<T>& cdf_array)
	{
		int choice_set_size = (int)cdf_array.size();
		if (choice_set_size>0)
		{
			T choice_probability = 1.0 / T(choice_set_size);
			for (int ia = 0;ia<choice_set_size;ia++)
			{
				if (ia == 0)
				{
					cdf_array[ia] = choice_probability;
				}
				else
				{
					if (ia == choice_set_size - 1)
					{
						cdf_array[ia] = 1.0;
					}
					else
					{
						cdf_array[ia] = cdf_array[ia - 1] + choice_probability;
					}
				}
			}
		}
	};

	template <class T>
	int find_alternative(const T r1, const vector<T>& cdf_array)
	{
		int choice_set_size = int(cdf_array.size());
		int chosen_alternative = -1;
		if (choice_set_size>1)
		{
			for (int ia = 0;ia<choice_set_size;ia++)
			{
				if (r1 <= cdf_array[ia])
				{
					chosen_alternative = ia;
					break;
				}
			}
		}
		else
		{
			chosen_alternative = 0;
		}
		return chosen_alternative;
	};

	template <class T>
	int choice_model(vector<int> & index_array, vector<T> & cdf_array, T r1) 
	{
		int chosen_alternative = find_alternative(r1, cdf_array);
		int origin_activity_location_index = index_array[chosen_alternative];
		return origin_activity_location_index;
	};

}