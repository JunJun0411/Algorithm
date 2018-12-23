#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


const int Max = 1000 + 1;
int N, M, V;
int graph[Max][Max];
bool visited[Max];
queue<int> q;

void DFS(int idx) {
	cout << idx << " ";

	for (int i = 1; i <= N; i++) {
		if (graph[idx][i] && !visited[i]) {
			visited[i] = true; //방문했다고 표시
			DFS(i);
		}
	}
}
void BFS(int idx) {
	q.push(idx);
	visited[idx] = true;

	while (!q.empty()) {
		idx = q.front();
		q.pop();

		cout << idx << " ";
		for (int i = 1; i <= N; i++) {
			if (graph[idx][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N;//정점의 개수
	cin >> M;//간선의 개수
	cin >> V;//정점의 번호
	for (int i = 0; i < M; i++) {
		int x1, x2; cin >> x1 >> x2;
		graph[x1][x2] = 1;
		graph[x2][x1] = 1;
	}
	visited[V] = 1;
	DFS(V);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	BFS(V);
	cout << '\n';
	return 0;
}