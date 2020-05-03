#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 304;
const int dy[4] = { -1 , 0 , 1 , 0 };
const int dx[4] = { 0, 1, 0, -1 };

int N, M;
int _map[Max][Max], copy_map[Max][Max];
bool visited[Max][Max];

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny>N || nx < 0 || nx > M || visited[ny][nx] || _map[ny][nx]==0) continue;
		dfs(ny, nx);
	}
}

int check() {
	// 빙산 개수 체크
	fill(&visited[0][0], &visited[0][0] + 304 * 304, false);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (_map[i][j] != 0 && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int icount = 0;
	int time = 0;
	cin >> N >> M;
	// Make Map
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> _map[i][j];
		}
	}

	while (1) {
		// 빙산개수 체크 1개가 아니면 break;
		if ((icount = check()) != 1) break;

		// 1년 지남
		time++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = _map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j]) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (ny<0 || ny>N || nx<0 || nx>M || copy_map[ny][nx] != 0) continue;
						cnt++;
					}
					_map[i][j] = max(copy_map[i][j] - cnt, 0);
				}
			}
		}
	}

	if (icount) cout << time << '\n';
	else cout << 0 << '\n';

	return 0;
}
/*
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0
*/