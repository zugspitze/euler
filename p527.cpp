#include <iostream>
#include <stdint.h>
#include <map>
#include <stdio.h>
using namespace::std;

uint64_t N = 10000000000ULL;

long double calculate_avg_bin_steps(uint64_t n, map<uint64_t, long double>& m)
{
	if (m.find(n) != m.end())
		return m[n];
	
	if (n == 1) {m[1] = 1.0; return 1.0;}
	if (n == 2) {m[2] = 1.5; return 1.5;}

	uint64_t left_size = (n - 1) / 2;
	uint64_t right_size = (n / 2);

	long double left_half = calculate_avg_bin_steps(left_size, m);
	long double right_half = calculate_avg_bin_steps(right_size, m);

	long double tmp = 1.0 + (left_size * left_half + right_size * right_half) / ((long double)(n));
	m[n] = tmp;
	return tmp;
}

int main ()
{
	map<uint64_t, long double> m;
	long double bin_ans = calculate_avg_bin_steps(N, m);

	long double sn_1 = 1.0;
	long double sn = 0.0;
	for (uint64_t i = 2; i <= N; ++i)
	{
		long double di = (double)i;
		sn = (2 * di - 1.0) + (di + 1.0) * sn_1;
		sn = sn / di;
		sn_1 = sn;
	}

	long double tn = sn / ((double)(N));
	long double ans = tn - bin_ans;
	printf("%.8f\n", (double)ans);
}
