#ifndef _START_H_
#define _START_H_

void Startmemu(void);
void Chessboard(void);
enum select get_select(void);
void gotoxy(int x, int y);

enum select
{
	player_first, computer_first,erro
};
#endif // !_START_H_
