#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j, key;
	int* arr;

	scanf("%d", &n);
	if ( n < 1 || n > 30000 )
	{
		return 0;
	}

	arr = (int*)malloc(sizeof(int)*n);

	for ( i = 0; i < n; i++ )
	{
		scanf("%d", &arr[i]);
	}

	for ( i = 0; i < n - 1; i++ )
	{
		key = arr[i + 1];
		for ( j = i; j > -1; j-- )
		{
			if ( arr[j] < key )
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = key;
	}

	for ( i = 0; i < n; i++ )
	{
		printf("%d\n", arr[i]);
	}

	free(arr);
	return 0;
}
