#include <iostream>
using namespace std;

int map[55][55]; //지도
int dx[9] = { -1,0,1,-1,0,1,-1,0,1 };
int dy[9] = { 1,1,1,0,0,0,-1,-1,-1 };
int cnt;
void dfs(int a, int b)
{
	map[a][b] = 0;
	for (int i = 0; i < 9; i++)
	{
		if (map[a + dx[i]][b + dy[i]] == 1)
			dfs(a + dx[i], b + dy[i]);
	}
}
int main()
{
	int w, h;
	while (1)
	{
		cnt = 0;

		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> map[i][j];

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				if (map[i][j] == 1)//땅 찾았을때
					dfs(i, j), cnt++;
			}
		cout << cnt;
	}
	return 0;
}