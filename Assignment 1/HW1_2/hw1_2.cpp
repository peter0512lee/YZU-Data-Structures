#include<iostream>
#include<string>

using namespace std;

template<class T>
T Bigger(T num1, T num2) {

	if (num1 > num2)
	{
		return num1;
	}
	else if (num1 < num2)
	{
		return num2;
	}
	else
	{
		return num1;
	}
}

int main() {

	string input1, input2;

	cout << "Input first number, float or char: ";
	getline(cin, input1);
	cout << "Input second number, float or char: ";
	getline(cin, input2);

	//如果第一個字元不是0-9，就直接進入template char
	if (input1[0] > 58 || input1[0] < 47 && input2[0] > 58 || input2[0] < 47)
	{
		cout << Bigger(input1[0], input2[0]) << endl;
	}
	else
	{
		cout << Bigger(input1, input2) << endl;
	}

	system("pause");
	return 0;
}