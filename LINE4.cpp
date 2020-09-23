#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

// �� �� �� ��
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
		// ���� ����ų� ���� ������ continue
		if (nx < 0 || nx >= size || ny < 0 || ny >= size || maze[nx][ny]) continue;
		// �̹� ������ �浵 �ƴ϶�� �� �������� ����.
		if (!visited[nx][ny]) {
			dfs(maze, nx, ny, q, p, size);
			if (flag) return;
			check = INF;
		}
		// ������ ���̸� �ּ� ���� check
		else check = min(check, visited[nx][ny]);
	}
	if (check != INF) {
		// ��� ���⿡ ���� �����ϰų� ������ ���̿��ٸ�
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

	// maze, ������ǥ, ������ǥ, maze �� �� ũ��
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