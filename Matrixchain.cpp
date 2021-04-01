//2018008804_¿Ã±‘øµ_12838
#include <iostream>
using namespace std;

void printParens(int i, int j, int** bracket, int& name)
{
	if ( i == j )
	{
		cout << name++ << " ";
	}
	else
	{
		cout << "( ";
		printParens(i, bracket[i][j], bracket, name);
		printParens(bracket[i][j] + 1, j, bracket, name);
		cout << ") ";
	}
}
void matrixChain(int p[], int n)
{
	int i, k, L, name;
	
	int** m = new int*[n+1];
	int** bracket = new int*[n];
	for ( i = 1; i <= n; i++ )
	{
		m[i] = new int[n+1];
	}
	for ( i = 1; i < n; i++ )
	{
		bracket[i] = new int[n + 1];
	}

	for ( i = 1; i <= n; i++ )
		m[i][i] = 0;

	for ( L = 2; L <= n; L++ )
	{
		for ( i = 1; i <= n - L + 1; i++ )
		{
			int j = i + L - 1;
			m[i][j] = 2147483647;
			for ( k = i; k <= j - 1; k++ )
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if ( q < m[i][j] )
				{
					m[i][j] = q;
					bracket[i][j] = k;
				}
			}
		}
	}
	
	name = 1;

	cout << m[1][n] << '\n';

	printParens(1, n, (int**)bracket, name);

	for ( i = 0; i < n; i++ )
		delete[] m[i], bracket[i];
	delete[] m, bracket;
}
int main()
{
	int n, p, i;

	cin >> n;
	if ( n < 1 || n > 100 ) return 0;

	int* p_arr = new int[n + 1];
	for ( i = 0; i <= n; i++ )
	{
		cin >> p;
		p_arr[i] = p;
	}

	matrixChain(p_arr, n);

	delete[] p_arr;

	return 0;
}