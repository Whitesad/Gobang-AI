#pragma once

using namespace std;
//Ԥ����곣����
#define _CRT_SECURE_NO_WARNINGS

//Ԥ�����ͷ�ļ���
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>

//Ԥ���幤��ͷ�ļ���
#include "start.h"
#include "Kizuna.h"
#include "MAP.h"

//Ԥ����������
typedef char element;

enum Round {
	Player, AI
};

#define NONE 0
#define WHITE 1
#define BLACK 2


//Ԥ���峣��
#define LEN 16

//Ԥ��������
