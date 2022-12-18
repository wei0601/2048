#include <iostream>
#include <windows.h>
#include<easyx.h>
#include <ctime>//����ʱ������ڵĺ����ṹ
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

int const ROW = 4;
int const COL = 4;
int game[ROW][COL] = { 0 };

//��������
int const UP = 1;
int const DOWN = 2;
int const LEFT = 3;
int const RIGHT = 4;

//��Ϸ������״̬
int const GAME_OVER = 1;
int const GAME_WIN = 2;
int const GAME_CONTINUE = 3;
int score = 0;
enum GameNum
{
	Game_2 = 2,
	Game_4 = 4,
	Game_8 = 8,
	Game_16 = 16,
	Game_32 = 32,
	Game_64 = 64,
	Game_128 = 128,
	Game_256 = 256,
	Game_512 = 512,
	Game_1024 = 1024,
	Game_2048 = 2048,
};//ö������

//��ӡ���õ�����
void Print()
{
	system("cls");//system("CLS")����ʵ����������
	
	mciSendString("open ������.mp3", 0, 0, 0);
	mciSendString("play ������.mp3", 0, 0, 0);
	system("color 4F"); //�ı����̨��ǰ��ɫ�ͱ�������������Ϊ����ɫ
	cout <<"                   2048 С��Ϸ                         " << endl;
	cout << "                    FIGHTINGS��                       " << endl;
	cout << "                       by wei" << endl<<endl;
	//�����������
	for (int i = 0; i < ROW; ++i)
	{
		cout << "_________________________________" << endl;
		for (int j = 0; j < COL; ++j)
		{
			if (game[i][j] == 0)
			{
				cout << "|   \t";
			}
			else
			{
				cout << "| " << game[i][j] << "\t";
			}
		}
		cout << "|" << endl;
	}
	cout << "_________________________________" << endl;
}


bool CreateNumber()
{
	int x = -1;
	int y = -1;
	int times = 0;
	int maxTimes = ROW * COL;
	//�ҿո�1/2�ĸ�������2��5/16�ĸ�������4��1/8����8,1/16����16
	int whitch = rand() % 16;//0-2�����
	do
	{
		x = rand() % ROW;
		y = rand() % COL;
		//����0-ROW(COL)-1�����
		++times;
	} while (game[x][y] != 0 && times <= maxTimes);

	//˵�������Ѿ�����
	if (times >= maxTimes)
	{
		return false;
	}
	else
	{
		GameNum num;
		if (whitch == 0)
		{
			num = Game_16;
		}
		else if (whitch==1|| whitch==2)
		{
			num = Game_8;
		}
		else if(whitch>=3&& whitch<=7)
		{
			num = Game_4;
		}
		else if (whitch)
		{
			num = Game_2;
		}
		game[x][y] = num;
	}

	return true;
}


