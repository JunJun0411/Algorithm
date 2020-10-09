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
			// ��� �ʰ�, �湮��� �ְų�, ��俵���̸� continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || !arr[nx][ny]) continue;
			q.push({ nx, ny });
			// �湮��� �����
			visited[nx][ny] = true;
		}
	}
}

int Solution() {
	int answer = 0;

	for (int k = 0; k < MAX; k++) {
		// ������ ���̰� �ƴϸ� continue
		if (!height[k]) continue;
		
		// �ִ뿵��
		int area = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// �湮��� �ʱ�ȭ
				visited[i][j] = false;
				// ��� ���� 0���� ��ȯ
				if (arr[i][j] <= k) 
					arr[i][j] = 0;
			}
		}

		// BFS ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// ����� �ʾҰ� �湮�� �� ���ٸ�
				if (arr[i][j] && !visited[i][j]) {
					BFS(i,j);
					area++;
				}
			}
		}
		// �ִ� ���� ���ϱ�
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