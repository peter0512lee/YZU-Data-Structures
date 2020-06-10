#include <iostream> 
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item
{
	int value, weight;

	// Constructor 
	Item() {}
	Item(int value, int weight) : value(value), weight(weight) {}
};

void heapify(struct Item arr[], int n, int i) 
{
	
	int smallest = i; // Initialize smalles as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is smaller than root 
	if (l < n && arr[l].value / arr[l].weight < arr[smallest].value / arr[smallest].weight)
		smallest = l;

	// If right child is smaller than smallest so far 
	if (r < n && arr[r].value / arr[r].weight < arr[smallest].value / arr[smallest].weight)
		smallest = r;

	// If smallest is not root 
	if (smallest != i)
	{
		swap(arr[i], arr[smallest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, smallest);
	}
}

void min_heap_sort(struct Item arr[], int len) {
	
	for (int i = len / 2 - 1; i >= 0; i--)
		heapify(arr, len, i);
	
	for (int i = len - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
 
double fractionalKnapsack(int W, struct Item arr[], int n)
{
	//    sorting Item on basis of ratio 	
	min_heap_sort(arr, n);	

	int curWeight = 0;  // Current weight in knapsack 
	double finalvalue = 0.0; // Result (value in Knapsack) 

							 // Looping through all Items 
	for (int i = 0; i < n; i++)
	{
		// If adding Item won't overflow, add it completely 
		if (curWeight + arr[i].weight <= W)
		{
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}

		// If we can't add current Item, add fractional part of it 
		else
		{
			int remain = W - curWeight;
			finalvalue += arr[i].value * ((double)remain / arr[i].weight);
			break;
		}
	}

	// Returning final value 
	return finalvalue;
}

int main()
{

	int N, W;
	cin >> N >> W;

	Item *ptr = new Item[N];

	for (size_t i = 0; i < N; i++)
	{
		cin >> ptr[i].value >> ptr[i].weight;
	}

	cout << "Maximum value we can obtain = " << fixed << setprecision(2) << fractionalKnapsack(W, ptr, N) << endl;

	delete[] ptr;
	
	return 0;
}