void Process(int direction)
{
	switch (direction)
	{
	case UP:
		//������һ�в���
		for (int row = 1; row < ROW; ++row)
		{
			for (int crow = row; crow >= 1; --crow)
			{
				for (int col = 0; col < COL; ++col)
				{
					//��һ������Ϊ��
					if (game[crow - 1][col] == 0)
					{
						game[crow - 1][col] = game[crow][col];
						game[crow][col] = 0;
						score = score;
					}
					else
					{
						//�ϲ�
						if (game[crow - 1][col] == game[crow][col]&& game[crow][col]==Game_2)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 2;
						}
						if (game[crow - 1][col] == game[crow][col] && game[crow][col] == Game_4)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 4;
						}
						if (game[crow - 1][col] == game[crow][col] && game[crow][col] == Game_8)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 8;
						}
						if (game[crow - 1][col] == game[crow][col] && game[crow][col] == Game_16)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 16;
						}
						if (game[crow - 1][col] == game[crow][col] && game[crow][col] == Game_32)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 32;
						}
						if (game[crow - 1][col] == game[crow][col] &&game[crow][col]== Game_64)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 64;
						}
						if (game[crow - 1][col] == game[crow][col] && game[crow][col] == Game_128)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 128;
						}
						if (game[crow - 1][col] == game[crow][col] && game[crow][col] == Game_256)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 256;
						}
						if (game[crow - 1][col] == game[crow][col] && game[crow][col] == Game_512)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 512;
						}
						if (game[crow - 1][col] == game[crow][col] && game[crow][col] == Game_1024)
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 1024;
						}
					}
				}
			}
		}
		break;
	case DOWN:
		//������һ�в���
		for (int row = ROW - 2; row >= 0; --row)
		{
			for (int crow = row; crow < ROW - 1; ++crow)
			{
				for (int col = 0; col < COL; ++col)
				{
					//��һ������Ϊ��
					if (game[crow + 1][col] == 0)
					{
						game[crow + 1][col] = game[crow][col];
						game[crow][col] = 0;
					}
					else
					{
						//�ϲ�
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_2)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 2;
						}
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_4)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 4;
						}
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_8)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 8;
						}
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_16)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 16;
						}
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_32)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 32;
						}
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_64)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 64;
						}
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_128)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 128;
						}
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_256)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 256;
						}
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_512)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 512;
						}
						if (game[crow + 1][col] == game[crow][col] && game[crow][col] == Game_1024)
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
							score = score + 1024;
						}

					}
				}
			}
		}
		break;
	case LEFT:
		//�����һ�в���
		for (int col = 1; col < COL; ++col)
		{
			for (int ccol = col; ccol >= 1; --ccol)
			{
				for (int row = 0; row < ROW; ++row)
				{
					//��һ������Ϊ��
					if (game[row][ccol - 1] == 0)
					{
						game[row][ccol - 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else
					{
						//�ϲ�
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol]== Game_2)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 2;
						}
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol] == Game_4)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 4;
						}
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol] == Game_8)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 8;
						}
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol] == Game_16)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 16;
						}
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol] == Game_32)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 32;
						}
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol] == Game_64)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 64;
						}
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol] == Game_128)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 128;
						}
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol] == Game_256)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 256;
						}
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol] == Game_512)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 512;
						}
						if (game[row][ccol - 1] == game[row][ccol] && game[row][ccol] == Game_1024)
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
							score = score + 1024;
						}
					}
				}
			}
		}
		break;
	case RIGHT:
		//���ұ�һ�в���
		for (int col = COL - 2; col >= 0; --col)
		{
			for (int ccol = col; ccol <= COL - 2; ++ccol)
			{
				for (int row = 0; row < ROW; ++row)
				{
					//��һ������Ϊ��
					if (game[row][ccol + 1] == 0)
					{
						game[row][ccol + 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else
					{
						//�ϲ�
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_2)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 2;
						}
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_4)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 4;
						}
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_8)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 8;
						}
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_16)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 16;
						}
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_32)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 32;
						}
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_64)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 64;
						}
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_128)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 128;
						}
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_256)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 256;
						}
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_512)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 512;
						}
						if (game[row][ccol + 1] == game[row][ccol] && game[row][ccol] == Game_1024)
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
							score = score + 1024;
						}
					}
				}
			}
		}
		break;
	}

}

//�������������������������
int Input()
{
	//��ȡ���������ĸ������
	int upArrow = 0;
	int downArrow = 0;
	int leftArrow = 0;
	int rightArrow = 0;
	int direction = 0;
	while (true)
	{
		upArrow = GetAsyncKeyState(VK_UP);//���ӵ��ϼ�ͷ
		downArrow = GetAsyncKeyState(VK_DOWN);//�¼�ͷ
		leftArrow = GetAsyncKeyState(VK_LEFT);//���ͷ
		rightArrow = GetAsyncKeyState(VK_RIGHT);//�Ҽ�ͷ

		if (upArrow)
		{
			direction = UP;
			break;
		}
		else if (downArrow)
		{
			direction = DOWN;
			break;
		}
		else if (leftArrow)
		{
			direction = LEFT;
			break;
		}
		else if (rightArrow)
		{
			direction = RIGHT;
			break;
		}

		Sleep(100);//��ͣ100ms
	}

	return direction;
}

//�ж���Ϸ״̬
int Judge()
{
	
	//Ӯ����Ϸ
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (game[i][j] == 2048)
			{
				return GAME_WIN;
				break;
			}
		}
	}

	//������
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL - 1; ++j)
		{
			if (!game[i][j] || (game[i][j] == game[i][j + 1]))
			{
				return GAME_CONTINUE;
				break;
			}
		}
	}
	//������
	for (int j = 0; j < COL; ++j)
	{
		for (int i = 0; i < ROW - 1; ++i)
		{
			if (!game[i][j] || (game[i][j] == game[i + 1][j]))
			{
				return GAME_CONTINUE;
				break;
			}
		}
	}

	//��������������״������Ϸ����
	return GAME_OVER;

}

int main()
{
	//����һ�����������
	srand((unsigned int)time(0));
	CreateNumber();
	CreateNumber();
	Print();
	int direction = 0;
	int gameState = -1;
	while (true)
	{
		gameState = Judge();
		direction = Input();
		if (direction && gameState == GAME_CONTINUE)
		{
			Process(direction);
			CreateNumber();
			Sleep(100);//��ͣ
			Print();
			cout << "score: " << score << endl;
			Sleep(1000);
		}
		else if (gameState == GAME_WIN)
		{
			Print();
			cout << "score: " << score << endl;
			cout << "You Win��" << endl;
			break;
		}
		else if (gameState == GAME_OVER)
		{
			Print();
			cout << "score: " << score << endl;
			cout << "You lose!" << endl;
			break;
		}
	}

	return 0;
}