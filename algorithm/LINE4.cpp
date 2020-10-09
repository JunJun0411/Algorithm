#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

// 북 동 남 서
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int visited[301][301];
int cnt = 1;
bool flag = false;
void dfs(vector<vector<int>> maze, int x, int y, int q, int p, int size) {
	if (x == q && y == p) {
		flag = true;
		return;
	}
	visited[x][y] = cnt++;

	int check = INF;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 범위 벗어나거나 벽이 있으면 continue
		if (nx < 0 || nx >= size || ny < 0 || ny >= size || maze[nx][ny]) continue;
		// 이미 지나온 길도 아니라면 그 방향으로 간다.
		if (!visited[nx][ny]) {
			dfs(maze, nx, ny, q, p, size);
			if (flag) return;
			check = INF;
		}
		// 지나온 길이면 최소 값을 check
		else check = min(check, visited[nx][ny]);
	}
	if (check != INF) {
		// 모든 방향에 벽이 존재하거나 지나온 길이였다면
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= size || ny < 0 || ny >= size || maze[nx][ny]) continue;
			if (visited[nx][ny] == check) {
				dfs(maze, nx, ny, q, p, size);
				if (flag) return;
			}
		}
	}
}
int solution(vector<vector<int>> maze) {
	int answer = 0;
	int size = maze.size();
	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++) 
			if (maze[i][j]) visited[i][j] = INF;

	// maze, 시작좌표, 도착좌표, maze 한 변 크기
	dfs(maze, 0,0, size-1, size-1, size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int ans = visited[i][j];
			cout << ans << " ";
			if (ans != INF && ans != 0) answer++;
		}
		cout << "\n";
	}

	return answer+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> maze = {
		{0, 1, 0, 0},
		{0, 0, 0, 0},
		{0, 1, 1, 1},
		{0, 0, 0, 0}
	};

	cout<< solution(maze) << "\n";
	
	return 0;
}