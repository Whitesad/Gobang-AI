#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int StrMap[11][11] = {			// 保存每个单位三角形代表的数字
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 3, 5, 0, 0, 0, 0, 0 },
	{ 0, 2, 1, 0, 0, 6, 8, 0, 0, 0, 0 },
	{ 0, 0, 3, 0, 0, 4, 0, 9, 11,0, 0 },
	{ 0, 0, 5, 6, 4, 0, 7, 0, 12,14,0 },
	{ 0, 0, 0, 8, 0, 7, 0, 0, 0, 15,17 },
	{ 0, 0, 0, 0, 9, 0, 0, 0, 10,0, 0 },
	{ 0, 0, 0, 0, 11,12,0, 10,0, 13, 0 },
	{ 0, 0, 0, 0, 0, 14,15,0, 13, 0, 16 },
	{ 0, 0, 0, 0, 0, 0, 17,0, 0, 16,0 },
};
int tri[9] = { 7, 56, 98, 448, 3584, 6160, 28672, 49280, 229376 };
int end_state = (1 << 18) - 1; // 所有边，即2^0+2^1+2^2+...+2^16+2^17=2^18-1
int calc(int cur_state, int new_state)
{
	int cnt = 0;
	for (int i = 0; i < 9; i++)
		if ((cur_state&tri[i]) != tri[i] && (new_state &tri[i]) == tri[i])cnt++;
	//这个意思即旧图与边权取公共部分是没有的，而新图是有的，&的操作是有1为1，即可理解为取公共，因为cur_state和new_state‘包含’tri[i]（不好解释的样子。。。这个题的位操作实在太巧妙了！）
	return cnt;
}
int alphabeta(int player, int cur_state, int alpha, int beta, int ca, int cb)
{
	if (ca >= 5)return 1;
	if (cb >= 5)return -1;
	int remain = (~cur_state)&end_state;
	while (remain)
	{
		int move = remain & (-remain);//你可以理解为可选的边已经按数值从大到小排好序，这个步骤就是取当前最大的数值边
		int tmp = calc(cur_state, cur_state | move);
		int ta = ca, tb = cb;
		player ? tb += tmp : ta += tmp;
		int v;
		if (tmp)v = alphabeta(player, cur_state | move, alpha, beta, ta, tb);
		else v = alphabeta(player ^ 1, cur_state | move, alpha, beta, ta, tb);
		player ? beta = min(beta, v) : alpha = max(alpha, v);
		if (beta <= alpha)break;
		remain -= move;
	}
	return player ? beta : alpha;
}
int main()
{
	int T, w = 0, n;
	scanf("%d", &T);
	while (T--)
	{
		int cur_state = 0; // 当前局面
		int ca = 0; // A 的得分
		int cb = 0; // B 的得分
		int alpha = -1, beta = 1;
		int player = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			int tmp = calc(cur_state, cur_state | 1 << StrMap[u][v]);
			player ? cb += tmp : ca += tmp;
			if (!tmp) player ^= 1;
			cur_state = cur_state | 1 << StrMap[u][v];
		}
		int ans = alphabeta(player, cur_state, alpha, beta, ca, cb);
		printf("Game %d: %c wins.\n", ++w, ans > 0 ? 'A' : 'B');
	}
	return 0;
}