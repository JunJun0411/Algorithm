#include <iostream>
#include <cstring>
using namespace std;

int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };//³² ³²¼­ ¼­ ºÏ¼­ ºÏ ºÏµ¿ µ¿ ³²µ¿
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int Max = 50;
int graph[Max][Max];
bool visited[Max][Max];
int M, N;

void DFS(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
			if (graph[nextY][nextX] && !visited[nextY][nextX]) {
				visited[nextY][nextX] = true;
				DFS(nextY, nextX);
			}
		}
	}
}
int main() {
	
	while(1) {
	cin >> M >> N; int cnt = 0;
		if (N == 0 && M == 0) return 0;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> graph[y][x];
			}
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (graph[y][x] && !visited[y][x]) {
					visited[y][x] = true;
					DFS(y, x);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		
		for (int i = 0; i < Max; i++) {
			memset(visited[i], false, sizeof(visited[i]));
			memset(graph[i], 0, sizeof(visited[i]));
		}
	}
}