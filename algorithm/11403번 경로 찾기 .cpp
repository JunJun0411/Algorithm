#include <iostream>
#include <queue>
using namespace std;

int N;
int Grape[101][101];
bool visited[101][101];
queue<pair<int, int> > q;

void DFS(int s, int e) {
		for (int i = 1; i <= N; i++) {
			if (Grape[e][i] && !visited[s][i]) {
				visited[s][i] = true;
				DFS(s, i);
			}
		}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Grape[i][j];
			if (Grape[i][j]) {
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		int startnode = q.front().first;
		int endnode = q.front().second;
		q.pop();

		DFS(startnode, endnode);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}