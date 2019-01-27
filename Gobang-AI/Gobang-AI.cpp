// Gobang-AI.cpp : 
//2019 1 15 AI开工
#define DEBU
#include "define.h"
Map Chess_board;
Gobang_AI Christina;
int main()
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // 

	Startmemu();//打印开始界面
	Chessboard();//打印棋盘
	enum select SELECT = get_select();//获得玩家输入
	Round round;
	int player_color, AI_color;
	while (SELECT == erro)
		SELECT = get_select();
	switch (SELECT)
	{
	case player_first:
		round = Round::Player;
		break;
	case computer_first:
		round = Round::AI;
		break;
	case erro:
		puts("Illegal input!");
		SELECT = get_select();
		break;
	}
	point step;
	if (SELECT == computer_first)
		step.x = step.y = 7,step.color=WHITE;
	else
		step.x = step.y = 0,step.color=BLACK;
	do
	{
		switch (round)
		{
		case Player:
			step.get();
			round = AI;
			Chess_board.set(step);
			break;
		case AI:
			step=Christina.play_chess(step);
			Chess_board.set(step);
			step.color = (step.color == WHITE ? BLACK : WHITE);
			round = Player;
			break;
		}
		Chess_board.flash_borad();
		gotoxy(0, 25);
		printf("r=%d c=%d", step.x, step.y);
		gotoxy(0, 21);
	} while (!Chess_board.isend(step));
	if (round == Player)
		puts("Your lose is decided by steins gate!");
	else
		puts("Your win is decided by steins gate!");
	getchar();
	return 0;
}
 