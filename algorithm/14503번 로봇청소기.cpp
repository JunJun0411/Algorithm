#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int Max = 52;
// 0 : 북, 1 : 동, 2 : 남, 3 : 서
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int N, M, r, c, w;
int room[Max][Max];

void DFS(int y, int x, int way) {
	queue < pair<pair<int, int>, int> >q;
	q.push({ { y, x }, way });
	int cnt = 0;

	while (!q.empty()) {
		int qy = q.front().first.first;
		int qx = q.front().first.second;
		int qw = q.front().second;
		// 청소
		if (room[qy][qx] == 0) {
			room[qy][qx] = 2;
			cnt++;
		}
		q.pop();

		bool flag = false;
		for (int i = 0; i < 4; i++) {
			// 왼쪽 방향
			int nw = (qw + (3 - i)) % 4;
			int ny = qy + dy[nw];
			int nx = qx + dx[nw];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
				if (!room[ny][nx]) {
					q.push({ { ny, nx }, nw });
					flag = true;
					break;
				}
		}

		// 네 방향 모두 청소할 수 없다면
		if (!flag) {
			int nw = (qw + 2) % 4;
			int ny = qy + dy[nw];
			int nx = qx + dx[nw];

			if ((ny >= 0 && ny < N && nx >= 0 && nx < M) && room[ny][nx] != 1) {
				q.push({ {ny, nx}, qw });
			}
			else
				break;
		}
	}
	cout << cnt << '\n';
	return;
}

void Input() {
	cin >> N >> M;
	cin >> r >> c >> w;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> room[i][j];
}

void Solution() {
	// 청소 시작
	DFS(r, c, w);
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