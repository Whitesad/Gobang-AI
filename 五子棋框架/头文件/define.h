
#ifndef _DEFINE_
#define _DEFINE_

#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

#define blank 0		//空白点
#define black 1		//黑方
#define white 2		//白方
#define inf 1000000		
#define inboard(a,b) (a>0 && a<=15 && b>0 && b<=15)		//用于检验招法是否在棋盘上

#define GRID_NUM 16		
struct point
{
	int x, y;
};


extern int chessBoard[GRID_NUM][GRID_NUM];//声明


#endif

