#include "util_bit_computation.h"

vector<int> utility_function::convert_original_binary(long long decimal, int num_digit)
{
	bool negative = decimal < 0;
	decimal = abs(decimal);
	vector<int> binary_digit_array;
	while (decimal != 0)
	{
		binary_digit_array.push_back(decimal % 2);
		decimal = decimal / 2;
	}

	int start_index = max(0, int(num_digit - binary_digit_array.size()));
	//int start_index = max(0, num_digit - binary_digit_array.size());
	int new_num_digit = start_index + binary_digit_array.size();
	vector<int> binary_digit_array_new(new_num_digit, 0);
	for (int i = 0; i < binary_digit_array.size(); i++)
	{
		binary_digit_array_new[new_num_digit - 1 - i] = binary_digit_array[i];
	}
	if (negative)
	{
		binary_digit_array_new[0] = 1;
	}
	return 	binary_digit_array_new;
}

void utility_function::convert_inverse_binary(vector<int>& binary_array)
{
	if (binary_array[0] > 0)
	{
		for (int i = 1; i < binary_array.size(); i++)
		{
			binary_array[i] = (binary_array[i] + 1) % 2;
		}
	}
}

void utility_function::convert_complementary_binary(vector<int>& binary_array)
{
	if (binary_array[0] > 0)
	{
		bool carry = true;
		binary_array.back() = (binary_array.back() + 1) % 2;
		carry = binary_array.back() == 0;
		for (int i = binary_array.size() - 1; i > 1; i--)
		{
			if (carry)
			{
				binary_array[i] = (binary_array[i] + 1) % 2;
				carry = binary_array[i] == 0;
			}
			else
			{
				return;
			}
		}
	}
}

long long utility_function::convert_from_base_array(vector<int>& binary_array, long long base, bool sign)
{
	long long decimal = 0;
	long long base_initial = 1;

	for (int i = binary_array.size(); i > 1; i--)
	{
		decimal += binary_array[i - 1] * base_initial;
		base_initial = base * base_initial;
	}

	if (sign)
	{
		decimal = (-2 * binary_array.front() + 1)*decimal;
	}
	else
	{
		decimal += binary_array.front() * base_initial;
	}
	return decimal;
}
