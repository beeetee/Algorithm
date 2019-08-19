#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;

int main() {

	int a, b, na=0, nb=0;

	cin >> a >> b;

	stack<int> StA;
	stack<int> StB;

	int ans = a + b;

	while (a > 0) {
		StA.push(a % 10);
		a /= 10;
	}

	while(b > 0) {
		StB.push(b % 10);
		b /= 10;
	}

	int ten = 1;
	while (!StA.empty()) {
		na += (StA.top()*ten);
		StA.pop();
		ten *= 10;
	}
	ten = 1;
	while (!StB.empty()) {
		nb += (StB.top()*ten);
		StB.pop();
		ten *= 10;
	}

	int ans2 = na + nb;
	cout << abs(ans - ans2);
}