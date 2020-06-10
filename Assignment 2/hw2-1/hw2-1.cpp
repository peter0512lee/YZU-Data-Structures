#include <iostream> 

using namespace std;

#define MAX 80

int priority(char op) // 運算子優先權
{
	switch (op)
	{
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	default:            return 0;
	}
}

void inToPostfix(char* infix, char* postfix)// 中序轉後序
{
	char stack[MAX] = { '\0' };
	int i, j, top;
	for (i = 0, j = 0, top = 0; infix[i] != '\0'; i++)
		switch (infix[i])
		{
		case '(':              // 運算子堆疊 
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
			stack[++top] = infix[i]; // 存入堆疊 
			break;
		case ')':
			while (stack[top] != '(') // 遇 ) 輸出至 ( 
			{
				postfix[j++] = stack[top--];
			}
			top--;  // 不輸出 ( 
			break;
		default:  // 運算元直接輸出 
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
