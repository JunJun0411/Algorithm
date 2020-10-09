#include <iostream>
#include <queue>
#define Max 100001
using namespace std;

bool visited[Max];

int DFS(int a, int b, int n, int m) {
	queue<int> q;
	q.push(n);

	// n��° ���ٸ� �湮üũ
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


			// ������ġ + 1 
			if (loc + 1 < Max && !visited[loc + 1]) {
				q.push(loc + 1);
				visited[loc + 1] = true;
			}

			// ������ġ - 1
			if (loc - 1 >= 0 && !visited[loc - 1]) {
				q.push(loc - 1);
				visited[loc - 1] = true;
			}

			// ������ġ + A 
			if (loc + a < Max && !visited[loc + a]) {
				q.push(loc + a);
				visited[loc + a] = true;
			}

			// ������ġ - A
			if (loc - a >= 0 && !visited[loc - a]) {
				q.push(loc - a);
				visited[loc - a] = true;
			}

			// ������ġ + B 
			if (loc + b < Max && !visited[loc + b]) {
				q.push(loc + b);
				visited[loc + b] = true;
			}

			// ������ġ - B
			if (loc - b >= 0 && !visited[loc - b]) {
				q.push(loc - b);
				visited[loc - b] = true;
			}

			// ������ġ * A 
			if (loc * a < Max && !visited[loc * a]) {
				q.push(loc * a);
				visited[loc * a] = true;
			}
			// ������ġ * A 
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

	// ���� A, B, ������ġ, �ֹ���ġ
	int A, B, N, M;
	cin >> A >> B >> N >> M;

	cout << DFS(A, B, N, M) << '\n';
	return 0;
}