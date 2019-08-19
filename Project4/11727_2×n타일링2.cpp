#include <iostream>
using namespace std;

int dp[1001] = { 0, 1, 3 };

int solve(int n) {
	if (dp[n]) return dp[n];

	return dp[n] = (solve(n - 1) % 10007 + 2 * solve(n - 2) % 10007) % 10007;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n);
}