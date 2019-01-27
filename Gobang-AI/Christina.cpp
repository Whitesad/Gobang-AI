#include "define.h"
#include "Christina.h"
double PosValue[15][15] =
{
{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0},
{1.0,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.0},
{1.0,1.3,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.3,1.0},
{1.0,1.3,1.8,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,1.8,1.3,1.0},
{1.0,1.3,1.8,2.5,3.5,3.5,3.5,3.5,3.5,3.5,3.5,2.5,1.8,1.3,1.0},
{1.0,1.3,1.8,2.5,3.5,4.5,4.5,4.5,4.5,4.5,3.5,2.5,1.8,1.3,1.0},
{1.0,1.3,1.8,2.5,3.5,4.5,5.5,5.5,5.5,4.5,3.5,2.5,1.8,1.3,1.0},
{1.0,1.3,1.8,2.5,3.5,4.5,5.5,6.0,5.5,4.5,3.5,2.5,1.8,1.3,1.0},
{1.0,1.3,1.8,2.5,3.5,4.5,5.5,5.5,5.5,4.5,3.5,2.5,1.8,1.3,1.0},
{1.0,1.3,1.8,2.5,3.5,4.5,4.5,4.5,4.5,4.5,3.5,2.5,1.8,1.3,1.0},
{1.0,1.3,1.8,2.5,3.5,3.5,3.5,3.5,3.5,3.5,3.5,2.5,1.8,1.3,1.0},
{1.0,1.3,1.8,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,1.8,1.3,1.0},
{1.0,1.3,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.3,1.0},
{1.0,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.0},
{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}
};
extern Map Chess_board;
long long MAX(long long A, long long B)
{
	return A > B ? A : B;
}
//struct point 区
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
//sstruct situation 区
long long situation::add(long long num) {
	switch (num)
	{
	case WIN5:win5++; break;
	case ALIVE2:alive2++; break;
	case ALIVE3:alive3++; break;
	case ALIVE4:alive4++; break;
	case DIE3:die3++; break;
	case DIE4:die4++; break;
	case LOWDIE4:lowdie4++; break;
	case TIAO3:tiao3++; break;
	case DIE2:die2++; break;
	case LOWALIVE2:lowalive2++; break;
	default:
		break;
	}
	return num;
}
long long situation::weight(void)
{
	long long result=0;
	if (win5 >= 1)
		result = MAX(result, LevelOne);//赢5

	if (alive4 >= 1 || die4 >= 2 || (die4 >= 1 && alive3 >= 1))
		result = MAX(result, Leveltwo);//活4 双死4 死4活3

	if (alive3 >= 2)
		result = MAX(result, Levelthree);//双活3

	if (die3 >= 1 && alive3 >= 1)
		result = MAX(result, Levelfour);//死3高级活3

	if (die4 >= 1)
		result = MAX(result, Levelfive);//高级死4

	if (lowdie4 >= 1)
		result = MAX(result, Levelsix);//低级死4

	if (alive3 >= 1)
		result = MAX(result, Levelseven);//单活3

	if (tiao3 >= 1)
		result = MAX(result, LevelEight);//跳活3

	if (alive2 >= 2)
		result = MAX(result, LevelNine);//双活2

	if (alive2 >= 1)
		result = MAX(result, LevelTen);//活2

	if (lowalive2 >= 1)
		result = MAX(result, LevelEleven);//低级活2

	if (die3 >= 1)
		result = MAX(result, LevelTwelve);//死3

	if (die2 >= 1)
		result = MAX(result, LevelThirteen);//死2
	return LevelFourteen;//没有威胁
}
void Gobang_AI::getchess(struct point chess)
{
	analyse_point = chess;
}
struct point Gobang_AI::play_chess(point player)
{
	//将玩家的棋子赋予给待分析棋子
	analyse_point = player;
	point atack_result,defend_result;
	point *atack=generate_way();
	point *defend = atack;
	long long score;
	long long ATACK_MAX=0;
	while (atack->x*atack->y!=0)
	{
		score = evaluate((*atack));
		score = (long long)(1.0*score*PosValue[atack->x-1][atack->y-1]);
		if (score > ATACK_MAX) 
		{
			atack_result = (*atack);
			ATACK_MAX = score;
		}
		atack++;
	}
	long long DEFEND_MAX=0;
	while (defend->x*defend->y != 0)
	{
		point tem = (*defend);
		tem.color = (tem.color == WHITE ? BLACK : WHITE);
		score = evaluate(tem);
		score = (long long)(1.0*score*PosValue[tem.x - 1][tem.y - 1]);
		if (score > DEFEND_MAX)
		{
			defend_result = (*defend);
			DEFEND_MAX = score;
		}
		defend++;
	}
	if (ATACK_MAX > DEFEND_MAX)
		return atack_result;
	else
		return defend_result;
}
	/*srand((time(0)));
	point result = player;
	result.x = player.x+(rand() % 2), result.y = player.y+(rand() % 2);
	while (!player.judge()||Chess_board.MAP[result.x][result.y]!=NONE  )
		result.x = player.x + (rand() % 2), result.y = player.y + (rand() % 2);*/
