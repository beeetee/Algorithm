#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101] = { 0, };
int check[101][101] = { 0, };
int dx[] = { -1,0,1,0 };//�ð����
int dy[] = { 0,1,0,-1 };
int n, m;

void BFS(int x, int y) {
	queue<pair<int, int>> q;

	pair<int, int> p;
	p = make_pair(x, y);
	q.push(p);    //q.push(make_pair(x,y));

	check[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {//�����¿� �׹��� Ž��
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (!check[nx][ny] && map[nx][ny]) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = check[x][y] + 1;
				}
				else if (check[nx][ny] == 0)
					check[nx][ny] = -1;
			}
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}//�� �Է¹���

	BFS(0, 0);

	cout << check[n - 1][m - 1] <<endl;
}
