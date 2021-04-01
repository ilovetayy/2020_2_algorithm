//2018008804_¿Ã±‘øµ_12838
#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void heapify(int* arr, int size, int here)//max heap
{
	int left = here * 2 + 1;
	int right = here * 2 + 2;
	int max = here;
	if ( left < size && arr[left] > arr[max] ) max = left;
	if ( right < size && arr[right] > arr[max] ) max = right;

	if ( max != here )
	{
		swap(&arr[here], &arr[max]);
		heapify(arr, size, max);
	}
}
void buildHeap(int* arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; i-- )
	{
		heapify(arr, size, i);
	}
}
void extractMax(int* a, int* size)
{
	cout << a[0] << " ";
	swap(&a[0], &a[*size - 1]);
	(*size)--;
}
int main(void)
{
	int n, k, element, i;

	cin >> n;
	if ( n < 1 || n > 100000 ) return 0;

	cin >> k;
	if ( k < 1 || k > 30 ) return 0;

	
	int* arr = new int[n];

	for ( i = 0; i < n; i++ )
	{
		cin >> element;
		arr[i] = element;
	}
	
	buildHeap(arr, n);

	for ( i = 0; i < k; i++ )
	{
		extractMax(arr, &n);
		heapify(arr, n, 0);
	}
	cout << "\n";

	for ( i = 0; i < n; i++ )
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	
	delete[] arr;
	return 0;
}