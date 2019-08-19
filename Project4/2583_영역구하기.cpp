#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int row, col, k, cnt;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int arr[101][101];
int visited[101][101] = { 0, };
vector<int> ans;

void dfs(int y, int x) {
	visited[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			if (nextY >= 0 && nextY < row && nextX >= 0 && nextX < col) {
				if (!arr[nextY][nextX] && !visited[nextY][nextX]) {
					dfs(nextY, nextX);
				}
			}
		}
	}
}

int main() {
	cin >> row >> col >> k;

	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!arr[i][j] && !visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}

	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}