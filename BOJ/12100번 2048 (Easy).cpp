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
	// 좌
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
				// 넣을 부분이 0일 때
				if (board[i][idx] == 0) {
					board[i][idx] = x;
				}
				// 넣을 부분이 같은 값일 떄
				else if (board[i][idx] == x) {
					board[i][idx] *= 2;
					idx++;
				}
				// 넣을 부분에 값이 다를 때
				else {
					idx++;
					board[i][idx] = x;
				}

			}
		}
		break;
		// 우
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
				// 넣을 부분이 0일 때
				if (board[i][idx] == 0) {
					board[i][idx] = x;
				}
				// 넣을 부분이 같은 값일 떄
				else if (board[i][idx] == x) {
					board[i][idx] *= 2;
					idx--;
				}
				// 넣을 부분에 값이 다를 때
				else {
					idx--;
					board[i][idx] = x;
				}
			}
		}
		break;

		// 상
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
				// 넣을 부분이 0일 때
				if (board[idx][i] == 0) {
					board[idx][i] = x;
				}
				// 넣을 부분이 같은 값일 떄
				else if (board[idx][i] == x) {
					board[idx][i] *= 2;
					idx++;
				}
				// 넣을 부분에 값이 다를 때
				else {
					idx++;
					board[idx][i] = x;
				}
			}
		}
		break;

		// 하
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
				// 넣을 부분이 0일 때
				if (board[idx][i] == 0) {
					board[idx][i] = x;
				}
				// 넣을 부분이 같은 값일 떄
				else if (board[idx][i] == x) {
					board[idx][i] *= 2;
					idx--;
				}
				// 넣을 부분에 값이 다를 때
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
		// 블록 최대값 서치 후 출력
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}
	int copy_board[Max][Max];
	// 맵 복사
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_board[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		shift(i);
		DFS(cnt + 1);

		//보드 원상복구
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