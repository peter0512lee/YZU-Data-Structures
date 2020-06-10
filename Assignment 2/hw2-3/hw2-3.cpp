#include <iostream>
#include <iomanip>

using namespace std;

int top;

typedef struct Knight {
	int row, col;
	int d;//�e������V
	int steps;
} KNIGHT;

void push(KNIGHT knight, KNIGHT *stack)
{
	stack[top] = knight;
	top++;
}

KNIGHT pop(KNIGHT *stack)
{
	top--;
	return(stack[top]);
}

//�P�_(row, col)���L�W�X�ѽL
int inChess(int row, int col, int r, int c)
{
	if (row >= 0 && row < r && col >= 0 && col < c)
		return true;
	else
		return false;
}

void output(int r, int c, int *sol)
{
	for (int x = 0; x < r; x++)
	{
		for (int y = 0; y < c; y++)
			cout << setw(3) << *(sol + c * x + y) << setw(3);
		cout << endl;
	}
}

//�M�h�q�_�I�}�l����n * n�B
int knightMove(int x, int y, int *sol, KNIGHT *stack, int r, int c)
{
	int steps = 0, d = 0, next_x, next_y;
	KNIGHT knight;
	*(sol + c * x + y) = steps++;
	//�����K�Ӥ�V�۹�y�Ъ��}�C
	int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
	
	while (steps <= r * c)
	{
		for (; d < 8; d++)//���թҦ������ʤ�V in �ثe���y��
		{
			//�ثe��m(row, col)�A�U�@�B�Ĥ@�ӥi�઺�y��
			next_x = x + xMove[d];
			next_y = y + yMove[d];
			if (inChess(next_x, next_y, r, c) && *(sol + c * next_x + next_y) == -1)
			{
				*(sol + c * next_x + next_y) = steps;
				knight.row = x;
				knight.col = y;
				knight.d = d;
				knight.steps = steps;
				push(knight, stack);//�N���ʦs�Jstack
				d = 0;
				x = next_x;
				y = next_y;
				steps++;
				if (steps == r * c)
				{
					return true;
				}
				break;
			}
		}
		if (d == 8 && top > 0)//�ثe��m�K�Ӥ�V�w���L�ҵL�i���ɰh�^�W�@�ӴM��i������V
		{
			knight = pop(stack);//���Xstack���ݪ����
			x = knight.row;
			y = knight.col;
			d = knight.d;
			steps = knight.steps;
			next_x = x + xMove[d];
			next_y = y + yMove[d];
			*(sol + c * next_x + next_y) = -1;
			d++;
		}
		else if (top <= 0)//�w�g�L�e��i�` no solution
		{
			break;
		}
	}	
	return false;
}

int main()
{
	int r = 0, c = 0, posX = 0, posY = 0;
	cout << "Input the size of chessboard: ";
	cin >> r >> c;
	cout << "Input the position of knight: ";
	cin >> posX >> posY;

	int *sol = new int[r * c];//�����M�h���޹L�{���ѽL

	KNIGHT *stack = new KNIGHT [r * c];//�B�z�^�����D�һݭn��Stack

	for (int x = 0; x < r; x++)//�Ҧ���l������-1
		for (int y = 0; y < c; y++)
			*(sol + c * x + y) = -1;

	//��l��m = 0
	*(sol + c * posX + posY) = 0;

	if(knightMove(posX, posY, sol, stack, r, c) == false)
		cout << "Solution does not exist" << endl;	
	else
		output(r, c, sol);


	delete[] sol;
	delete[] stack;
	
	return 0;
}
