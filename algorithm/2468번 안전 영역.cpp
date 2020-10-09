#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int N;
int arr[MAX][MAX];
bool height[MAX];
bool visited[MAX][MAX];

void BFS(int x, int y) {
	queue<pair< int, int> > q;
	visited[x][y] = true;
	q.push({ x, y });
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 경계 초과, 방문기록 있거나, 잠긴영역이면 continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || !arr[nx][ny]) continue;
			q.push({ nx, ny });
			// 방문기록 남기기
			visited[nx][ny] = true;
		}
	}
}

int Solution() {
	int answer = 0;

	for (int k = 0; k < MAX; k++) {
		// 영역의 높이가 아니면 continue
		if (!height[k]) continue;
		
		// 최대영역
		int area = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 방문기록 초기화
				visited[i][j] = false;
				// 잠긴 영역 0으로 변환
				if (arr[i][j] <= k) 
					arr[i][j] = 0;
			}
		}

		// BFS 진행
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 잠기지 않았고 방문한 적 없다면
				if (arr[i][j] && !visited[i][j]) {
					BFS(i,j);
					area++;
				}
			}
		}
		// 최대 영역 구하기
		answer = max(answer, area);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// INPUT
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x; cin >> x;
			arr[i][j] = x;
			height[x] = true;
		}
	}
	height[0] = true;
	// Solution
	cout << Solution() << '\n';

	return 0;
}