#include <iostream>
using namespace std;

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { 1, -1, 0, 0 };

int N, M, K;
int pos[2];
int dice[6] = { 0, }; // 0: ��, 1: ��, 2: ��, 3: ��, 4: ��, 5: ��
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

		// �ֻ����� ���� ���� ����� continue
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		pos[0] = ny;
		pos[1] = nx;

		//�ش� ��ǥ�� ����
		int num = Map[ny][nx]; 

		// �ֻ��� ������
		switch (dir) {
			// ��
		case 1:
			// �ٴ� ���ڰ� 0�̶�� �ֻ��� �ٴ� ���ڸ� ����
			if (num == 0) {
				Map[ny][nx] = dice[1];
			}
			dice[1] = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			// �ֻ��� �ٴ��� ������ ���ڷ� ����
			dice[5] = Map[ny][nx]; 
			// �ٴ��� 0�� �ƴϸ� �ٴڼ��ڸ� 0���� ����
			if(num != 0)
				Map[ny][nx] = 0;
			answer[cnt++] = dice[0];
			break;
			// ��
		case 2:
			// �ٴ� ���ڰ� 0�̶�� �ֻ��� �ٴ� ���ڸ� ����
			if (num == 0) {
				Map[ny][nx] = dice[3];
			}
			dice[3] = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			// �ֻ��� �ٴ��� ������ ���ڷ� ����
			dice[5] = Map[ny][nx];
			// �ٴ��� 0�� �ƴϸ� �ٴڼ��ڸ� 0���� ����
			if (num != 0)
				Map[ny][nx] = 0;
			answer[cnt++] = dice[0];
			break;
			// ��
		case 3:
			// �ٴ� ���ڰ� 0�̶�� �ֻ��� �ٴ� ���ڸ� ����
			if (num == 0) {
				Map[ny][nx] = dice[4];
			}
			dice[4] = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			// �ֻ��� �ٴ��� ������ ���ڷ� ����
			dice[5] = Map[ny][nx];
			// �ٴ��� 0�� �ƴϸ� �ٴڼ��ڸ� 0���� ����
			if (num != 0)
				Map[ny][nx] = 0;
			answer[cnt++] = dice[0];
			break;
			// ��
		case 4:
			// �ٴ� ���ڰ� 0�̶�� �ֻ��� �ٴ� ���ڸ� ����
			if (num == 0) {
				Map[ny][nx] = dice[2];
			}
			dice[2] = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			// �ֻ��� �ٴ��� ������ ���ڷ� ����
			dice[5] = Map[ny][nx];
			// �ٴ��� 0�� �ƴϸ� �ٴڼ��ڸ� 0���� ����
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