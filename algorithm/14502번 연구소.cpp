#include <iostream>
#include <queue>
using namespace std;

const int Max = 9;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
int N, M;
int _map[Max][Max];
int result = 0;

void BFS(int y, int x) {
	queue<pair<int, int> > q;
	q.push({ y, x });

	while (!q.empty()) {
		int qy = q.front().first;
		int qx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = qy + dy[i];
			int nx = qx + dx[i];
			if (ny < 0 || ny > N || nx < 0 || nx > M || _map[ny][nx]) continue;
			_map[ny][nx] = 2;
			q.push({ ny, nx });
		}
	}
}

void DFS(int cnt) {
	// 3개의 벽이 만들어 졌다면
	if (cnt == 3) {
		// Map 복사
		int copy_map[Max][Max];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				copy_map[i][j] = _map[i][j];
		// 바이러스 확산
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (copy_map[i][j] == 2) BFS(i, j);
		
		// 바이러스 없는 영역의 갯수
		int clean = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (_map[i][j] == 0) clean++;
		result = max(result, clean);

		// Map 복구
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				_map[i][j] = copy_map[i][j];
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (_map[i][j] == 0) {
				_map[i][j] = 1;
				DFS(cnt + 1);
				_map[i][j] = 0;
			}
		}
	}
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> _map[i][j];	
}
void Solution() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			if (_map[i][j] == 0) {
				_map[i][j] = 1;
				DFS(1);
				_map[i][j] = 0;
			}
		
	cout << result << '\n';
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}