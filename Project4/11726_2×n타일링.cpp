#include <iostream>
using namespace std;

int main(void) {

	int Dp[1010] = {1,1};
	int n;

	cin >> n;

	for (int i = 2; i <= n; i++)
		Dp[i] = (Dp[i - 1] + Dp[i - 2]) % 10007;

	cout << Dp[n] % 10007;
	return 0;
}