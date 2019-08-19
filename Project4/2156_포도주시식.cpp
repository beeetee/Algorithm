#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int d[10001];


int main()
{


	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	d[1] = arr[1];           // 1잔이 있을 때 최대 값은 1잔을 마시는 것임
	d[2] = arr[1] + arr[2];  // 2잔이 있을 때 최대 값은 2잔을 모두 마시는 것임

	for (int i = 3; i <= n; i++)
		d[i] = max(max(d[i - 1], d[i - 2] + arr[i]), d[i - 3] + arr[i - 1] + arr[i]);

	cout << d[n] << "\n";
}