#include <iostream>
#include <algorithm>
using namespace std;

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

int R, C, M;
int map[102][102];
int move_map[102][102];

struct shake {
	int y, x;
	int speed, dir, size;
	bool life = false;
};
shake S[10001];

void moveDir(int p) {
	int speed = S[p].speed;
	int x = S[p].x;
	int y = S[p].y;
	int r = R - 1;
	int c = C - 1;
	switch (S[p].dir) {
	case 0: // ����
		if (speed > y) {
			speed -= y;
			speed %= r * 2;
			if (speed < r) {
				S[p].dir = 1;
				S[p].y = speed;
			}
			else {
				S[p].y = 2 * r - speed;
			}
		}
		else
			S[p].y -= speed;
		break;
	case 1: // ����
		if (y + speed > r) {
			speed -= r - y;
			speed %= r * 2;
			if (speed < r) {
				S[p].dir = 0;
				S[p].y = r - speed;
			}
			else {
				S[p].y = speed - r;
			}
		}
		else
			S[p].y += speed;
		break;
	case 2: // ��
		if (x + speed > c) {
			speed -= c - x;
			speed %= c * 2;
			if (speed < c) {
				S[p].dir = 3;
				S[p].x = c - speed;
			}
			else {
				S[p].x = speed - c;
			}
		}
		else
			S[p].x += speed;
		break;

	case 3: // ��
		if (speed > x) {
			speed -= x;
			speed %= c * 2;
			if (speed < c) {
				S[p].dir = 2;
				S[p].x = speed;
			}
			else {
				S[p].x = 2 * c - speed;
			}
		}
		else
			S[p].x -= speed;
		break;
	}

	// �̵� �� ū ����⸸ ����
	move_map[S[p].y][S[p].x] = max(move_map[S[p].y][S[p].x], S[p].size);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		if (!map[y - 1][x - 1]) {
			map[y - 1][x - 1] = z;
			S[i] = { y - 1, x - 1, s, d - 1, z, true };
		}
	}

	int res = 0;
	// ���ÿ��� �����̴� ��
	for (int i = 0; i < C; i++) {
		// ����
		for (int j = 0; j < R; j++) {
			// ���� ����
			if (map[j][i]) {
				//cout << i << "�� ° : ũ�� " << map[j][i] << " ���\n";
				res += map[j][i];
				map[j][i] = 0;
				S[map[j][i]].life = false;
				break;
			}
		}

		// ��� �̵�
		for (int p = 0; p < M; p++) {
			// ���� ��� skip
			if (!S[p].life) continue;
			// ������ ���� ��� skip
			if (map[S[p].y][S[p].x] != S[p].size) {
				S[p].life = false;
				continue;
			}
			//cout << " �̵� ��� "<<p<<'\n';
			moveDir(p);
		}

		for (int k = 0; k < R; k++) {
			for (int l = 0; l < C; l++) {
				cout << move_map[k][l] << " ";
				map[k][l] = move_map[k][l];
				move_map[k][l] = 0;
			}
			cout << '\n';
		}

		/*cout << "���� ��� : ";
		for (int p = 0; p < M; p++)
			if (S[p].life && map[S[p].y][S[p].x] == S[p].size)
				cout << p << " ";
		cout << '\n';*/

	}

	cout << res << '\n';
	return 0;
}