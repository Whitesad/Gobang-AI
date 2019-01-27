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

//棋子情况
#define WIN5 100000
#define ALIVE4 10000
#define DIE4 500
#define DIE3  250
#define LOWDIE4 200
#define ALIVE3 1000
#define ALIVE2 10
#define NOTHREAT 1
#define TIAO3 90
#define DIE2 2
#define LOWALIVE2 9

#define LevelOne 200000
#define Leveltwo 10000
#define Levelthree 5000
#define Levelfour 3000
#define Levelfive 500
#define Levelsix 200
#define Levelseven 100
#define LevelEight 50
#define LevelNine 100
#define LevelTen 20
#define LevelEleven 10
#define LevelTwelve 5
#define LevelThirteen 5
#define LevelFourteen 1

struct situation
{
	long long add(long long num);
	long long weight(void);
	situation(void) {
		win5=0;
		alive2=0;
		alive3=0;
		alive4=0;
		die3=0;
		die4=0;
		lowdie4=0;
		lowalive2 = 0;
		die2 = 0;
		tiao3=0;
	}
	int win5;
	int alive2;
	int alive3;
	int alive4;
	int lowalive2;
	int die2 = 0;
	int die3;
	int die4;
	int lowdie4;
	int tiao3;
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
