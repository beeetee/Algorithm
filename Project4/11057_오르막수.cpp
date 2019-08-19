#include <iostream>
using namespace std;

int N;

int arr[1001][10];

void init() {
	for (int i = 0; i < 10; i++) {
		arr[0][i] = 1;
	}
}

int solve() {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
				arr[i][j] %= 10007;
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < 10; i++) {
		cnt += arr[N - 1][i];
	}
	return cnt;
}

int main() {

	cin >> N;
	init();
	cout << solve() % 10007;

	return 0;
}