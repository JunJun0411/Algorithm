#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { 1, 0, -1, 0 };

int N, M;
int map[51][51];
int box[51][51];
pair<int, int> virus[11]; // ���̷��� ����
int virusN = 0; // ���̷��� ����
int arr[11];
int answer = INF;

// ������ Ȯ�� ��ġ ����
pair<int, int> last[51*51];
int lastN = 0;

int play() {
	int step = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		lastN = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (box[i][j] != step) continue;
				
				// 4 ���� Ȯ��
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N || box[ny][nx] >= 0) continue;
					box[i][j] = step + 1;
					last[lastN].first = i;
					last[lastN++].second = j;
					flag = true; // Ȯ���ߴٸ�
				}
			}
		}
		step++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << box[i][j];
			}
			cout << '\n';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] == -1) {
				return INF;
			}
		}
	}
	return step;
}

void selectVirus(int cnt, int start) {
	// M�� ���̷����� Ȯ�� ����
	if (cnt == M) {
		// SandBox�� ����� Ȯ�� ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				box[i][j] = map[i][j];
			}
		}

		// ��Ȱ��ȭ ���̷��� check
		bool check[11] = { false, };
		
		for (int i = 0; i < M; i++) {
			check[arr[i]] = true;
			box[virus[arr[i]].first][virus[arr[i]].second] = 0;
		}
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " : " << virus[arr[i]].first << virus[arr[i]].second<<" ";
		}

		int step = play();
		cout << "step: "<<step << '\n';
		if (step == INF) return;

		// ������ step�� ��Ȱ��ȭ ���̷��������� Ȯ���� ��� -1
		vector<int> buf;
		for (int i = 0; i < virusN; i++) {
			if (check[i]) continue;
			// ��Ȱ��ȭ ���̷��� ��ȣ buf ����
			buf.push_back(i);
		}

		bool flag = false;
		int size = buf.size();
		for (int i = 0; i < lastN; i++) {
			flag = false;
			for (int k = 0; k < size; k++) {
				if (last[i].first == virus[buf[k]].first && last[i].second == virus[buf[k]].second) {
					flag = true;
				}
			}
			if (!flag) break;
		}
		if (flag) step--;

		answer = min(answer, step);
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
			cin >> map[i][j];
			if (map[i][j] == 0) map[i][j] = -1;		// ��ĭ
			if (map[i][j] == 1) map[i][j] = INF;	//��
			if (map[i][j] == 2) {
				virus[virusN++] = { i, j };
				map[i][j] = -2;
			}
		}
	}

	selectVirus(0, 0);

	cout << answer << '\n';
	return 0;
}