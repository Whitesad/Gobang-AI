#include "define.h"
double PosValue[15][15] =
{
{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0},
{1.0,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.0},
{1.0,1.5,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,1.5,1.0},
{1.0,1.5,2.0,3.5,3.5,3.5,3.5,3.5,3.5,3.5,3.5,3.5,2.0,1.5,1.0},
{1.0,1.5,2.0,3.5,4.0,4.0,4.0,4.0,4.0,4.0,4.0,3.5,2.0,1.5,1.0},
{1.0,1.5,2.0,3.5,4.0,4.5,4.5,4.5,4.5,4.5,4.0,3.5,2.0,1.5,1.0},
{1.0,1.5,2.0,3.5,4.0,4.5,5.5,5.5,5.5,4.5,4.0,3.5,2.0,1.5,1.0},
{1.0,1.5,2.0,3.5,4.0,4.5,5.5,7.0,5.5,4.5,4.0,3.5,2.0,1.5,1.0},
{1.0,1.5,2.0,3.5,4.0,4.5,5.5,5.5,5.5,4.5,4.0,3.5,2.0,1.5,1.0},
{1.0,1.5,2.0,3.5,4.0,4.5,4.5,4.5,4.5,4.5,4.0,3.5,2.0,1.5,1.0},
{1.0,1.5,2.0,3.5,4.0,4.0,4.0,4.0,4.0,4.0,4.0,3.5,2.0,1.5,1.0},
{1.0,1.5,2.0,3.5,3.5,3.5,3.5,3.5,3.5,3.5,3.5,3.5,2.0,1.5,1.0},
{1.0,1.5,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,1.5,1.0},
{1.0,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.0},
{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}
};
extern Map Chess_board;
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
void Gobang_AI::getchess(struct point chess)
{
	analyse_point = chess;
}
struct point Gobang_AI::play_chess(point player)
{
	//����ҵ����Ӹ��������������
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
	memset(WAY, 0, sizeof(WAY));//��ʼ��
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
#define WIN5 100000
#define ALIVE4 10000
#define DIE4 500
#define DIE3  1000
#define LOWDIE4 400
#define ALIVE3 1000
#define ALIVE2 10
#define NOTHREAT 1
#define TIAO3 90
#define DIE2 2
#define LOWALIVE2 9

	int L1 = LEFT[0], L2 = LEFT[1], L3 = LEFT[2];
	int R1 = RIGHT[0], R2 = RIGHT[1], R3 = RIGHT[2];


	if (count >= 5)//������5��
		return WIN5;//5����

	if (count == 4)//������4��
	{
		if (L == NONE && R == NONE)//���߶Ͽ�λ�þ���
			return ALIVE4;//����
		else if (L == BOUD && R == BOUD)//���߶Ͽ�λ�þ��ǿ�
			return NOTHREAT;//û����в
		else if (L == NONE || R == NONE)//���߶Ͽ�λ��ֻ��һ����
			return DIE4;//����
	}

	if (count == 3) {//������3��

		if (L == NONE && R == NONE)//���߶Ͽ�λ�þ���
		{
			if (L1 == BOUD && R1 == BOUD)//��Ϊ��������
				return DIE3;
			else if (L1 == step.color || R1 == step.color)//ֻҪһ��Ϊ�Լ�������
				return LOWDIE4;
			else if (L1 == NONE || R1 == NONE)//ֻҪ��һ����
				return ALIVE3;
		}
		else if (L == BOUD && R == BOUD)//���߶Ͽ�λ�þ��ǿ�
		{
			return NOTHREAT;//û����в
		}
		else if (L == NONE || R == NONE)//���߶Ͽ�λ��ֻ��һ����
		{
			if (L == BOUD) {//��߱��Է���ס
				if (R1 == BOUD)//�ұ�Ҳ���Է���ס
					return NOTHREAT;
				if (R1 == NONE)//�ұ߾���
					return DIE3;
				if (R1 == step.color)
					return LOWDIE4;

			}
			if (R == BOUD) {//�ұ߱��Է���ס
				if (L1 == BOUD)//���Ҳ���Է���ס
					return NOTHREAT;
				if (L1 == NONE)//��߾���
					return DIE3;
				if (L1 == step.color)//��߻����Լ�������
					return LOWDIE4;
			}
		}
	}

