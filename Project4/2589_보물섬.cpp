#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int L, W, Maxdistance = -1;
char tmp;
vector<char> map[51];
bool visited[51][51];
queue<pair<int, int>> q;
int dist[51][51];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int MAX(int a, int b) {
	return a > b ? a : b;
}
void input() {
	cin >> L >> W;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {
			cin >> tmp;
			map[i].push_back(tmp);
		}
	}
}
void bfs(pair<int, int> p) {
	q.push(p);

	pair<int, int> tmp;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			if (nextY < L && nextY >= 0 && nextX < W && nextX >= 0) {
				if (map[nextY][nextX] == 'L' && !visited[nextY][nextX]) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
					dist[nextY][nextX] = dist[y][x] + 1;
					Maxdistance = MAX(Maxdistance, dist[nextY][nextX]);
				}
			}


		}
	}
}
int main()
{
	input();

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 'L') {
				pair<int, int> pos = make_pair(i, j);
				bfs(pos);
				memset(visited, 0, sizeof(visited));
				memset(dist, 0, sizeof(dist));
			}
		}
	}

	cout << Maxdistance;

}