#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001];
int vertex, edge, start; //����, ����, ������
int dfsVisit[1001];	//DFS ��θ� ���� �� �湮�� üũ�� �迭
int bfsVisit[1001]; //BFS ��θ� ���� �� �湮�� üũ�� �迭

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

//DFS ��͸� ���
void printDFS(int x) {
	dfsVisit[x] = 1;
	cout << x << " ";
	for (int i = 1; i <= vertex; i++) {
		if (graph[x][i] == 1 && dfsVisit[i] == 0) {
			printDFS(i);
		}
	}
}

//BFS ť�� ���
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
	inputAndInit();	 //�Է� �� �ʱ�ȭ
	printDFS(start); //DFS ��θ� ���
	printBFS();		 //BFS ��θ� ���
}