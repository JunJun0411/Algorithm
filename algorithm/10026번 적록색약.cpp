#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define Max 101

int N;
int normal = 0, abnormal = 0;
string pic[Max];
bool visited[Max][Max];
bool abvisited[Max][Max];
bool check;
int abcheck;
int r, t, y, u;

void BFS(int i, int j) {
	queue<pair<int, int> > q;
	q.push({i, j});
	char c = pic[i][j];

	if (pic[i][j] == 'B') abcheck = 1;
	else abcheck = 2;

	if (!check) {
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			if (a + 1 < N && !visited[a + 1][b] && pic[a + 1][b] == c) {
				visited[a + 1][b] = true;
				q.push({ a + 1, b });
			}
			if (a - 1 >= 0 && !visited[a - 1][b] && pic[a - 1][b] == c) {
				visited[a - 1][b] = true;
				q.push({ a - 1, b });
			}
			if (b + 1 < N && !visited[a][b + 1] && pic[a][b + 1] == c) {
				visited[a][b + 1] = true;
				q.push({ a, b + 1 });
			}
			if (b - 1 >= 0 && !visited[a][b - 1] && pic[a][b - 1] == c) {
				visited[a][b - 1] = true;
				q.push({ a, b - 1 });
			}
		}
	}
	else {
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			if (a + 1 < N&&pic[a + 1][b] == 'B') r = 1; else r = 2;
			if (a - 1 >= 0 && pic[a - 1][b] == 'B') t = 1; else t = 2;
			if (b + 1 < N &&pic[a][b + 1] == 'B') y = 1; else y = 2;
			if (b - 1 >= 0 && pic[a][b - 1] == 'B') u = 1; else u = 2;
			if (a + 1 < N && !abvisited[a + 1][b] && r == abcheck) {
				abvisited[a + 1][b] = true;
				q.push({ a + 1, b });
			}
			if (a - 1 >= 0 && !abvisited[a - 1][b] && t == abcheck) {
				abvisited[a - 1][b] = true;
				q.push({ a - 1, b });
			}
			if (b + 1 < N && !abvisited[a][b + 1] && y == abcheck) {
				abvisited[a][b + 1] = true;
				q.push({ a, b + 1 });
			}
			if (b - 1 >= 0 && !abvisited[a][b - 1] && u == abcheck) {
				abvisited[a][b - 1] = true;
				q.push({ a, b - 1 });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pic[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				check = false;
				visited[i][j] = true;
				BFS(i, j);
				normal++;
			}
			if (!abvisited[i][j]) {
				check = true;
				abvisited[i][j] = true;
				BFS(i, j);
				abnormal++;
			}
		}
	}
	cout << normal<<" " << abnormal<< '\n';
	return 0;
}