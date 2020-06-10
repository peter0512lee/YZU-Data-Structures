#include <stdlib.h>
#include <stdio.h>

#pragma warning(disable:4996)

int Pascal(int *ptr, int row, int col) {

	int r = row, c = col;

	//如果col = 1 或 row = col 就回傳1
	if (c == 1 || r == c) 
	{
		return 1;
	}
	else //利用遞迴呼叫自己在依序加回來得到答案
	{
		return Pascal(ptr, r - 1, c - 1) + Pascal(ptr, r - 1, c);
	}

}

int main() {
	
	while (true) {
		int row = 0, col = 0;
		printf("*(-1, -1 to end)*\n");
		printf("P(row, col) = ");
		scanf("%d %d", &row, &col);

		//建立動態陣列 size = row * col
		int *ptr = (int*)malloc(row * col * sizeof(int));
		if (row == -1)
			break;
		printf("%d\n", Pascal(ptr, row, col));
		free(ptr);
	}	

	system("pause");
	return 0;
}