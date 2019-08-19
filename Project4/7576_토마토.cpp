#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int col, row;
int box[1001][1001];
queue<pair<int, int>> q;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



void input() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		pair<int, int> tom = q.front();	// auto tom = q.front();
		q.pop();

		int r = tom.first;
		int c = tom.second;

		for (int i = 0; i < 4; i++) {
			int nextR = r + dy[i];
			int nextC = c + dx[i];

			if (nextR < 0 || nextC < 0 || nextR >= row || nextC >= col) {
				continue;
			}
			if (!box[nextR][nextC]) {
				box[nextR][nextC] = box[r][c] + 1;
				q.push({ nextR, nextC });
			}
		}
	}
}

int MAX(int a, int b) {
	return a > b ? a : b;
}

int answer() {
	int max = -1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!box[i][j]) {
				return -1;
			}
			max = MAX(max, box[i][j]);
		}
	}
	return --max;
}

int main()
{
	cin >> col >> row;
	input();
	bfs();
	cout << answer();
}