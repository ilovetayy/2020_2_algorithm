//2018008804_LeeGyuYeong_12838
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int sum = 0;

typedef struct Node
{
	char data;
	int freq;
	Node *left, *right;
	Node(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
}Node;
typedef struct compare
{
	bool operator()(Node* l, Node* r)
	{
		return (l->freq > r->freq);
	}
}compare;
void getStrings(Node* root, string str)
{
	if ( !root ) return;
	
	if ( root->data != '@' )
		sum += root->freq * str.size();

	getStrings(root->left, str + "0");
	getStrings(root->right, str + "1");
}
void HuffmanCodes(char data[], int freq[], int size)
{
	struct Node *left, *right, *top;

	priority_queue<Node*, vector<Node*>, compare> minHeap;

	for ( int i = 0; i < size; ++i )
		minHeap.push(new Node(data[i], freq[i]));

	while ( minHeap.size() != 1 )
	{
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new Node('@', left->freq + right->freq);
		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	getStrings(minHeap.top(), "");

	cout << sum << '\n';
}
int main(void)
{
	int num_char, i, num, total;
	string input;
	
	cin >> num_char;
	if ( num_char < 1 || num_char > 30000 ) return 0;

	char* chars = new char[num_char];
	int* nums = new int[num_char];

	for ( i = 0; i < num_char; i++ )
	{
		cin >> input >> num;
		chars[i] = input[0];
		nums[i] = num;
	}

	cin >> total;

	if ( num_char == (num_char & -num_char) )
		cout << total * (int)log2(num_char) << '\n';
	else
		cout << total * ((int)log2(num_char) + 1) << '\n';

	HuffmanCodes(chars, nums, num_char);

	delete[] chars;
	delete[] nums;

	return 0;
}