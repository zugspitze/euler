#include <iostream>
#include <vector>
#include <stdint.h>
using namespace::std;

const int p = 1000;

int main ()
{
	vector<int> v;
	v.push_back(1);

	for (int i = 1; i <= p; ++i)
	{
		int carry = 0;
		for (int j = 0; j < v.size(); ++j)
		{
			int tmp = (v[j] << 1) + carry;
			v[j] = tmp % 10;
			carry = tmp / 10;
		}

		while (carry)
		{
			v.push_back(carry % 10);
			carry /= 10;
		}
	}

	uint64_t sum = 0;
	for (int j = 0; j < v.size(); ++j)
		sum += v[j];

	cout << sum << endl;
	return 0;
}
