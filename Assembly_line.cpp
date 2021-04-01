#include <iostream>
using namespace std;


int assemblyLine(int n, int e1, int e2, int x1, int x2, int a1[], int a2[], int t1[], int t2[])
{
	int f, l, i, j, k;

	int* f1 = new int[n + 1];
	int* f2 = new int[n + 1];
	int* l1 = new int[n + 1];
	int* l2 = new int[n + 1];

	int* lines = new int[n];
	int* stations = new int[n];

	f1[1] = e1 + a1[1];
	f2[1] = e2 + a2[1];

	for ( j = 2; j <= n; j++ )
	{
		if ( f1[j - 1] <= f2[j - 1] + t2[j - 1] )
		{
			f1[j] = f1[j - 1] + a1[j];
			l1[j] = 1;
		}
		else
		{
			f1[j] = f2[j - 1] + t2[j - 1] + a1[j];
			l1[j] = 2;
		}
		if ( f2[j - 1] <= f1[j - 1] + t1[j - 1] )
		{
			f2[j] = f2[j - 1] + a2[j];
			l2[j] = 2;
		}
		else
		{
			f2[j] = f1[j - 1] + t1[j - 1] + a2[j];
			l2[j] = 1;
		}
	}

	if ( f1[n] + x1 <= f2[n] + x2 )
	{
		f = f1[n] + x1;
		l = 1;
	}
	else
	{
		f = f2[n] + x2;
		l = 2;
	}

	cout << f << '\n';

	i = l;
	k = 1;
	lines[0] = i;
	stations[0] = n;
	for ( j = n; j >= 2; j-- )
	{
		if ( i == 1 ) i = l1[j];
		else i = l2[j];

		lines[k] = i;
		stations[k] = j - 1;
		k++;
	}

	for ( i = n - 1; i >= 0; i-- )
	{
		cout << lines[i] << " " << stations[i]<< '\n';
	}

	delete[] f1, f2, l1, l2, lines, stations;
	return 0;
}
int main()
{
	int n, e1, e2, x1, x2, input, i;

	cin >> n;
	if ( n < 1 || n > 100 ) return 0;

	cin >> e1 >> e2;
	if ( e1 < 1 || e1 > 100 || e2 < 1 || e2 > 100) return 0;

	cin >> x1 >> x2;

	int* a1 = new int[n + 1];
	int* a2 = new int[n + 1];
	int* t1 = new int[n];
	int* t2 = new int[n];

	for ( i = 1; i <= n; i++ )
	{
		cin >> input;
		if ( input < 1 || input > 100 ) return 0;
		a1[i] = input;
	}
	for ( i = 1; i <= n; i++ )
	{
		cin >> input;
		if ( input < 1 || input > 100 ) return 0;
		a2[i] = input;
	}
	for ( i = 1; i < n; i++ )
	{
		cin >> input;
		if ( input < 1 || input > 100 ) return 0;
		t1[i] = input;
	}
	for ( i = 1; i < n; i++ )
	{
		cin >> input;
		if ( input < 1 || input > 100 ) return 0;
		t2[i] = input;
	}

	assemblyLine(n, e1, e2, x1, x2, a1, a2, t1, t2);

	delete[] a1, a2, t1, t2;
	return 0;
}
