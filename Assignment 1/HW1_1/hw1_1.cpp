#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)//in order to use fopen scanf

int main(void) {

  //read FILE and open FILE
	FILE *sumFloating;
	sumFloating = fopen("SunFloating.txt", "r");

	if (sumFloating == NULL) {
		printf("Error Reading File\n");
		exit(0);
	}

	int n = 0;
	printf("Input n (from 0 to MAX_SIZE = 4096) : ");
	scanf("%d", &n);
	printf("\n");

	float numberArray[4096];
	float sumFloat = 0;

  //把檔案中的數字讀到Array裡面
	for (int i = 0; i < n; i++)
	{
		fscanf(sumFloating, "%g,", &numberArray[i]);
	}
  //印出每個Array中的數字
	for (int i = 0; i < n; i++)
	{
		printf("Number[%d] : %g\n\n", i, numberArray[i]);
	}
  //相加
	for (int i = 0; i < n; i++)
	{
		sumFloat += numberArray[i];
	}

	printf("SumFloating is: %g\n\n", sumFloat);
  //close FILE
	fclose(sumFloating);

	system("pause");
	return 0;
}
