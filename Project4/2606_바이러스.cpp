#include <iostream>
#include <vector>
using namespace std;

int comNum;
int number;
int countVirus = 0;
vector<int> com[101];
bool visited[101] = { false, };

void input() {
	for (int i = 0; i < number; i++) {
		int a, b;
		cin >> a >> b;
		com[a].push_back(b);
		com[b].push_back(a);
	}
}

void dfs(int index) {



	for (int i = 0; i < com[index].size(); i++) {
		if (!visited[com[index][i]]) {
			countVirus++;
			visited[com[index][i]] = true;
			dfs(com[index][i]);
		}
	}
}

int main()
{
	cin >> comNum >> number;

	input();
	visited[1] = true;
	dfs(1);




	cout << countVirus;


}