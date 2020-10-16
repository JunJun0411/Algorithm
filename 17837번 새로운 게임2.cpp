#include <iostream>
#include <vector>
using namespace std;

// �� �� �� ��
const int dy[5] = { 0, 0, 0, -1, 1 };
const int dx[5] = { 0, 1, -1, 0, 0 };
const int cdir[5] = { 0, 2, 1, 4, 3 };
int N, K;
int chess[15][15];
vector<pair<int, int> >horse[15][15]; // �� ��ȣ, ��������
pair<int, int> pos[11];

bool turn() {
	for (int i = 0; i < K; i++) {
		int y = pos[i].first, x = pos[i].second;
		int size = horse[y][x].size();
		int num, dir;
		
		for (int j = 0; j < size; j++) {
			if (horse[y][x][j].first == i) {
				// ���� ������ �ش� ĭ�� ���° ���̿� �ִ��� num�� ����
				dir = horse[y][x][j].second;
				num = j;
				break;
			}
		}

		// �̵� �Ϸ��� ĭ�� �� Ȯ��
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 1 || ny > N || nx < 1 || nx > N || chess[ny][nx] == 2) { // ������ ����ų� �Ķ����� ���
			//cout << i << "�� ��: " << " - "<< ny << ", " << nx << '\n';
			horse[y][x][num].second = cdir[dir]; // ���� ��ȯ
			dir = horse[y][x][num].second;
			ny = y + dy[dir];
			nx = x + dx[dir];
			// ������ȯ �Ŀ��� �Ķ����̸� continue
			if (chess[ny][nx] == 2) continue; 
		}
		//cout << num << " " << size << '\n';
		vector<pair<int, int> > buf;
		// ����� ���
		if (chess[ny][nx] == 0) {
			for (int j = num; j < size; j++) {
				buf.push_back({ horse[y][x][j].first, horse[y][x][j].second });
			}
			for (int j = num; j < size; j++) {
				horse[y][x].pop_back();
			}
		}
		// �������� ���
		else if (chess[ny][nx] == 1) {
			for (int j = size-1; j >= num; j--) {
				buf.push_back({ horse[y][x][j].first, horse[y][x][j].second });
			}
			for (int j = num; j < size; j++) {
				horse[y][x].pop_back();
			}
		}
		//cout << i << "�� ��: " << ny << ", " << nx << '\n';

		size = buf.size();
		for (int j = 0; j < size; j++) {
			// �̵��� ������ ��ġ ���� ���� Update
			pos[buf[j].first].first = ny;
			pos[buf[j].first].second = nx;
			horse[ny][nx].push_back({ buf[j].first, buf[j].second });
		}
		if (horse[ny][nx].size() >= 4) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= N+1; j++) {
			if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {
				chess[i][j] = 2;
			}
			else
				cin >> chess[i][j];
		}
	}
	/*for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			cout << chess[i][j];
		}
		cout << '\n';
	}*/


	for (int i = 0; i < K; i++) {
		int y, x, dir;
		cin >> y >> x >> dir;
		horse[y][x].push_back({ i, dir });
		pos[i] = { y , x };
	}
	int t;
	bool flag = false;
	for (t = 1; t <= 1000; t++) {
		//for (int i = 0; i < K; i++) {
		//	int y = pos[i].first, x = pos[i].second;
		//	int size = horse[y][x].size();
		//	int num, dir;

		//	for (int j = 0; j < size; j++) {
		//		if (horse[y][x][j].first == i) {
		//			// ���� ������ �ش� ĭ�� ���° ���̿� �ִ��� num�� ����
		//			dir = horse[y][x][j].second;
		//			num = j;
		//			break;
		//		}
		//	}
		//	cout <<i<<"�� ��: "<< y<<", "<< x << " ����: "<< dir << '\n';
		//}
		if (flag = turn()) break; // 4�� ���̴� ������ �Ծ���?
		//cout << "t: "<<t << '\n';
	}

	cout << (flag ? t : -1) << '\n';
	return 0;
}