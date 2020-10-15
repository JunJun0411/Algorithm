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
int shake[4]; // y, x, ũ��, ���� ����� ��
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
				// ã���� fish�� ����
				if (map[ny][nx] < shake[2]) {
					fish.push_back({ ny, nx });
					flag = true;
					//cout << step <<"��ŭ ������ ����� ã�Ҵ�" << '\n';
				}
			}
		}
		if (flag) break;
	}

	// ���� ����� ������
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
			// �����ġ ���
			if (map[i][j] == 0) map[i][j] = INF;
			if (map[i][j] == 9) {
				map[i][j] = INF;
				shake[0] = i;
				shake[1] = j;
				shake[2] = 2; // ũ��
				shake[3] = 0; // ��Ƹ��� ����� ��
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
		//cout<<"�����ġ: " << y <<", "<< x <<" - "<<dis << "�Ÿ� ������ ��� ũ��: "<< map[y][x] <<'\n';
		// ��Ƹ԰� shake �ʱ�ȭ fish ���� �ʱ�ȭ
		map[y][x] = INF;
		shake[0] = y;
		shake[1] = x;
		if (++shake[3] == shake[2]) {
			shake[2]++; // ���� Ŀ����
			shake[3] = 0; // �ٽ� ��Ƹ��� ����� ó������ ����
		}
		//cout << "�����ġ �̵�: " << shake[0] << ", " << shake[1] <<", ũ�� : " << shake[2] <<'\n';
		fish.clear();
		//cout << '\n';
	}
	cout << answer << '\n';
}