#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

const int dy[4] = { 0,0,1,-1 };
const int dx[4] = { 1, -1, 0, 0 };

int N, L, R;
int map[51][51];
int copy_map[51][51];
int country[51][51];
vector<pair<int, int> > buf;

bool dis(int x, int y) {
	int num = abs(x - y);
	if (L <= num && num <= R) return true;
	return false;
}

bool bfs(int y, int x, int idx) {
	bool flag = false;
	queue<pair<int, int> > q;
	q.push({ y,x });
	buf.push_back({ y,x });

	while (!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (country[ny][nx] != 0) continue;
			if (dis(map[y][x], map[ny][nx])) {
				q.push({ ny, nx });
				buf.push_back({ ny, nx });
				country[ny][nx] = idx;
				flag = true;
			}
		}
	}
	return flag;
}

int solve() {
	memset(country, 0, sizeof(country));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			copy_map[i][j] = map[i][j];
		

	int idx = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (country[i][j]) continue;
			country[i][j] = ++idx;

			// 국경선을 안 열었다면
			if (!bfs(i, j, idx)) {
				country[i][j] = 0;
				idx--;
			}
			// 국경선 이동이 있다면
			else {
				int sum = 0;
				int size = buf.size();
				for (int k = 0; k < size; k++) {
					sum += map[buf[k].first][buf[k].second];
				}
				
				sum /= size;
				for (int k = 0; k < size; k++) {
					copy_map[buf[k].first][buf[k].second] = sum;
				}
			}
			buf.clear();
		}

	return idx;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	while (solve()) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = copy_map[i][j];

		answer++;
	}
			
	cout << answer << '\n';
	return 0;
}