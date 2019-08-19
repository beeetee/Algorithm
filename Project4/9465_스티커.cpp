#include <iostream>
#include <vector>

using namespace std;
int T, n;
vector<vector<int>> arr;
vector<vector<int>> dp;

void input() {

	cin >> n;
	arr = vector<vector<int>>(2, vector<int>(n + 1, 0));
	dp = vector<vector<int>>(2, vector<int>(n + 1, 0));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void init() {
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];

	dp[0][1] = dp[1][0] + arr[0][1];
	dp[1][1] = dp[0][0] + arr[1][1];
}

int MAX(int a, int b) {
	return a > b ? a : b;
}

void solve() {
	for (int i = 2; i < n; i++) {
		dp[0][i] = arr[0][i] + MAX(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = arr[1][i] + MAX(dp[0][i - 1], dp[0][i - 2]);
	}
}

int main() {
	cin >> T;

	while (T--) {
		input();

		init();

		solve();

		cout << MAX(dp[0][n - 1], dp[1][n - 1]) << endl;
	}

	return 0;
}
