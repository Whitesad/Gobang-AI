#include "define.h"
#include "searchmove.h"
#include "printchessboard.h"
int main()
{
	cout << "*************��ӭ�����������˻�����ϵͳ*************" << endl;
	cout << "����: newblack  ��������" << endl;
	cout << "����: newwhite  ���Ժ���" << endl;
	cout << "����: move x y  ��ʾ���ӵ�" << endl; 
	print();
	char input[64];
	while (~scanf("%s", input))
	{
		if (strcmp(input, "newblack") == 0)//��������
		{
			;
		}
		else if (strcmp(input, "newwhite") == 0)//���Ժ���
		{
			;
		}
		else if (input[0] == 'm')//�������
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
c���Ա���ԭ��
ͷ�ļ��÷�
#ifndef��#def��#endif�Ⱥ���÷�
http://www.51hei.com/bbs/dpj-54868-1.html
http://www.51hei.com/bbs/dpj-28952-1.html
http://www.51hei.com/bbs/dpj-46187-1.html

*/