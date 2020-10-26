#include <iostream>
#include <vector>
using namespace std;

const int dy[5] = { 0, -1, 1, 0, 0 };
const int dx[5] = { 0, 0, 0, -1, 1 };

int N, M, K;
pair<int, int> map[21][21]; // ����� ��ȣ, ����� ����
pair<pair<int, int>, int> shake[401]; // ����� ��ġ, ����
int sDir[401][5][5]; // ���� �켱����

void debugg() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j].first << map[i][j].second << "   ";
		}
		cout << '\n';
	}
}

void moving() {
	vector<pair<pair<int, int>, pair<int, int>> > buf; // ��� ��ȣ, ����, ��ǥ
	for (int i = 1; i <= M; i++) {
		if (!shake[i].second) continue; // ���� ���� continue
		int y = shake[i].first.first;
		int x = shake[i].first.second;
		int r = shake[i].second; // ����
//		cout << i<<"�� ��� ��ġ: " << y << ", " << x << '\n';
		bool flag = false;
		for (int j = 1; j <= 4; j++) {
			// ���� �켱���� ���
			int dir = sDir[i][r][j]; 
			int ny = y + dy[dir];
			int nx = x + dx[dir];
//			cout << "��� ��ġ: " << ny << ", " << nx << " ����: " << dir << " �� �� �־�? "<<'\n';
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (map[ny][nx].first != 0) continue; // ������ ���� �ٸ� ����� ������ �ִٸ� �Ȱ���.

			// �� ���� �������ٸ�, ���ۿ� ���
			buf.push_back({ { i , dir } , { ny, nx } });
			flag = true;
//			cout << " O " << '\n';
			break;
		}
		if (!flag) {
			for (int j = 1; j <= 4; j++) {
				// ���� �켱���� ���
				int dir = sDir[i][r][j];
				int ny = y + dy[dir];
				int nx = x + dx[dir];
//				cout << "��� ��ġ: " << ny << ", " << nx << " ����: " << dir << " �� �� �־�? " << map[ny][nx].first << '\n';
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (map[ny][nx].first != i) continue; // ������ ���� �ٸ� ����� ������ �ִٸ� �Ȱ���.

				// �� ���� �������ٸ�, ���ۿ� ���
				buf.push_back({ { i , dir } , { ny, nx } });
//				cout << " O " << '\n';
				break;
			}
		}
	 }

	// ���� �����
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (map[i][j].first) 
				// ���� -1, 0�̶�� ���� �����.
				if ((--map[i][j].second) == 0) 
					map[i][j].first = 0;		
	
	// ��� ��ġ
	int size = buf.size();
	for (int i = 0; i < size; i++) {
		int num = buf[i].first.first;
		int dir = buf[i].first.second;
		int y = buf[i].second.first;
		int x = buf[i].second.second;
		if (map[y][x].first == 0 || map[y][x].first == num) {
			map[y][x].first = num;
			map[y][x].second = K;
			shake[num].first.first = y;
			shake[num].first.second = x;
			shake[num].second = dir;
		}
		else {
			// ���� ��� ǥ��
			shake[num].second = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j].first;
			if (map[i][j].first > 0) {
				map[i][j].second = K;
				shake[map[i][j].first].first.first = i;
				shake[map[i][j].first].first.second = j;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> shake[i].second;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> sDir[i][j][k];
			}
		}
	}

	
	int t;
	for (t = 1; t <= 1000; t++) {
		bool flag = false;
		//cout << "t: " << t << '\n';
	//	debugg();
		// �̵�
		moving();

		// 1�� ��� ���� ����ִ� ��� �ִ��� Ȯ��
		for (int i = 2; i <= M; i++) {
		//	cout << shake[i].second << " ";
			if (shake[i].second) {
				flag = true;
				break;
			}
		}
	//	cout << '\n';
		if (!flag) break;
	}
	cout << (t>1000 ? -1 : t) << '\n';
}