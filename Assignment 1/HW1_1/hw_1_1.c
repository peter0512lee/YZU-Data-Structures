#include <stdio.h>
#include <stdlib.h>

int main() {

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

  //���ɮפ����ƦrŪ��Array�̭�
	for (int i = 0; i < n; i++)
	{
		fscanf(sumFloating, "%g,", &numberArray[i]);
	}
  //�L�X�C��Array�����Ʀr
	for (int i = 0; i < n; i++)
	{
		printf("Number[%d] : %g\n\n", i, numberArray[i]);
	}
  //�ۥ[
	for (int i = 0; i < n; i++)
	{
		sumFloat += numberArray[i];
	}

	printf("SumFloating is: %g\n\n", sumFloat);
  //close FILE
	fclose(sumFloating);

	return 0;
}

