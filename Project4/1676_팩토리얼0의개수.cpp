#include <iostream>
using namespace std;
int main()
{
	int n;
	int two = 0, five = 0;
	int i;

	cin >> n;

	for (i = 2; i <= n; i *= 2) {
		two += n / i;
	}
	for (i = 5; i <= n; i *= 5) {
		five += n / i;
	}
	int ans = two < five ? two : five;
	cout << ans;

	return 0;
}