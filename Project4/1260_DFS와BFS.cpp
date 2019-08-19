#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001];
int vertex, edge, start; //정점, 간선, 시작점
int dfsVisit[1001];	//DFS 경로를 구할 때 방문을 체크할 배열
int bfsVisit[1001]; //BFS 경로를 구할 때 방문을 체크할 배열

void inputAndInit() {
	ios_base::sync_with_stdio(false);

	cin >> vertex >> edge >> start;
	for (int i = 1; i <= edge; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;

		graph[temp1][temp2] = 1;
		graph[temp2][temp1] = 1;
	}
}

//DFS 재귀를 사용
void printDFS(int x) {
	dfsVisit[x] = 1;
	cout << x << " ";
	for (int i = 1; i <= vertex; i++) {
		if (graph[x][i] == 1 && dfsVisit[i] == 0) {
			printDFS(i);
		}
	}
}

//BFS 큐를 사용
void printBFS() {
	cout << "\n";
	int curr = start;
	bfsVisit[curr] = 1;

	queue<int> q;
	q.push(curr);

	while (!q.empty()) {
		curr = q.front();
		q.pop();
		cout << curr << " ";
		for (int i = 1; i <= vertex; i++) {
			if (graph[curr][i] == 1 && bfsVisit[i] == 0) {
				q.push(i);
				bfsVisit[i] = 1;
			}
		}
	}
	cout << "\n";
}

int main() {
	inputAndInit();	 //입력 및 초기화
	printDFS(start); //DFS 경로를 출력
	printBFS();		 //BFS 경로를 출력
}