#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
const int dx[8] = { 1, 0, -1, 1, 1, 0, -1, -1 };

int N, M, K;
int map[11][11];
int add[11][11];

vector<int> vec[11][11];

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int size = vec[i][j].size();
			if (size == 0) continue;
			int dead = 0;
			vector<int> buf;

			sort(vec[i][j].begin(), vec[i][j].end(), greater<int>());
			for (int k = size - 1; k >= 0; k--) {
				int age = vec[i][j][k];
				// 양분섭취 못하고 사망
				if ((map[i][j] -= age) < 0) {
					map[i][j] += age;
					dead += age / 2;
				}
				else {
					buf.push_back(age + 1);
				}
			}
			vec[i][j].clear();
			for (int k = 0; k < buf.size(); k++) {
				vec[i][j].push_back(buf[k]);
			}

			// 거름
			map[i][j] += dead;
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int size = vec[i][j].size();
			if (size == 0) continue;
			for (int k = 0; k < size; k++) {
				if (vec[i][j][k] % 5) continue;
				for (int l = 0; l < 8; l++) {
					int ny = i + dy[l];
					int nx = j + dx[l];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
					vec[ny][nx].push_back(1); 
				}
			}
		}
	}
}

void winter() {
	// 양분 주기
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			map[i][j] += add[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			map[i][j] = 5;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> add[i][j];
		}

	int y, x, age;
	for (int i = 0; i < M; i++) {
		cin >> y >> x >> age;
		vec[y - 1][x - 1].push_back(age);
	}

	while (K--) {
		// 봄, 여름
		spring();
		fall();
		//debugg();
		// 겨울
		winter();
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			answer += vec[i][j].size();

	cout << answer << '\n';
	return 0;
}