#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, m, i, p1 = 0, p2 = 0, cnt = 0;

	scanf("%d", &n);
	scanf("%d", &m);
	if ( n < 1 || n > 100000 || m < 1 || m > 100000 ) return 0;

	vector<int> A(n);
	vector<int> B(m);

	for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
	for ( i = 0; i < m; i++ )scanf("%d", &B[i]);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	while ( p1 < n && p2 < m )
	{
		if ( A[p1] < B[p2] )p1++;
		else if ( A[p1] > B[p2] )p2++;
		else
		{
			p1++, p2++, cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
