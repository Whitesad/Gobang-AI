#pragma once
#ifndef _KIZUNA_H_
#define _KIZUNA_H_
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
};
class Gobang_AI
{
public:
	Gobang_AI(){/**/ }
	void getchess(point chess);
	point play_chess(point player);
private:
	point analyse_point;
};

#endif // !_START_H_
