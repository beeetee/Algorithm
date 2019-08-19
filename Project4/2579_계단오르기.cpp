#include<iostream>

using namespace std;

int n;
int stairs[301];
int dp[301];

int Max(int a, int b) {
	return a > b ? a : b;
}


void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}
}

void init() {
	dp[0] = stairs[0];
	dp[1] = Max(stairs[1] + stairs[0], stairs[1]);
	dp[2] = Max(stairs[2] + stairs[0], stairs[2] + stairs[1]);
}

int MaxScore() {
	for (int i = 3; i < n; i++) {
		int case1 = stairs[i] + stairs[i - 1] + dp[i - 3];
		int case2 = stairs[i] + dp[i - 2];
		dp[i] = Max(case1, case2);
	}
	return dp[n - 1];
}

int main() {

	input();
	init();
	cout << MaxScore();

	return 0;
}

