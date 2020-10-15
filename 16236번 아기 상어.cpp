#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

int N;
int map[21][21];
int shake[4]; // y, x, 크기, 먹은 물고기 수
vector<pair<int, int> > fish;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}


int search() {
	queue<pair<int, int> > q;
	bool visited[21][21] = { false, };
	visited[shake[0]][shake[1]] = true;
	q.push({ shake[0], shake[1] });
	int step = 0;
	bool flag = false;

	while (!q.empty()) {
		int size = q.size();
		step++;
		while (size--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || (map[ny][nx] != INF && map[ny][nx] > shake[2])) continue;
				q.push({ ny, nx });
				visited[ny][nx] = true;
				// 찾으면 fish에 저장
				if (map[ny][nx] < shake[2]) {
					fish.push_back({ ny, nx });
					flag = true;
					//cout << step <<"만큼 떨어진 물고기 찾았다" << '\n';
				}
			}
		}
		if (flag) break;
	}

	// 작은 물고기 없으면
	if (!flag) return 0;
	return step;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			// 상어위치 등록
			if (map[i][j] == 0) map[i][j] = INF;
			if (map[i][j] == 9) {
				map[i][j] = INF;
				shake[0] = i;
				shake[1] = j;
				shake[2] = 2; // 크기
				shake[3] = 0; // 잡아먹은 물고기 수
			}
		}
	}
	int dis = 0;
	int answer = 0;
	while (dis = search()) {
		answer += dis;
		sort(fish.begin(), fish.end(), cmp);
		int y = fish[0].first;
		int x = fish[0].second;
		//cout<<"고기위치: " << y <<", "<< x <<" - "<<dis << "거리 떨어진 고기 크기: "<< map[y][x] <<'\n';
		// 잡아먹고 shake 초기화 fish 버퍼 초기화
		map[y][x] = INF;
		shake[0] = y;
		shake[1] = x;
		if (++shake[3] == shake[2]) {
			shake[2]++; // 몸집 커지고
			shake[3] = 0; // 다시 잡아먹은 물고기 처음부터 시작
		}
		//cout << "상어위치 이동: " << shake[0] << ", " << shake[1] <<", 크기 : " << shake[2] <<'\n';
		fish.clear();
		//cout << '\n';
	}
	cout << answer << '\n';
}