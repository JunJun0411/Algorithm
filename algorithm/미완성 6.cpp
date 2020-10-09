#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

struct scard {
	int FromX = -1, FromY = -1;
	int ToX = -1, ToY = -1;
};

scard dash[7];
int card = 0;
int num;

int dis(vector<vector<int>> board, int r, int c, int a, int b) {
	if (r == a && c == b) return 0;

	bool visited[4][4] = { 0, };
	queue<pair<int, int> > q;
	q.push({ r, c });
	visited[r][c] = true;

	int step = 0;
	while (!q.empty()) {
		int size = q.size();
		step++;
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for (int i = 0; i < 4; i++) {
				int nx, ny, mx, my;
				nx = x + dx[i];
				ny = y + dy[i];
				// ���� �ʰ�
				if (nx < 0 || nx > 3 || ny < 0 || ny > 3 || visited[nx][ny]) continue;

				// cntl����
				mx = nx, my = ny;
					
				while (1) {
					// �ݺ� �̵�
					mx += dx[i];
					my += dy[i];

					// ���� �ʰ��ϸ� �� ��������
					if ((mx < 0 ||mx>3 || my < 0 || my>3)) {
						mx -= dx[i];
						my -= dy[i];
						break;
					}

					// ī�� ������ �ű����
					if (board[mx][my]) break;
				}

				// ã����
				if ((nx == a) && (ny == b)) return step;
				
				q.push({ nx, ny });
				visited[nx][ny] = true;
				
				if (nx != mx || ny != my) {
					// ã����
					if (mx == a && my == b) return step;
					q.push({ mx, my });
				}
			}
		}
	}
	
	return INF;
}
int bfs(vector<vector<int>> board, int r, int c) {
	int MIN = INF;
	for (int k = 0; k < card; k++) {
		// �� ��ġ���� �� ī����� Ű ���� �ּڰ�
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[i][j]) {
					// r,c ��ġ���� i,j ���� Ű ���� �� ����
					num = dis(board, r, c, i, j);
					// i,j���� ������ ��� ���� ������ �ּ� ���� ��
					/*num += bfs(board, i, j);*/
					MIN = min(MIN, num);
				}
			}
		}
	}
	int enter = board[r][c];

	return 0;
}

int solution(vector<vector<int>> board, int r, int c) {
	int answer = INF;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j]) card++;
			if (board[i][j] && dash[board[i][j]].FromX == -1) {
				dash[board[i][j]].FromX = i;
				dash[board[i][j]].FromY = j;
			}
			else if (board[i][j] && dash[board[i][j]].FromX != -1) {
				dash[board[i][j]].ToX = i;
				dash[board[i][j]].ToY = j;
			}
		}
	}
	answer = bfs(board, r, c);
	

	return answer + card;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> board = { {1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0} };
	int r = 1, c = 0;
	cout << solution(board, r, c);

	return 0;
}