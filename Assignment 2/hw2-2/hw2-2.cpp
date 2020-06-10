#include<iostream>

using namespace std;

//------------------------------------Stack---------------------------------//
class StackArray
{
public:
	StackArray() :top(-1), capacity(1) {
		stack = new int[capacity];
	}

	~StackArray() {
		delete[] stack;
	}

	void Push(int x) {

		if (top == capacity - 1) {
			DoubleCapacity();
		}
		stack[++top] = x;
	}

	void Pop() {

		if (IsEmpty()) {
			cout << "Stack is empty." << endl;
			return;
		}
		top--;
	}

	bool IsEmpty() {

		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
		
	}

	int Top() {

		if (IsEmpty()) {
			cout << "Stack is empty." << endl;
			return -1;
		}
		return stack[top];
	}

	int getSize() {

		return top + 1;
	}

	int getElement(int i) {

		return stack[i];
	}

private:
	int top;
	int capacity;
	int *stack;

	void DoubleCapacity() {

		capacity *= 2;
		int *newStack = new int[capacity];

		for (int i = 0; i < capacity / 2; i++) {
			newStack[i] = stack[i];
		}

		delete[] stack;
		stack = newStack;
	}
};

//------------------------------------Stack---------------------------------//

int main() 
{
	int num;
	StackArray s1, s2;

	cout << "Input elements (-1 to end):" << endl;
	
	while (cin >> num && num != -1)
	{
		s1.Push(num);		
	}

	cout << endl;

	s2.Push(s1.getElement(0));

	for (size_t i = 1; i < s1.getSize(); i++)
	{
		
		if (s2.IsEmpty())
		{
			s2.Push(s1.getElement(i));
			continue;
		}

		while (s2.IsEmpty() == false && s2.Top() < s1.getElement(i))
		{
			cout << s2.Top() << " -> " << s1.getElement(i) << ", ";
			s2.Pop();
		}

		s2.Push(s1.getElement(i));
	}

	while (s2.IsEmpty() == false)
	{
		cout << s2.Top() << " -> " << -1 << ", ";
		s2.Pop();
	}

	cout << endl;
	
	return 0;
}