#pragma once
#ifndef _CHRISTINA_H_
#define _CHRISTINA_H_

struct point
{
	point(void) {/**/ }
	point(int x_value, int y_value) {
		x = x_value, y = y_value;
	}
	void get(int x_value, int y_value)
	{
		x = x_value, y = y_value;
	}
	void get(void);
	bool judge(void) {
		if (x >= 1 && x <= 15 && y >= 1 && y <= 15)
			return true;
		return false;
	}
	int x, y;
	int color;
};
class Gobang_AI
{
public:
	Gobang_AI(){/**/ }
	void getchess(point chess);
	point play_chess(point player);
private:
	long long evaluate(point& step);
	long long cal(point &step,int R, int L, int count, int *RIGHT, int *LEFT);
	void getchess(point &step, int fr, int fc, int *chess);//作为补全连珠域外棋子的函数存在
	point *generate_way(void);
	point analyse_point;
	point WAY[255];
};

#endif // !_START_H_
