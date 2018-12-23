#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { 1, -1, 0, 0 }; //³², ºÏ
int dx[4] = { 0, 0, 1, -1 }; //µ¿, ¼­

const int Max = 27;
vector<int> A(Max*Max);
int graph[Max][Max];
bool visited[Max][Max];
int N;
int T = 0;
void DFS(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		
		//if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N) {
			if (!visited[nextY][nextX] && graph[nextY][nextX]) {
				visited[nextY][nextX] = true;
				if (visited[nextY][nextX]) T++;
				DFS(nextY, nextX);
			}
		
	}
}
int main() {
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%1d", &graph[y][x]);
		}
	}
	int cnt = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (graph[y][x] && !visited[y][x]) {
				visited[y][x] = true;
				if (visited[y][x]) T++;
				DFS(y, x);
				A[cnt] = T;
				cnt++;
				T = 0;
			}
		}
	}
	sort(A.begin(), A.end());
	cout << cnt << '\n';
	for (int i = 0; i < A.size(); i++) {
		if(A[i] != 0)
			cout << A[i] << '\n';
	}
}