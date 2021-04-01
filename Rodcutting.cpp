//2018008804_¿Ã±‘øµ_12838
#include <iostream>
using namespace std;

int numRods;
int cutRod(int price[], int rods[], int n)
{
	int* res = new int[n + 1];
	int* lastRod = new int[n + 1];
	res[0] = 0;
	int i, j;

	for ( i = 1; i <= n; i++ )
	{
		int max_val = -2147483648;
		int best_len = -1;
		for ( j = 0; j < i; j++ )
		{
			if ( max_val < price[j] + res[i - j - 1] )
			{
				max_val = price[j] + res[i - j - 1];
				best_len = j;
			}
		}
		res[i] = max_val;
		lastRod[i] = best_len + 1;
	}

	i = n;
	j = 0;
	while ( i > 0 )
	{
		rods[j++] = lastRod[i];
		i -= lastRod[i];
	}

	numRods = j;

	return res[n];
}


int main(void)
{
	int len, p, i;

	cin >> len;
	if ( len < 1 || len > 100 ) return 0;

	int* p_arr = new int[len];
	int* rods = new int[len + 1];

	for ( i = 0; i < len; i++ )
	{
		cin >> p;
		if ( i > 1 && p_arr[i - 1] > p ) return 0;
		p_arr[i] = p;
	}
	
	cout << cutRod(p_arr, rods, len) << '\n';
	cout << rods[0];
	for ( i = 1; i < numRods; i++ )
		cout << " " << rods[i];

	delete[] p_arr;

	return 0;
}