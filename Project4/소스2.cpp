#include<iostream>
#include<stdlib.h>

using namespace std;
int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
int RifA[10];

int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			RifA[j * 2] = arr[j];
			RifA[j * 2 + 1] = arr[j + 5];
		}
		memcpy(&arr[0], &RifA[0], sizeof(arr));
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i]<<" ";
	}
}