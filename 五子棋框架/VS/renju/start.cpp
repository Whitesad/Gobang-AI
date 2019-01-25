#include "define.h"
#include "searchmove.h"
#include "printchessboard.h"
int main()
{
	cout << "*************欢迎来到五子棋人机对弈系统*************" << endl;
	cout << "输入: newblack  电脑先手" << endl;
	cout << "输入: newwhite  电脑后手" << endl;
	cout << "输入: move x y  表示落子点" << endl; 
	print();
	char input[64];
	while (~scanf("%s", input))
	{
		if (strcmp(input, "newblack") == 0)//电脑先手
		{
			;
		}
		else if (strcmp(input, "newwhite") == 0)//电脑后手
		{
			;
		}
		else if (input[0] == 'm')//玩家落子
		{
			;
		}
		else
		{
			;
		}
	}
}





/*
c语言编译原理
头文件用法
#ifndef、#def、#endif等宏的用法
http://www.51hei.com/bbs/dpj-54868-1.html
http://www.51hei.com/bbs/dpj-28952-1.html
http://www.51hei.com/bbs/dpj-46187-1.html

*/