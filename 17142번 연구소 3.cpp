#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define INF 987654321
using namespace std;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { 1, 0, -1, 0 };

int N, M;
int room[51][51];
int box[51][51];
pair<int, int> virus[11]; // 바이러스 정보
int virusN = 0; // 바이러스 개수
int arr[11]; // 활성 바이러스
int answer = INF;


void debugg() {
	cout << '\n';
	for (int i = 0; i < M; i++) cout << arr[i] << " ";
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] == INF) cout << "* ";
			else if (box[i][j] == -1) cout << "P ";
			else cout << box[i][j]<<" ";
		}
		cout << '\n';
	}
}

int play() {
	vector<pair<int, int> > last[51*51];
	queue<pair<int, int> > q;

	// 비활성화 바이러스 check
	bool check[11] = { false, };

	for (int i = 0; i < M; i++) {
		check[arr[i]] = true;
		box[virus[arr[i]].first][virus[arr[i]].second] = 0;
		q.push({ virus[arr[i]].first, virus[arr[i]].second });
	}

	int step = 0;
	while (!q.empty()) {
		step++;
		int size = q.size();
		while (size--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N || box[ny][nx] >= 0) continue;
				box[ny][nx] = step;
				q.push({ ny, nx });
				last[step].push_back({ ny, nx });
			}
		}
	}
	step--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 확산 못시키는 땅 존재
			if (box[i][j] == -1) { return INF; } 
		}
	}

	// 마지막 step이 비활성화 바이러스만으로 확산된 경우 -1
	map<pair<int, int>, bool> buf;
	for (int i = 0; i < virusN; i++) {
		if (check[i]) continue;
		// 비활성화 바이러스 번호 buf 저장
		buf[{virus[i].first, virus[i].second}] = true;
	}
	for (int k = step; k > 0; k--) {
		bool flag = true;
		int size = last[k].size();
		for (int i = 0; i < size; i++) {
			if (!buf[{last[k][i].first, last[k][i].second}]) {
				flag = false;
				break;
			}
		}
		if (flag) step--;
		else break;
	}

	//debugg();
	//cout << "step : "<<step << '\n';
	return step;
}

void selectVirus(int cnt, int start) {
	// M개 바이러스로 확산 실행
	if (cnt == M) {
		// SandBox를 만들어 확산 진행
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				box[i][j] = room[i][j];
			}
		}

		answer = min(answer, play());
		return;
	}

	for (int i = start; i < virusN; i++) {
		arr[cnt] = i;
		selectVirus(cnt + 1, i + 1);
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> room[i][j];
			if (room[i][j] == 0) room[i][j] = -1;		// 빈칸
			if (room[i][j] == 1) room[i][j] = INF;	//벽
			if (room[i][j] == 2) {
				virus[virusN++] = { i, j };
				room[i][j] = -2;
			}
		}
	}

	selectVirus(0, 0);

	cout << (answer==INF ? -1 : answer) << '\n';
	return 0;
}

/*
5 1
2 2 2 1 1
2 1 1 1 1
2 1 1 1 1
0 1 1 1 1
2 2 2 1 1

5 1
2 2 2 1 1
2 1 1 1 1
2 1 1 1 1
1 1 1 1 1
2 2 2 1 1

5 2
2 2 2 1 1
2 1 1 1 1
2 1 1 1 1
1 1 1 1 1
2 2 2 1 1

5 2
2 1 2 1 0
2 1 1 1 1
0 1 1 1 1
1 1 1 1 1
2 2 2 1 1


*/