#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_MAP_SIZE = 501;
const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { -1, 1, 0, 0 };
int N, M;
int map[MAX_MAP_SIZE][MAX_MAP_SIZE];
bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE];
int answer = 0;

void dfs2(int y, int x, int cnt, int sum) {
	// 기저 사례
	if (cnt == 4) {
		answer = max(answer, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
		// 방문기록
		visited[ny][nx] = true;
		dfs2(y, x, cnt + 1, sum + map[ny][nx]);
		visited[ny][nx] = false;
	}
}
void dfs(int y, int x, int cnt, int sum) {
	// 기저 사례
	if (cnt == 4) {
		answer = max(answer, sum);
		return;
	}

	// ㅓ, ㅗ, ㅏ, ㅜ 처리
	if (cnt == 2) {
		int q = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
			// 방문기록
			visited[ny][nx] = true;
			dfs2(y, x, cnt + 1, sum + map[ny][nx]);
			visited[ny][nx] = false;
		}
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
		// 방문기록
		visited[ny][nx] = true;
		dfs(ny, nx, cnt + 1, sum + map[ny][nx]);
		visited[ny][nx] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 방문기록
			visited[i][j] = true;
			dfs(i, j, 1, map[i][j]);
			visited[i][j] = false;
		}
	}

	cout << answer << '\n';
	return 0;
}