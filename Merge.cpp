//2018008804_¿Ã±‘øµ_12838
#include <stdio.h>
#include <stdlib.h>

void merge(int n, int* a, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	int* tmp = (int*)malloc(sizeof(int)*n);
	while ( i <= mid && j <= right )
	{
		if ( a[i] >= a[j] )
		{
			tmp[k++] = a[i++];
		}
		else
		{
			tmp[k++] = a[j++];
		}
	}
	while ( i <= mid )
	{
		tmp[k++] = a[i++];
	}
	while ( j <= right )
	{
		tmp[k++] = a[j++];
	}
	for ( int l = left; l <= right; l++ )
	{
		a[l] = tmp[l];
	}

	free(tmp);
}
void mergeSort(int n, int* a, int left, int right)
{
	int mid;
	if ( left < right )
	{
		mid = (left + right) / 2;
		mergeSort(n, a, left, mid);
		mergeSort(n, a, mid + 1, right);
		merge(n, a, left, mid, right);
	}
}
int main()
{
	int n, i;
	int* arr;

	scanf("%d", &n);
	if ( n < 1 || n > 100000 )
	{
		return 0;
	}
	arr = (int*)malloc(sizeof(int)*n);

	for ( i = 0; i < n; i++ )
	{
		scanf("%d", &arr[i]);
	}

	mergeSort(n, arr, 0, n - 1);

	for ( i = 0; i < n; i++ )
	{
		printf("%d\n", arr[i]);
	}

	free(arr);
	return 0;
}