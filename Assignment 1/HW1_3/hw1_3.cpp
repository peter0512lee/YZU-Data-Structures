#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main()
{
	int arr[4096];
	
	//�M�w�n��J�X�ӼƦr
	printf("Input size:\n");
	int size = 0;
	scanf("%d", &size);

	printf("Test numbers from the standard input:\n");

	//��J�Ʀr
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);		
	}

	//�p�G�ثe���Ʀr��U�@�ӼƦr�j�N�洫
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arr[i + 1])
			arr[i + 1] = arr[i];
	}

	//�L�X�̫�@�ӼƦr
	printf("\noutput:\n%d\n\n", arr[size - 1]);

	system("pause");
	return 0;
}