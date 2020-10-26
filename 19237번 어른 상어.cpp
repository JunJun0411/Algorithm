#include <iostream>
#include <vector>
using namespace std;

const int dy[5] = { 0, -1, 1, 0, 0 };
const int dx[5] = { 0, 0, 0, -1, 1 };

int N, M, K;
pair<int, int> map[21][21]; // 상어의 번호, 상어의 흔적
pair<pair<int, int>, int> shake[401]; // 상어의 위치, 방향
int sDir[401][5][5]; // 방향 우선순위

void debugg() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j].first << map[i][j].second << "   ";
		}
		cout << '\n';
	}
}

void moving() {
	vector<pair<pair<int, int>, pair<int, int>> > buf; // 상어 번호, 방향, 좌표
	for (int i = 1; i <= M; i++) {
		if (!shake[i].second) continue; // 죽은 상어는 continue
		int y = shake[i].first.first;
		int x = shake[i].first.second;
		int r = shake[i].second; // 방향
//		cout << i<<"번 상어 위치: " << y << ", " << x << '\n';
		bool flag = false;
		for (int j = 1; j <= 4; j++) {
			// 방향 우선순위 대로
			int dir = sDir[i][r][j]; 
			int ny = y + dy[dir];
			int nx = x + dx[dir];
//			cout << "상어 위치: " << ny << ", " << nx << " 방향: " << dir << " 갈 수 있어? "<<'\n';
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (map[ny][nx].first != 0) continue; // 가려는 곳에 다른 상어의 흔적이 있다면 안간다.

			// 갈 곳이 정해졌다면, 버퍼에 담기
			buf.push_back({ { i , dir } , { ny, nx } });
			flag = true;
//			cout << " O " << '\n';
			break;
		}
		if (!flag) {
			for (int j = 1; j <= 4; j++) {
				// 방향 우선순위 대로
				int dir = sDir[i][r][j];
				int ny = y + dy[dir];
				int nx = x + dx[dir];
//				cout << "상어 위치: " << ny << ", " << nx << " 방향: " << dir << " 갈 수 있어? " << map[ny][nx].first << '\n';
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (map[ny][nx].first != i) continue; // 가려는 곳에 다른 상어의 흔적이 있다면 안간다.

				// 갈 곳이 정해졌다면, 버퍼에 담기
				buf.push_back({ { i , dir } , { ny, nx } });
//				cout << " O " << '\n';
				break;
			}
		}
	 }

	// 흔적 지우기
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (map[i][j].first) 
				// 흔적 -1, 0이라면 흔적 지운다.
				if ((--map[i][j].second) == 0) 
					map[i][j].first = 0;		
	
	// 상어 배치
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
			// 죽은 상어 표시
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
		// 이동
		moving();

		// 1번 상어 빼고 살아있는 상어 있는지 확인
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