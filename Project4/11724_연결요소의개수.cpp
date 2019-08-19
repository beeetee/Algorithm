#include <iostream>
#include <vector>
using namespace std;


int M, N;
vector<int> graph[1001];
bool visited[1001];

void DFS(int node) {
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next])

			DFS(next);

	}
}


int main(void){

	cin >> N >> M;

	for (int i = 0; i < M; i++){

		int node1, node2;

		cin >> node1 >> node2;

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {

		if (!visited[i]){
			DFS(i);
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;

}