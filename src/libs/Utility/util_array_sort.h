#pragma once
#include <vector>
#include <numeric>
using namespace std;
namespace utility_function
{
	template <typename T>
	vector<size_t> sort_indexes(const vector<T> &v)
	{
		vector<size_t> idx(v.size());
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&v](size_t i1, size_t i2) {return v[i1] < v[i2]; });
		return idx;
	}
}