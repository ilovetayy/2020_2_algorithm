//2018008804_¿Ã±‘øµ_12838
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void rangeSearch(vector<int> v, int start, int end)
{
	int i, j;

	i = find(v.begin(), v.end(), start) - v.begin();
	j = find(v.begin(), v.end(), end) - v.begin();

	if ( i != v.size() && j != v.size() )
	{
		printf("%d", j - i + 1);
	}
	else if ( i == v.size() && j != v.size())//i not contain
	{
		i = upper_bound(v.begin(), v.end(), start) - v.begin();
		printf("%d", j - i + 1);
	}
	else if (i != v.size() && j == v.size() )//j not contain
	{
		j = upper_bound(v.begin(), v.end(), end) - v.begin();
		printf("%d", j - i);
	}
	else // i,j not contain
	{
		i = upper_bound(v.begin(), v.end(), start) - v.begin();
		j = upper_bound(v.begin(), v.end(), end) - v.begin();
		printf("%d", j - i);
	}
}
int main(void)
{
	int n, m, k, i, element;

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &k);
	if ( n < 1 || n>100000 || m < 1 || m>100000 || k < 1 || k>100000 ) return 0;

	vector<int> A(k), B(k);
	for ( i = 0; i < k; i++ )
	{
		scanf("%d", &A[i]);
		scanf("%d", &B[i]);
	}

	vector<int> keys(n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d", &element);
		if ( element > m ) return 0;
		keys[i] = element;
	}
	sort(keys.begin(), keys.end());

	for ( i = 0; i < k; i++ )
	{
		rangeSearch(keys, A[i], B[i]);
		printf("\n");
	}

	return 0;
}