#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };

int T, I;
pair<int, int> start, endPos;

vector<vector<int>> arr;
int visited[301][301];

void init() {
	arr = vector<vector<int>>(2, vector<int>(I + 1, 0));
	memset(visited, 0, sizeof(visited));
}

void input() {
	cin >> I;
	cin >> start.first >> start.second;
	cin >> endPos.first >> endPos.second;

}

bool reachEnd(pair<int, int> curr) {
	return curr.first == endPos.first && curr.second == endPos.second ? true : false;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push(start);

	visited[start.first][start.second] = 1;

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		if (reachEnd(curr)) {
			cout << --visited[curr.first][curr.second] << endl;
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nextY = curr.first + dy[i];
			int nextX = curr.second + dx[i];



			if (nextY < I && nextY >= 0 && nextX < I && nextX >= 0) {
				if (!visited[nextY][nextX]) {
					visited[nextY][nextX] = visited[curr.first][curr.second] + 1;
					q.push(make_pair(nextY, nextX));
				}
			}

		}
	}
}

int main() {

	cin >> T;

	while (T--) {
		input();
		init();
		bfs();
	}

	return 0;
}