#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_CNT = 10;
const int INF = 987654321;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

class PT {
public:
	int y;
	int x;
	PT() {};
	PT(int y, int x) : x(x), y(y) {};

	void setPt(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

PT R, B, O;
int N, M; // ���� ����
char Map[10][10];

int solution(int cnt, PT r, PT b, int dir) {
	if (cnt > MAX_CNT) return INF;
	int ans = INF;
	
	int ry = r.y;
	int rx = r.x;
	int by = b.y;
	int bx = b.x;
	// ����̱� ����
	if (dir != -1) {

		// �Ķ� �� ������
		while (Map[by + dy[dir]][bx + dx[dir]] == '.') {
			by += dy[dir];
			bx += dx[dir];
			// ���� �����ߴٸ�
			if (by == O.y && bx == O.x)	return INF;
		}
		// ���� �� ������
		while (Map[ry + dy[dir]][rx + dx[dir]] == '.') {
			ry += dy[dir];
			rx += dx[dir];
			// ���� �����ߴٸ�
			if (ry == O.y && rx == O.x) return cnt;
		}

		// ��￴�� �� �������� �����ٸ�
		if (r.y == ry && r.x == rx && b.y == by && b.x == bx) return INF;

		// ���� ���� ��ġ�� �Ķ� ���� ��ġ�� ���� ���
		if (ry == by && rx == bx) {
			switch (dir) {
			// ��
			case 0:
				if (r.y > b.y) ry++;
				else by++;
				break;

			// ��
			case 1:
				if (r.y > b.y) by--;
				else ry--;
				break;

			// ��
			case 2:
				if (r.x > b.x) rx++;
				else bx++;
				break;

			// ��
			case 3:
				if (r.x > b.x) bx--;
				else rx--;
				break;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		ans = min(ans, solution(cnt + 1, PT(ry, rx), PT(by, bx), i));
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			if (c == 'R') {
				R.setPt(i, j);
				Map[i][j] = '.';
			}
			else if (c == 'B') {
				B.setPt(i, j);
				Map[i][j] = '.';
			}
			else if (c == 'O') {
				O.setPt(i, j);
				Map[i][j] = '.';
			}
			else {
				Map[i][j] = c;
			}
		}
	}

	int answer = solution(0, R, B, -1);
	cout << (answer != INF ? answer : -1) << '\n';

	return 0;
}