#include<iostream>
#include<stdlib.h>

using namespace std;

int a, b;

int MAX(int a, int b) {

	return a > b ? a : b;
}

int main() {
	int ans;
	int x, y, z;

	cin >> x >> y >> z;

	int max = MAX(x, MAX(y, z));
	int xy = (x + y + z) - max;

	ans = max - xy;
	ans = ans < 0 ? 0 : ans + 1;
	cout << ans << endl;
}