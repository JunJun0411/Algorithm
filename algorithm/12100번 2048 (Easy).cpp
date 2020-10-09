#include <iostream>
#include <queue>
using namespace std;

const int Max = 21;
int board[Max][Max];
int N;
int ans = 0;

void shift(int way) {
	queue<int> q;
	switch (way)
	{
	// ��
	case 0:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j]) {
					q.push(board[i][j]);
				}
				board[i][j] = 0;
			}

			int idx = 0;
			while (!q.empty()) {
				int x = q.front();
				q.pop();
				// ���� �κ��� 0�� ��
				if (board[i][idx] == 0) {
					board[i][idx] = x;
				}
				// ���� �κ��� ���� ���� ��
				else if (board[i][idx] == x) {
					board[i][idx] *= 2;
					idx++;
				}
				// ���� �κп� ���� �ٸ� ��
				else {
					idx++;
					board[i][idx] = x;
				}

			}
		}
		break;
		// ��
	case 1:
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (board[i][j]) {
					q.push(board[i][j]);
				}
				board[i][j] = 0;
			}

			int idx = N - 1;
			while (!q.empty()) {
				int x = q.front();
				q.pop();
				// ���� �κ��� 0�� ��
				if (board[i][idx] == 0) {
					board[i][idx] = x;
				}
				// ���� �κ��� ���� ���� ��
				else if (board[i][idx] == x) {
					board[i][idx] *= 2;
					idx--;
				}
				// ���� �κп� ���� �ٸ� ��
				else {
					idx--;
					board[i][idx] = x;
				}
			}
		}
		break;

		// ��
	case 2:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[j][i])
					q.push(board[j][i]);
				board[j][i] = 0;
			}

			int idx = 0;
			while (!q.empty()) {
				int x = q.front();
				q.pop();
				// ���� �κ��� 0�� ��
				if (board[idx][i] == 0) {
					board[idx][i] = x;
				}
				// ���� �κ��� ���� ���� ��
				else if (board[idx][i] == x) {
					board[idx][i] *= 2;
					idx++;
				}
				// ���� �κп� ���� �ٸ� ��
				else {
					idx++;
					board[idx][i] = x;
				}
			}
		}
		break;

		// ��
	case 3:
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (board[j][i]) 
					q.push(board[j][i]);
				board[j][i] = 0;
				
			}

			int idx = N - 1;
			while (!q.empty()) {
				int x = q.front();
				q.pop();
				// ���� �κ��� 0�� ��
				if (board[idx][i] == 0) {
					board[idx][i] = x;
				}
				// ���� �κ��� ���� ���� ��
				else if (board[idx][i] == x) {
					board[idx][i] *= 2;
					idx--;
				}
				// ���� �κп� ���� �ٸ� ��
				else {
					idx--;
					board[idx][i] = x;
				}
			}
		}
		break;
	}
}

void DFS(int cnt) {

	if (cnt == 5) {
		// ��� �ִ밪 ��ġ �� ���
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}
	int copy_board[Max][Max];
	// �� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_board[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		shift(i);
		DFS(cnt + 1);

		//���� ���󺹱�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = copy_board[i][j];
			}
		}
	}
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

}

void Solution() {
	DFS(0);
	cout << ans << '\n';
}
void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}