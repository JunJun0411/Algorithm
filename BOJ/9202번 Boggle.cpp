#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXW = 300001;
const int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
const int dx[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int W, B;
string dic[MAXW];
string board[30][4];
bool visited[4][4] = { 0, };
bool flag;

void dfs(int b, int y, int x, int d, int cnt, int size) {
	if (flag) 		
		return;

	// 단어 찾은 경우
	if (cnt == size) {
		flag = true;
		return;
	}

	// 8 방향에 대해 비교
	for (int i = 0; i < 8; i++) {
		if (flag) return;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || visited[ny][nx] || (board[b][ny][nx] != dic[d][cnt])) continue;
		visited[ny][nx] = true;
		dfs(b, ny, nx, d, cnt + 1, size);
		visited[ny][nx] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//INPUT
	cin >> W;

	for (int i = 0; i < W; i++) {
		cin >> dic[i];
	}
	sort(dic, dic + W);

	cin >> B;
	for (int i = 0; i < B; i++) {
		// i번째 board Input
		for (int j = 0; j < 4; j++)
			cin >> board[i][j];

		// 모든 사전에 대해 dfs
		int sum = 0, cnt = 0;
		string maxS = "";
		
		for (int k = 0; k < W; k++) {
			int size = dic[k].size();
			// 찾은 신호
			flag = false;

			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					// i번째 사전의 첫글자와 같으면 시작
					if (board[i][y][x] == dic[k][0]) {
						// 단어 사전 찾기 시작
						visited[y][x] = true;
						dfs(i, y, x, k, 1, size);
						visited[y][x] = false;
					}
					// 찾았다면 탈출
					if (flag) break;
				}
				// 찾았다면 점수와 갯수 증가 후 탈출 
				if (flag) {
					// 가장 긴 단어 고르기, 길이가 같다면 사전 순
					if (maxS.size() < size || (maxS.size() == size && maxS > dic[k])) maxS = dic[k];
					if (size == 8) sum += 11;
					else if (size == 7) sum += 5;
					else if (size == 6) sum += 3;
					else if (size == 5) sum += 2;
					else if (size == 3 || size == 4) sum += 1;
					cnt++;
					break;
				}
			}
			
		}
		cout << sum << " " << maxS << " " << cnt << '\n';
	}
	return 0;
}