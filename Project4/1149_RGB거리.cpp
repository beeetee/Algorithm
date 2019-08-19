#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n;
	int dp[1001][3] = { 0 }; //[i][0]:R, [i][1]:G, [i][2]:B

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]); //R
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]); //G
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]); //B
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

	return 0;
}
