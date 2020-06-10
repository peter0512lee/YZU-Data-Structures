#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main()
{
	int arr[4096];
	
	//∕﹚璶块碭计
	printf("Input size:\n");
	int size = 0;
	scanf("%d", &size);

	printf("Test numbers from the standard input:\n");

	//块计
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);		
	}

	//狦ヘ玡计ゑ计碞ユ传
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arr[i + 1])
			arr[i + 1] = arr[i];
	}

	//程计
	printf("\noutput:\n%d\n\n", arr[size - 1]);

	system("pause");
	return 0;
}