#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, cnt = 0;
vector<int> num;
vector<int> map[26];
bool visited[26][26];


int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void input() {
	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] == '0') {
				map[i].push_back(0);
			}
			else {
				map[i].push_back(1);
			}
		}
	}
}

void output() {
	sort(num.begin(), num.end());
	cout << num.size() << endl;
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << endl;
	}
}

void dfs(pair<int, int> p) {
	for (int i = 0; i < 4; i++) {
		int nextY = p.first + dy[i];
		int nextX = p.second + dx[i];

		if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N) {
			if (map[nextY][nextX] && !visited[nextY][nextX]) {
				visited[nextY][nextX] = true;
				cnt++;
				dfs(make_pair(nextY, nextX));
			}
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				cnt++;
				dfs(make_pair(i, j));
				num.push_back(cnt);
				cnt = 0;
			}
		}
	}
}

int main()
{
	input();
	solve();
	output();
}