#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int countNumber = 0;


int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i < 100)
			countNumber++;
		else {
			int n1 = i % 10;
			int n2 = (i / 10) % 10;
			int n3 = i / 100;
			if (n1 - n2 == n2 - n3) {
				countNumber++;
			}
		}
	}

	cout << countNumber;
}