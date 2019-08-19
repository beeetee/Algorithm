#include<iostream>
using namespace std;

int mp[51][51];
bool visit[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int T, M, N, K;
int cnt;
int column, row;


void dfs(int x, int y){
	visit[x][y] = true;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			if (mp[nx][ny] && !visit[nx][ny])
			{
				visit[nx][ny] = true;
				dfs(nx, ny);
			}
		}
	}
}

void init(){
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			mp[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

int main()
{
	cin >> T;

	while (T--)
	{
		init();
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> column >> row;
			if (0 <= column && column < M && 0 <= row && row < N)
			{
				mp[row][column] = 1;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (mp[i][j] && !visit[i][j])
				{
					dfs(i, j);
					cnt++;
				}

			}
		}
		cout << cnt << endl;
	}
	return 0;
}