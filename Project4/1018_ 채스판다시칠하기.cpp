#include <iostream>
using namespace std;

int row, col;
char chess[51][51];
int answer = 2500;

char blackFirst[8][8] = { {'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'} };
char whiteFirst[8][8] = { {'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'} };

int Min(int a, int b) {
	return a < b ? a : b;
}

int compareFirstBoard(int r, int c) {
	int countBlackFirst = 0;
	int countWhiteFirst = 0;
	for (int i = r; i < r + 8; i++) {
		for (int j = c; j < c + 8; j++) {
			if (chess[i][j] != blackFirst[i - r][j - c]) {
				countBlackFirst++;
			}
			if (chess[i][j] != whiteFirst[i - r][j - c]) {
				countWhiteFirst++;
			}
		}
	}
	return Min(countBlackFirst, countWhiteFirst);
}
void input() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> chess[i][j];
		}
	}
}

void check() {
	for (int i = 0; i <= row - 8; i++) {
		for (int j = 0; j <= col - 8; j++) {
			answer = Min(answer, compareFirstBoard(i, j));
		}
	}
}

int main()
{
	input();
	check();
	cout << answer;
}