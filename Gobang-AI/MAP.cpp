#include "define.h"
Map::Map()
{
	memset(MAP, NONE, sizeof(MAP));
	memset(MAP_clone, NONE, sizeof(MAP_clone));
	black_point = 0, white_point = 0;
}
bool Map::isend(point step)
{
	step.color = MAP[step.x][step.y];
	//向下进行检查
	point tem = step;
	int line = 1;
	tem.x++;
	while (tem.judge() && MAP[tem.x][tem.y] == step.color)
		tem.x++, line++;
	//向上进行检查
	tem = step;
	tem.x--;
	while (tem.judge() && MAP[tem.x][tem.y] == step.color)
		tem.x--,line++;
	if (line >= 5)
		return true;
	
	//向左进行检查
	line = 1;
	tem = step;
	tem.y--;
	while (tem.judge() && MAP[tem.x][tem.y] == step.color)
		tem.y--, line++;
	//向右进行检查
	tem = step;
	tem.y++;
	while (tem.judge() && MAP[tem.x][tem.y] == step.color)
		tem.y++, line++;
	if (line >= 5)
		return true;
	
	//向左上
	line = 1;
	tem = step;
	tem.x--, tem.y--;
	while (tem.judge() && MAP[tem.x][tem.y] == step.color)
		tem.x--,tem.y--,line++;
	//向右下
	tem = step;
	tem.x++, tem.y++;
	while (tem.judge() && MAP[tem.x][tem.y] == step.color)
		tem.x++, tem.y++, line++;
	if (line >= 5)
		return true;

	//向右上
	line = 1;
	tem = step;
	tem.x--, tem.y++;
	while (tem.judge() && MAP[tem.x][tem.y] == step.color)
		tem.x--, tem.y++, line++;
	//向左下
	tem = step;
	tem.x++, tem.y--;
	while (tem.judge() && MAP[tem.x][tem.y] == step.color)
		tem.x++, tem.y--, line++;
	if (line >= 5)
		return true;

	return false;
}
void Map::flash_borad(void)
{
	int flag = 0;
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
			if (MAP[i][j] != MAP_clone[i][j])
			{
				gotoxy(1 +2*j,4+i );
				if (MAP[i][j] == WHITE)
					printf("○");
				else
					printf("●");
				flag = 1;
				break;
			}
		if (flag) break;
	}
	memcpy(MAP_clone, MAP, sizeof(MAP));
	gotoxy(0, 20);
	printf("                                       \n");
	printf("                                       \n");
	printf("                                       \n");
	printf("                                       \n");
	printf("                                       \n");
	printf("                                       \n");
	printf("                                       \n");
	printf("                                       \n");
	gotoxy(0, 20);

}
void Map::set(point step)
{
	MAP[step.x][step.y] = step.color;
}