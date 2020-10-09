#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, K, M, N, X, Y;
int Bachubat[51][51];
bool visited[51][51];

void BFS(int x, int y, int m, int n) {
	queue<pair<int, int> > q;
	q.push({ x, y });

	int x0, x1, x2, y0, y1, y2;
	
	while (!q.empty()) {
		x1 = q.front().first;
		y1 = q.front().second;
		q.pop();

		x0 = x1 - 1; x2 = x1 + 1;
		y0 = y1 - 1; y2 = y1 + 1;

		if (x2 < m &&Bachubat[x2][y1] && !visited[x2][y1]) {
			visited[x2][y1] = true;
			q.push({ x2, y1 });
		}
		if (x0 >= 0 && Bachubat[x0][y1] && !visited[x0][y1]) {
			visited[x0][y1] = true;
			q.push({ x0, y1 });
		}
		if (y2 < n&&Bachubat[x1][y2] && !visited[x1][y2]) {
			visited[x1][y2] = true;
			q.push({ x1, y2 });
		}
		if (y0 >= 0 && Bachubat[x1][y0] && !visited[x1][y0]) {
			visited[x1][y0] = true;
			q.push({ x1, y0 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	queue<int> ans;
	for (int t = 0; t < T; t++) {
		int sum = 0;
		memset(Bachubat, 0, sizeof(Bachubat));
		memset(visited, false, sizeof(visited));
		cin >> M >> N>>K;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			Bachubat[X][Y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (Bachubat[i][j] && !visited[i][j]) {
					visited[i][j] = true;
					BFS(i, j, M, N);
					sum++;
				}
			}
		}
		ans.push(sum);
	}
	while (!ans.empty()) {
		cout << ans.front() << '\n';
		ans.pop();
	}
	return 0;
}