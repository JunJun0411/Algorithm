#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int Max = 1001;
int graph[Max][Max];
int visited[Max];
queue<int> q;
int N, M; //정점의 개수, 간선의 개수


void BFS(int idx) {
	q.push(idx);
	visited[idx] = true;

	while (!q.empty()) {
		idx = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[idx][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int n = 0;
	for (int i = 0; i < M; i++) {
		int x1, x2; cin >> x1 >> x2;
		graph[x1][x2] =1 ;
		graph[x2][x1] =1 ;
	}
	for (int i = 1; i <= N; i++) {

		if (visited[i] == false) {
			BFS(i);
			n++;
		}
	}
	cout << n << " ";
}
