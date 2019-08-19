#include<iostream>
#include<cstdio>
using namespace std;

int arr[100001];
long long sumArr[100001];

long long max(long long a, long long b) {
	if (a > b) return a;
	return b;
}

int main(void) {

	int n;
	long long tmp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sumArr[0] = arr[0];
	tmp = arr[0];

	for (int i = 1; i < n; i++) {
		sumArr[i] = max(sumArr[i - 1] + arr[i], arr[i]);
		tmp = max(sumArr[i], tmp);
	}
	cout << tmp;
	return 0;
}