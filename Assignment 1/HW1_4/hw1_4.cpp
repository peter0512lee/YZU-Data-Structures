#include <stdlib.h>
#include <stdio.h>

#pragma warning(disable:4996)

int Pascal(int *ptr, int row, int col) {

	int r = row, c = col;

	//�p�Gcol = 1 �� row = col �N�^��1
	if (c == 1 || r == c) 
	{
		return 1;
	}
	else //�Q�λ��j�I�s�ۤv�b�̧ǥ[�^�ӱo�쵪��
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

		//�إ߰ʺA�}�C size = row * col
		int *ptr = (int*)malloc(row * col * sizeof(int));
		if (row == -1)
			break;
		printf("%d\n", Pascal(ptr, row, col));
		free(ptr);
	}	

	system("pause");
	return 0;
}