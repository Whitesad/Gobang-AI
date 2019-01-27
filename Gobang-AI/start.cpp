#include "define.h"
void gotoxy(int x, int y) //������ƶ�������Ϊ(x,y)�ĵط�
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void Startmemu(void)
{
	cout << "*************��ӭ�����������˻�����ϵͳ*************" << endl;
	cout << "����: newblack  ��������" << endl;
	cout << "����: newwhite  ���Ժ���" << endl;
	cout << "����: move x y  ��ʾ���ӵ�" << endl;
}
static void judge(int i, int j);
void Chessboard(void)
{
	for (int i = 0; i < 16; i++)
	{
		if (i == 0)
		{
			printf("    ");
			for (int j = 1; j < 16; j++)
				printf("%-2d", j);
			printf("\n");
			continue;
		}
		for (int j = 0; j < 16; j++)
		{
			if (j == 0)
			{
				printf("%2d", i);
				continue;
			}
			else
			{
				judge(i, j);
			}
		}
		printf("\n");
	}
}
void judge(int i, int j)
{
	if (i == 1 && j == 1)
		printf(" �X");
	else if (i == 1 && j == 15)
		printf(" �[");
	else if (i == 15 && j == 1)
		printf(" �^");
	else if (i == 15 && j == 15)
		printf(" �a");
	else if (i == 1 && j != 15 && j != 1)
		printf(" ��");
	else if (i == 15 && j != 15 && j != 1)
		printf(" ��");
	else if (j == 1 && i != 15 && i != 1)
		printf(" ��");
	else if (j == 15 && i != 15 && i != 1)
		printf(" ��");
	else
		printf(" ��");
}
enum select get_select(void)
{
	char input[35];
	puts("Input your choice:");
	gets_s(input,34);
	if (strcmp(input, "newblack") == 0)
		return select::computer_first;
	if (strcmp(input, "newwhite") == 0)
		return select::player_first;
	else return select::erro;
}