	if (count == 2) {//������2��

		if (L == NONE && R == NONE)//���߶Ͽ�λ�þ���
		{
			if ((R1 == NONE && R2 == step.color) ||
				(L1 == NONE && L2 == step.color))
				return DIE3;//��3
			else if (L1 == NONE && R1 == NONE)
				return ALIVE2;//��2

			if ((R1 == step.color && R2 == BOUD) ||
				(L1 == step.color && L2 == BOUD))
				return DIE3;//��3

			if ((R1 == step.color && R2 == step.color) ||
				(L1 == step.color && L2 == step.color))
				return LOWDIE4;//��4

			if ((R1 == step.color && R2 == NONE) ||
				(L1 == step.color && L2 == NONE))
				return TIAO3;//����3
			//����������±߷���NOTHREAT
		}
		else if (L == BOUD && R == BOUD)//���߶Ͽ�λ�þ��ǿ�
		{
			return NOTHREAT;
		}
		else if (L == NONE || R == NONE)//���߶Ͽ�λ��ֻ��һ����
		{
			if (L == BOUD) {//��߱��Է���ס
				if (R1 == BOUD || R2 == BOUD) {//ֻҪ�жԷ���һ������
					return NOTHREAT;//û����в
				}
				else if (R1 == NONE && R2 == NONE) {//����
					return DIE2;//��2
				}
				else if (R1 == step.color && R2 == step.color) {//��Ϊ�Լ�������
					return LOWDIE4;//��4
				}
				else if (R1 == step.color || R2 == step.color) {//ֻ��һ���Լ�������
					return DIE3;//��3
				}
			}
			if (R == BOUD) {//�ұ߱��Է���ס
				if (L1 == BOUD || L2 == BOUD) {//ֻҪ�жԷ���һ������
					return NOTHREAT;//û����в
				}
				else if (L1 == NONE && L2 == NONE) {//����
					return DIE2;//��2
				}
				else if (L1 == step.color && L2 == step.color) {//��Ϊ�Լ�������
					return LOWDIE4;//��4
				}
				else if (L1 == step.color || L2 == step.color) {//ֻ��һ���Լ�������
					return DIE3;//��3
				}
			}
		}
	}

	if (count == 1) {
		//������1��
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
		//�������±߷���û����в
	}
	return NOTHREAT;//����û����в
}
long long Gobang_AI::evaluate(point& step)
{

	long long score = 0;
	int RIGHT[3], LEFT[3];//�����鴢����Ǹ������������Ҹ������ӵ����,���Ϊǰ����
	int L, R;//����������ͷ�ֱ���ʲô
	//���½��м��
	point tem = step;
	int count = 1;
	tem.x++;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x++, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		L = NONE;
	else L = BOUD;
	getchess(tem, 1, 0, LEFT);
	//���Ͻ��м��
	tem = step;
	tem.x--;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x--, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		R = NONE;
	else R = BOUD;
	getchess(tem, -1, 0, RIGHT);
	score += cal(step, R, L, count, RIGHT, LEFT);

	//������м��
	count = 1;
	tem = step;
	tem.y--;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.y--, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		L = NONE;
	else L = BOUD;
	getchess(tem, 0, -1, LEFT);
	//���ҽ��м��
	tem = step;
	tem.y++;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.y++, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		R = NONE;
	else R = BOUD;
	getchess(tem, 0, 1, RIGHT);
	score += cal(step, R, L, count, RIGHT, LEFT);


	//������
	count = 1;
	tem = step;
	tem.x--, tem.y--;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x--, tem.y--, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		L = NONE;
	else L = BOUD;
	getchess(tem, -1, -1, LEFT);
	//������
	tem = step;
	tem.x++, tem.y++;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x++, tem.y++, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		R = NONE;
	else R = BOUD;
	getchess(tem, 1, 1, RIGHT);
	score += cal(step, R, L, count, RIGHT, LEFT);


	//������
	count = 1;
	tem = step;
	tem.x--, tem.y++;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x--, tem.y++, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		L = NONE;
	else L = BOUD;
	getchess(tem, -1, 1, LEFT);
	//������
	tem = step;
	tem.x++, tem.y--;
	while (tem.judge() && Chess_board.MAP[tem.x][tem.y] == step.color)
		tem.x++, tem.y--, count++;
	if (tem.judge() && Chess_board.MAP[tem.x][tem.y] == NONE)
		R = NONE;
	else R = BOUD;
	getchess(tem, 1, -1, RIGHT);
	score += cal(step, R, L, count, RIGHT, LEFT);



	return score;
}


