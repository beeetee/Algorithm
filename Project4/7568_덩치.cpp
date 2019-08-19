#include <iostream>
#include <vector>
using namespace std;

int N, x, y;
vector<pair<int, int>> table;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		table.push_back(make_pair(x, y));
	}
}
void solve() {
	for (int i = 0; i < N; i++) {
		int score = 0;
		for (int j = 0; j < N; j++) {
			if (table[i].first < table[j].first &&
				table[i].second < table[j].second) {
				score++;
			}
		}
		cout << ++score << " ";
	}
}
int main()
{
	input();
	solve();
}