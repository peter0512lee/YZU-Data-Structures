#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(vector<int> &arr, int front, int end)
{
	int pivot = arr[end];
	int i = front - 1;
	for (int j = front; j < end; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	i++;
	swap(arr[i], arr[end]);
	return i;
}

void QuickSort(vector<int> &arr, int front, int end)
{
	if (front < end) {
		int pivot = Partition(arr, front, end);
		QuickSort(arr, front, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}

int main() 
{
		
	vector<int> arr;
	int a, index = 0;
	while (cin >> a)
	{
		arr.push_back(a);
		char ch = getchar(); 
		if (ch == '\n')
			break;
	}

	int i;
	cin >> i;

	QuickSort(arr, 0, arr.size() - 1);

	cout << arr[i - 1] << endl;
		
	return 0;
}