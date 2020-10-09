#include <iostream>
#include <queue>
#define Max 100001
using namespace std;

bool visited[Max];

int DFS(int a, int b, int n, int m) {
	queue<int> q;
	q.push(n);

	// n번째 돌다리 방문체크
	visited[n] = true;

	int count = 0;
	while (!q.empty()) {
		count++;
		
		int size = q.size();
		while (size--) {
			int loc = q.front();
			q.pop();

			if (loc + 1 == m) return count++;
			if (loc + a == m) return count++;
			if (loc + b == m) return count++;
			if (loc - 1 == m) return count++;
			if (loc - a == m) return count++;
			if (loc - b == m) return count++;
			if (loc * a == m) return count++;
			if (loc * b == m) return count++;


			// 현재위치 + 1 
			if (loc + 1 < Max && !visited[loc + 1]) {
				q.push(loc + 1);
				visited[loc + 1] = true;
			}

			// 현재위치 - 1
			if (loc - 1 >= 0 && !visited[loc - 1]) {
				q.push(loc - 1);
				visited[loc - 1] = true;
			}

			// 현재위치 + A 
			if (loc + a < Max && !visited[loc + a]) {
				q.push(loc + a);
				visited[loc + a] = true;
			}

			// 현재위치 - A
			if (loc - a >= 0 && !visited[loc - a]) {
				q.push(loc - a);
				visited[loc - a] = true;
			}

			// 현재위치 + B 
			if (loc + b < Max && !visited[loc + b]) {
				q.push(loc + b);
				visited[loc + b] = true;
			}

			// 현재위치 - B
			if (loc - b >= 0 && !visited[loc - b]) {
				q.push(loc - b);
				visited[loc - b] = true;
			}

			// 현재위치 * A 
			if (loc * a < Max && !visited[loc * a]) {
				q.push(loc * a);
				visited[loc * a] = true;
			}
			// 현재위치 * A 
			if (loc * b < Max && !visited[loc * b]) {
				q.push(loc * b);
				visited[loc * b] = true;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 콩콩 A, B, 동규위치, 주미위치
	int A, B, N, M;
	cin >> A >> B >> N >> M;

	cout << DFS(A, B, N, M) << '\n';
	return 0;
}