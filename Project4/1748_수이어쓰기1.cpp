#include<iostream>
using namespace std;

int N, ans;

int main() {
	cin >> N;

	for (int i = 1; i <= N; ) {
		ans += (N - i + 1);
		i *= 10;
	}


	cout << ans;
	return 0;
}
