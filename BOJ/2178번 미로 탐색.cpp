#include <iostream>
#include <queue>
using namespace std;

int dy[4] = { 0,1,0,-1 }; //동 남 서 북
int dx[4] = { 1,0,-1,0 }; //시계방향 3 6 9 12
const int Max = 102;
int graph[Max][Max];
bool visited[Max][Max];
int N, M;
int T = 0;
queue<pair<int, int > > q;
void BFS(int y, int x) {
	visited[y][x] = true;
	q.push(make_pair(y, x));
	T++;
	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int nY = q.front().first;
			int nX = q.front().second;
			if (nY == N && nX == M) return;

			q.pop();
			for (int i = 0; i < 4; i++) {
				if (graph[nY + dy[i]][nX + dx[i]] && !visited[nY + dy[i]][nX + dx[i]]) {
					visited[nY + dy[i]][nX + dx[i]] = true;
					q.push(make_pair(nY + dy[i], nX + dx[i]));
				}
			}
		}
		T++;
	}
}
int main() {
	cin >> N >> M; //100이하

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%1d", &graph[y][x]);
		}
	}	
	BFS(1, 1);
	cout << T << '\n';
}