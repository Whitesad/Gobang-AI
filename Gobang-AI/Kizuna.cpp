#include "define.h"

extern Map Chess_board;
void Gobang_AI::getchess(struct point chess)
{
	analyse_point = chess;
}
struct point Gobang_AI::play_chess(point player)
{
	srand((time(0)));
	point result = player;
	result.x = player.x+(rand() % 2), result.y = player.y+(rand() % 2);
	while (!player.judge()||Chess_board.MAP[result.x][result.y]!=NONE  )
		result.x = player.x + (rand() % 2), result.y = player.y + (rand() % 2);
	return result;
}

void point::get(void)
{
	puts("Input your step(r,c)");
	int num = scanf("%d %d", &x, &y);
	while (num != 2 || judge() == false || Chess_board.MAP[x][y] != NONE)
	{
		puts("Illegal input!Try again:");
		num = scanf("%d %d", &x, &y);
	}
}