point* Gobang_AI::generate_way(void)
{
	memset(WAY, 0, sizeof(WAY));//初始化
	int color = (analyse_point.color == WHITE ? BLACK : WHITE);
	int count = 0;
	for(int i=1;i<=15;i++)
		for (int j = 1; j <= 15; j++) {
			if (Chess_board.MAP[i][j] == NONE)
			{
				WAY[count].x = i, WAY[count].y = j,WAY[count].color=color;
				count++;
			}
		}
	return &WAY[0];
}
void Gobang_AI::getchess(point &step,int fr, int fc, int *chess)
{
	point tem = step;
	int i;
	for (i = 0; i < 3; i++) 
	{
		tem.x = tem.x + fr, tem.y = tem.y + fc;
		if (tem.judge())
		{
			if(Chess_board.MAP[tem.x][tem.y] == step.color)
				chess[i] = step.color;
			else if(Chess_board.MAP[tem.x][tem.y] == NONE)
				chess[i] = NONE;
			else
				chess[i] = BOUD;
		}
		else chess[i] = BOUD;
	}
}
long long Gobang_AI::cal(point &step,int R, int L, int count,int *RIGHT,int *LEFT) {


	int L1 = LEFT[0], L2 = LEFT[1], L3 = LEFT[2];
	int R1 = RIGHT[0], R2 = RIGHT[1], R3 = RIGHT[2];


	if (count >= 5)//中心线5连
		return WIN5;//5连珠

	if (count == 4)//中心线4连
	{
		if (L == NONE && R == NONE)//两边断开位置均空
			return ALIVE4;//活四
		else if (L == BOUD && R == BOUD)//两边断开位置均非空
			return NOTHREAT;//没有威胁
		else if (L == NONE || R == NONE)//两边断开位置只有一个空
			return DIE4;//死四
	}

	if (count == 3) 
	{//中心线3连

		if (L == NONE && R == NONE)//两边断开位置均空
		{
			if (L1 == BOUD && R1 == BOUD)//均为对手棋子
				return DIE3;
			else if (L1 == step.color || R1 == step.color)//只要一个为自己的棋子
				return LOWDIE4;
			else if (L1 == NONE || R1 == NONE)//只要有一个空
				return ALIVE3;
		}
		else if (L == BOUD && R == BOUD)//两边断开位置均非空
		{
			return NOTHREAT;//没有威胁
		}
		else if (L == NONE || R == NONE)//两边断开位置只有一个空
		{
			if (L == BOUD) 
			{//左边被对方堵住
				if (R1 == BOUD)//右边也被对方堵住
					return NOTHREAT;
				if (R1 == NONE)//右边均空
					return DIE3;
				if (R1 == step.color)
					return LOWDIE4;

			}
			if (R == BOUD) {//右边被对方堵住
				if (L1 == BOUD)//左边也被对方堵住
					return NOTHREAT;
				if (L1 == NONE)//左边均空
					return DIE3;
				if (L1 == step.color)//左边还有自己的棋子
					return LOWDIE4;
			}
		}
	}

	if (count == 2) 
	{//中心线2连
		if (L == NONE && R == NONE)//两边断开位置均空
		{
			if ((R1 == NONE && R2 == step.color) ||
				(L1 == NONE && L2 == step.color))
				return DIE3;//死3
			else if (L1 == NONE && R1 == NONE)
				return ALIVE2;//活2

			if ((R1 == step.color && R2 == BOUD) ||
				(L1 == step.color && L2 == BOUD))
				return DIE3;//死3

			if ((R1 == step.color && R2 == step.color) ||
				(L1 == step.color && L2 == step.color))
				return LOWDIE4;//死4

			if ((R1 == step.color && R2 == NONE) ||
				(L1 == step.color && L2 == NONE))
				return TIAO3;//跳活3
			//其他情况在下边返回NOTHREAT
		}
		else if (L == BOUD && R == BOUD)//两边断开位置均非空
		{
			return NOTHREAT;
		}
		else if (L == NONE || R == NONE)//两边断开位置只有一个空
		{
			if (L == BOUD) {//左边被对方堵住
				if (R1 == BOUD || R2 == BOUD) {//只要有对方的一个棋子
					return NOTHREAT;//没有威胁
				}
				else if (R1 == NONE && R2 == NONE) {//均空
					return DIE2;//死2
				}
				else if (R1 == step.color && R2 == step.color) {//均为自己的棋子
					return LOWDIE4;//死4
				}
				else if (R1 == step.color || R2 == step.color) {//只有一个自己的棋子
					return DIE3;//死3
				}
			}
			if (R == BOUD) {//右边被对方堵住
				if (L1 == BOUD || L2 == BOUD) {//只要有对方的一个棋子
					return NOTHREAT;//没有威胁
				}
				else if (L1 == NONE && L2 == NONE) {//均空
					return DIE2;//死2
				}
				else if (L1 == step.color && L2 == step.color) {//均为自己的棋子
					return LOWDIE4;//死4
				}
				else if (L1 == step.color || L2 == step.color) {//只有一个自己的棋子
					return DIE3;//死3
				}
			}
		}
	}

	if (count == 1) {
		//中心线1连
		if (L == NONE && L1 == step.color &&
			L2 == step.color && L3 == step.color)
			return LOWDIE4;
		if (R == NONE && R1 == step.color &&
			R2 == step.color && R3 == step.color)
			return LOWDIE4;

		if (L == NONE && L1 == step.color &&
			L2 == step.color && L3 == NONE && R == NONE)
			return TIAO3;
		if (R == NONE && R1 == step.color &&
			R2 == step.color && R3 == NONE && L == NONE)
			return TIAO3;

		if (L == NONE && L1 == step.color &&
			L2 == step.color && L3 == BOUD && R == NONE)
			return DIE3;
		if (R == NONE && R1 == step.color &&
			R2 == step.color && R3 == BOUD && L == NONE)
			return DIE3;

		if (L == NONE && L1 == NONE &&
			L2 == step.color && L3 == step.color)
			return DIE3;
		if (R == NONE && R1 == NONE &&
			R2 == step.color && R3 == step.color)
			return DIE3;

		if (L == NONE && L1 == step.color &&
			L2 == NONE && L3 == step.color)
			return DIE3;
		if (R == NONE && R1 == step.color &&
			R2 == NONE && R3 == step.color)
			return DIE3;

		if (L == NONE && L1 == step.color &&
			L2 == NONE && L3 == NONE && R == NONE)
			return LOWALIVE2;
		if (R == NONE && R1 == step.color &&
			R2 == NONE && R3 == NONE && L == NONE)
			return LOWALIVE2;

		if (L == NONE && L1 == NONE &&
			L2 == step.color && L3 == NONE && R == NONE)
			return LOWALIVE2;
		if (R == NONE && R1 == NONE &&
			R2 == step.color && R3 == NONE && L == NONE)
			return LOWALIVE2;
		//其余在下边返回没有威胁
	}
	return NOTHREAT;//返回没有威胁
}
long long Gobang_AI::evaluate(point& step)
{

	long long score = 0;
	int RIGHT[3], LEFT[3];//此数组储存的是该连珠域外左右各三个子的情况,左边为前三个
	int L, R;//储存左右两头分别是什么
	situation Record;


	//向下进行检查
	point tem = step;
	int count = 1;
	tem.x++;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x++, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		L = NONE;
	else L = BOUD;
	getchess(tem, 1, 0, LEFT);
	//向上进行检查
	tem = step;
	tem.x--;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x--, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		R = NONE;
	else R = BOUD;
	getchess(tem, -1, 0, RIGHT);
	score += Record.add(cal(step, R, L, count, RIGHT, LEFT));

	//向左进行检查
	count = 1;
	tem = step;
	tem.y--;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.y--, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		L = NONE;
	else L = BOUD;
	getchess(tem, 0, -1, LEFT);
	//向右进行检查
	tem = step;
	tem.y++;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.y++, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		R = NONE;
	else R = BOUD;
	getchess(tem, 0, 1, RIGHT);
	score += Record.add(cal(step, R, L, count, RIGHT, LEFT));


	//向左上
	count = 1;
	tem = step;
	tem.x--, tem.y--;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x--, tem.y--, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		L = NONE;
	else L = BOUD;
	getchess(tem, -1, -1, LEFT);
	//向右下
	tem = step;
	tem.x++, tem.y++;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x++, tem.y++, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		R = NONE;
	else R = BOUD;
	getchess(tem, 1, 1, RIGHT);
	score += Record.add(cal(step, R, L, count, RIGHT, LEFT));


	//向右上
	count = 1;
	tem = step;
	tem.x--, tem.y++;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x--, tem.y++, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		L = NONE;
	else L = BOUD;
	getchess(tem, -1, 1, LEFT);
	//向左下
	tem = step;
	tem.x++, tem.y--;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x++, tem.y--, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		R = NONE;
	else R = BOUD;
	getchess(tem, 1, -1, RIGHT);
	score += Record.add(cal(step, R, L, count, RIGHT, LEFT));

	score += Record.weight();

	return score;
}


