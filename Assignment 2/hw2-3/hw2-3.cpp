#include <iostream>
#include <iomanip>

using namespace std;

int top;

typedef struct Knight {
	int row, col;
	int d;//前往的方向
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

//判斷(row, col)有無超出棋盤
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

//騎士從起點開始移動n * n步
int knightMove(int x, int y, int *sol, KNIGHT *stack, int r, int c)
{
	int steps = 0, d = 0, next_x, next_y;
	KNIGHT knight;
	*(sol + c * x + y) = steps++;
	//紀錄八個方向相對座標的陣列
	int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
	
	while (steps <= r * c)
	{
		for (; d < 8; d++)//嘗試所有的移動方向 in 目前的座標
		{
			//目前位置(row, col)，下一步第一個可能的座標
			next_x = x + xMove[d];
			next_y = y + yMove[d];
			if (inChess(next_x, next_y, r, c) && *(sol + c * next_x + next_y) == -1)
			{
				*(sol + c * next_x + next_y) = steps;
				knight.row = x;
				knight.col = y;
				knight.d = d;
				knight.steps = steps;
				push(knight, stack);//將移動存入stack
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
		if (d == 8 && top > 0)//目前位置八個方向已爬過皆無可走時退回上一個尋找可走的方向
		{
			knight = pop(stack);//取出stack頂端的資料
			x = knight.row;
			y = knight.col;
			d = knight.d;
			steps = knight.steps;
			next_x = x + xMove[d];
			next_y = y + yMove[d];
			*(sol + c * next_x + next_y) = -1;
			d++;
		}
		else if (top <= 0)//已經無前跡可循 no solution
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

	int *sol = new int[r * c];//紀錄騎士巡邏過程的棋盤

	KNIGHT *stack = new KNIGHT [r * c];//處理回溯問題所需要的Stack

	for (int x = 0; x < r; x++)//所有格子全部填-1
		for (int y = 0; y < c; y++)
			*(sol + c * x + y) = -1;

	//初始位置 = 0
	*(sol + c * posX + posY) = 0;

	if(knightMove(posX, posY, sol, stack, r, c) == false)
		cout << "Solution does not exist" << endl;	
	else
		output(r, c, sol);


	delete[] sol;
	delete[] stack;
	
	return 0;
}
