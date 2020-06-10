#include <iostream> 

using namespace std;

#define MAX 80

int priority(char op) // �B��l�u���v
{
	switch (op)
	{
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	default:            return 0;
	}
}

void inToPostfix(char* infix, char* postfix)// ��������
{
	char stack[MAX] = { '\0' };
	int i, j, top;
	for (i = 0, j = 0, top = 0; infix[i] != '\0'; i++)
		switch (infix[i])
		{
		case '(':              // �B��l���| 
			stack[++top] = infix[i];
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			while (priority(stack[top]) >= priority(infix[i]))
			{
				postfix[j++] = stack[top--];
			}
			stack[++top] = infix[i]; // �s�J���| 
			break;
		case ')':
			while (stack[top] != '(') // �J ) ��X�� ( 
			{
				postfix[j++] = stack[top--];
			}
			top--;  // ����X ( 
			break;
		default:  // �B�⤸������X 
			postfix[j++] = infix[i];
		}
	while (top > 0)
	{
		postfix[j++] = stack[top--];
	}
}

int main(void)
{
	char infix[MAX] = { '\0' };
	char postfix[MAX] = { '\0' };

	cout << "infix: ";
	cin >> infix;
	inToPostfix(infix, postfix);

	cout << "postfix: ";
	int i;
	for (i = 0; postfix[i] != '\0'; i++)
	{
		cout << postfix[i];
	}

	return 0;
}
