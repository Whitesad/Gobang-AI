#pragma once

using namespace std;
//预定义宏常量区
#define _CRT_SECURE_NO_WARNINGS

//预定义库头文件区
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>

//预定义工程头文件区
#include "start.h"
#include "Kizuna.h"
#include "MAP.h"

//预定义类型区
typedef char element;

enum Round {
	Player, AI
};

#define NONE 0
#define WHITE 1
#define BLACK 2


//预定义常量
#define LEN 16

//预定义数据
