#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int Max = 102;
const int dy[4] = { 0, 1, 0 ,-1 };
const int dx[4] = { 1, 0, -1, 0 };
int _map[Max][Max], nmap[Max][Max], N;


void dfs(int y, int x, int num) {
	nmap[y][x] = num;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny > N || nx <0 || nx > N || _map[ny][nx] == 0 || nmap[ny][nx]) continue;
		dfs(ny, nx, num);
	}
}

int bfs(int y, int x, int num) {
	bool visited[Max][Max] = { false, };
	queue<pair<int, int> > Q;
	Q.push({ y, x });
	int step = 0;

	while (!Q.empty()) {
		int size = Q.size();
		//cout << step << '\n';
		while (size--) {
			int qy = Q.front().first;
			int qx = Q.front().second;
			Q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = qy + dy[i];
				int nx = qx + dx[i];
				if (ny<0 || ny > N || nx <0 || nx > N || nmap[ny][nx] == num || visited[ny][nx]) continue;
				if (nmap[ny][nx] != 0) return step;
				visited[ny][nx] = true;

				Q.push({ ny, nx });
			}
		}
		step++;
	}
	return Max * 3;
}

int main() {
	ios::ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> _map[i][j];
		}
	}

	// 섬마다 번호를 다르게 매기자
	fill(&nmap[0][0], &nmap[0][0] + Max * Max, 0);
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!nmap[i][j] && _map[i][j]) {
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}

	//각 섬에서 다른 번호의 섬을 만날때까지 최소값 구하자
	int Min = Max * 3;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (_map[i][j])
				Min = min(bfs(i, j, nmap[i][j]), Min);
		}
	}
	cout << Min << '\n';

	return 0;
}

/*
10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
*/