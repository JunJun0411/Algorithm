#include <iostream>
using namespace std;

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { 1, -1, 0, 0 };

int N, M, K;
int pos[2];
int dice[6] = { 0, }; // 0: 상, 1: 동, 2: 남, 3: 서, 4: 북, 5: 하
int Map[21][21];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer[1001];
	int cnt = 0;

	cin >> N >> M >> pos[0] >> pos[1] >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int dir;
		cin >> dir;
		
		int ny = pos[0] + dy[dir - 1];
		int nx = pos[1] + dx[dir - 1];

		// 주사위가 지도 범위 벗어나면 continue
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		pos[0] = ny;
		pos[1] = nx;

		//해당 좌표의 숫자
		int num = Map[ny][nx]; 

		// 주사위 굴리기
		switch (dir) {
			// 동
		case 1:
			// 바닥 숫자가 0이라면 주사위 바닥 숫자를 복사
			if (num == 0) {
				Map[ny][nx] = dice[1];
			}
			dice[1] = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			// 주사위 바닥을 지도의 숫자로 변경
			dice[5] = Map[ny][nx]; 
			// 바닥이 0이 아니면 바닥숫자를 0으로 변경
			if(num != 0)
				Map[ny][nx] = 0;
			answer[cnt++] = dice[0];
			break;
			// 서
		case 2:
			// 바닥 숫자가 0이라면 주사위 바닥 숫자를 복사
			if (num == 0) {
				Map[ny][nx] = dice[3];
			}
			dice[3] = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			// 주사위 바닥을 지도의 숫자로 변경
			dice[5] = Map[ny][nx];
			// 바닥이 0이 아니면 바닥숫자를 0으로 변경
			if (num != 0)
				Map[ny][nx] = 0;
			answer[cnt++] = dice[0];
			break;
			// 북
		case 3:
			// 바닥 숫자가 0이라면 주사위 바닥 숫자를 복사
			if (num == 0) {
				Map[ny][nx] = dice[4];
			}
			dice[4] = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			// 주사위 바닥을 지도의 숫자로 변경
			dice[5] = Map[ny][nx];
			// 바닥이 0이 아니면 바닥숫자를 0으로 변경
			if (num != 0)
				Map[ny][nx] = 0;
			answer[cnt++] = dice[0];
			break;
			// 남
		case 4:
			// 바닥 숫자가 0이라면 주사위 바닥 숫자를 복사
			if (num == 0) {
				Map[ny][nx] = dice[2];
			}
			dice[2] = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			// 주사위 바닥을 지도의 숫자로 변경
			dice[5] = Map[ny][nx];
			// 바닥이 0이 아니면 바닥숫자를 0으로 변경
			if (num != 0)
				Map[ny][nx] = 0;
			answer[cnt++] = dice[0];
			break;
		}
	}

	for (int i = 0; i < cnt; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}