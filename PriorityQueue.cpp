#include <stdio.h>
#include <vector>
using namespace std;

typedef struct
{
	vector<int> keys;
	vector<int> extracted;
}Heap;
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
Heap* createHeap()
{
	Heap* heap = new Heap;
	heap->keys = vector<int>(1);
	heap->extracted = vector<int>(1);
	return heap;
}
void heapify(Heap* h, int here)
{
	int left = here * 2;
	int right = here * 2 + 1;
	int max = here;
	if ( left < h->keys.size() && h->keys[left] > h->keys[max] ) max = left;
	if ( right < h->keys.size() && h->keys[right] >= h->keys[max] ) max = right;

	if ( max != here )
	{
		swap(h->keys[here], h->keys[max]);
		heapify(h, max);
	}
}
void insert(Heap* h, int val)
{
	h->keys.push_back(val);
	for ( int i = h->keys.size()/ 2; i > 0; i-- )
		heapify(h, i);
}
void extractMax(Heap* h)
{
	h->extracted.push_back(h->keys[1]);
	swap(h->keys[1], h->keys[h->keys.size()-1]);
	h->keys.pop_back();
	heapify(h, 1);
}
void heapify_bottom(Heap* h, int cur)
{
	while ( h->keys[cur] > h->keys[cur / 2] )
	{
		swap(h->keys[cur], h->keys[cur / 2]);
		cur /= 2;
		if ( cur == 1 ) break;
	}
}
void changeKey(Heap* h, int index, int val)
{
	if ( h->keys[index] == val ) return;
	h->keys[index] = val;
	for ( int i = h->keys.size() / 2; i > 0; i-- )
		heapify(h, i);
	/*
	else if ( h->keys[index] < val )//increase
	{
		h->keys[index] = val;
		heapify_bottom(h, index);
	}
	else//decrease
	{
		h->keys[index] = val;
		heapify(h, index);
	}
	*/
}
int main(void)
{
	int cmd, key, index, i;

	Heap* heap = createHeap();

	while ( 1 )
	{
		scanf("%d", &cmd);

		if ( cmd == 0 )
		{
			for ( i = 1; i < heap->extracted.size(); i++ )
				printf("%d ", heap->extracted[i]);
			printf("\n");
			for ( i = 1; i < heap->keys.size(); i++ )
				printf("%d ", heap->keys[i]);
			printf("\n");
			return 0;
		}
		else if ( cmd == 1 )
		{
			scanf("%d", &key);
			if ( key > 100000 ) continue;
			insert(heap, key);
		}
		else if ( cmd == 2 )
		{
			if ( heap->keys.size() == 1 ) continue;
			extractMax(heap);
		}
		else if ( cmd == 3 )
		{
			scanf("%d", &index);
			if ( index >= heap->keys.size() ) continue;
			scanf("%d", &key);
			if ( key > 100000 ) continue;
			changeKey(heap, index, key);
		}
		else break;
	}

	return 0;
}
