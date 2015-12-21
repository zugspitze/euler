#include <iostream>
#include <vector>
using namespace::std;

int main ()
{
	vector<vector<int> > v(20, vector<int>(20, 0));
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 20; ++j)
			cin >> v[i][j];

	int prod = 1;
	int max = 1;
	// up/down
	for (int i = 0; i < 17; ++i)
	{
		for (int j = 0;  j < 20; ++j)
		{
			prod = 1;
			for (int k = 0; k < 4; ++k)
				prod *= v[i + k][j];

			max = (max < prod) ? prod : max;
		}
	}

	// left/right
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 17; ++j)
		{
			prod = 1;
			for (int k = 0; k < 4; ++k)
				prod *= v[i][j + k];

			max = (max < prod) ? prod : max;
		}
	}

	// diagonal
	for (int i = 0; i < 17; ++i)
	{
		for (int j = 0; j < 17; ++j)
		{
			prod = 1;
			for (int k = 0; k < 4; ++k)
				prod *= v[i + k][j + k];

			max = (max < prod) ? prod : max;
		}
	}

	cout << max << endl;
}
