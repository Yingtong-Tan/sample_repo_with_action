#pragma once
#include <vector>
#include <algorithm>

using namespace std;

namespace utility_function
{
	//general
	vector<int> convert_original_binary(long long decimal, int num_digit);
	void convert_inverse_binary(vector<int> & original_binary_array);
	void convert_complementary_binary(vector<int> & inverse_binary_array);
	long long convert_from_base_array(vector<int> & array, long long base, bool sign = false);
}