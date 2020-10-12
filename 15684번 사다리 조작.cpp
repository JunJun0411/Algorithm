#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, H;
int map[31][11];
int answer = INF;

bool play() {
	for (int i = 0; i < N; i++) {
		int nx = i;
		for (int j = 0; j < H; j++) {
			//y ��ǥ = i
			int dir = map[j][nx];

			if (dir == -1) { // ���� ��ٸ� ����
				nx++;
			}
			else if (dir == -2) {// ���� ��ٸ� ����
				nx--;
			}
		}
		//cout << i << ": " << nx << '\n';
		if (i != nx) return false;
	}
	
	return true; // ����
}

int dfs(int y, int x, int cnt, int n) {
	
	if (cnt == n) {
		//cout << '\n';
		if (play()) {
			return n;
		}
		return -1;
	}

	for (int i = y; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] < 0 || map[i][j + 1] < 0 || (i == y && j < x)) { continue; }
			map[i][j] = -1;
			map[i][j + 1] = -2;
			//cout << i << ", " << j << " - (" << cnt<<")  ";
			if (dfs(i, j, cnt + 1, n) == n) { return n; }
			map[i][j] = 0;
			map[i][j + 1] = 0;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;

	// ��ٸ� ��ġ �Է�
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = -1;
		map[a - 1][b] = -2;
	}

	// ¦���� ��ġ �Ǿ� �ִ� ���
	if (M % 2 == 0) {
		if (play()) {
			answer = 0;
		}
		else {
			//�ٸ� 2�� �̱�
			answer = dfs(0, 0, 0, 2);
		}
	}
	else { // Ȧ���� ��ġ �Ǿ� �ִ� ���
		// ��ٸ� 1�� ��ġ
		answer = dfs(0, 0, 0, 1);
		if (answer != 1) {
			// ��ٸ� 3�� ��ġ
			answer = dfs(0, 0, 0, 3);
		}
	}

	cout << answer << '\n';

	return 0;
}