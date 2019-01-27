// Gobang-AI.cpp : 
//2019 1 15 AI开工
#define DEBUGS
#include "define.h"
Map Chess_board;
int main()
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // 

	Startmemu();//打印开始界面
	Chessboard();//打印棋盘
	enum select SELECT = get_select();//获得玩家输入
	Round round;
	Gobang_AI Kizuna;
	int player_color, AI_color;
	while (SELECT == erro)
		SELECT = get_select();
	switch (SELECT)
	{
	case player_first:
		round = Round::Player;
		player_color = BLACK, AI_color = WHITE;
		break;
	case computer_first:
		round = Round::AI;
		player_color = WHITE, AI_color = BLACK;
		break;
	case erro:
		puts("Illegal input!");
		SELECT = get_select();
		break;
	}
	point step;
	if (SELECT == computer_first)
		step.x = step.y = 7;
	else
		step.x = step.y = 0;
	int color = WHITE;
	while (!Chess_board.isend(step,color))
	{
		switch (round)
		{
		case Player:
			step.get();
			round = AI;
			Chess_board.set(step, player_color);
			break;
		case AI:
			step=Kizuna.play_chess(step);
			Chess_board.set(step, AI_color);
			round = Player;
			break;
		default:
			break;
		}
		Chess_board.flash_borad();
		color = (color == WHITE ? BLACK : WHITE);
	}
	return 0;
}
