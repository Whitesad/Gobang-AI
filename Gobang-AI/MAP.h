#pragma once
#ifndef _MAP_H_
#define _MAP_H_
#define LEN 16
#include "define.h"
struct point;
enum Round;
class Map
{
public:
	Map();
	bool isend(point step);
	void flash_borad(void);
	void set(point step);
	char MAP[LEN][LEN];
	char MAP_clone[LEN][LEN];
private:
	int black_point;
	int white_point;
};



#endif // !_MAP_H_
