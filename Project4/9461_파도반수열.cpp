#include <iostream>
using namespace std;

int main()
{
	long long p[101];

	for (int i = 1; i <= 3; i++) {
		p[i] = 1;
	}
	for (int i = 4; i <= 5; i++) {
		p[i] = 2;
	}
	p[6] = 3;

	for (int i = 7; i <= 100; i++) {
		p[i] = p[i - 2] + p[i - 3];
	}

	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		cout << p[n] << endl;
	}

}
