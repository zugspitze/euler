#include <iostream>
#include <vector>
#include <stdint.h>
using namespace::std;

const int N = 100;

int main ()
{
	vector<int> v;
	v.push_back(1);
	for (int i = 1; i <= N; ++i)	
	{
		int carry = 0;
		for (int j = 0; j < v.size(); ++j)
		{
			int tmp = v[j] * i + carry;
			v[j] = tmp % 10;
			carry = tmp / 10;
		}

		while (carry)
		{
			v.push_back(carry % 10);
			carry /= 10;
		}
	}

	uint64_t sum = 0ULL;
	for (int i = 0; i < v.size(); ++i)
		sum += v[i];

	cout << sum << endl;

	return 0;
}
