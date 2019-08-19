#include <iostream>
using namespace std;
long long fac(long long num)
{
	static long long mem[13];
	if (mem[num] != 0)
		return mem[num];
	if (num == 0 || num == 1)
	{
		return mem[num] = 1;
	}
	return mem[num] = num * fac(num - 1);
}
int main() {
	long long num;
	cin >> num;
	cout << fac(num);
}
