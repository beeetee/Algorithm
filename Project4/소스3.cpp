#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

int main() {
	int T, N;
	
	cin >> T;

	while (T--) {
		cin >> N;

		int arr[1001];
		vector<int> v;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		v.push_back(arr[1] - arr[0]);
		for (int i = 2; i < N; i++) {
			int n = arr[i] - arr[i - 1];
			if (n * v[v.size() - 1] < 0) {
				v.push_back(n);
			}
		}

		cout << v.size() + 1 << endl;

	}
}