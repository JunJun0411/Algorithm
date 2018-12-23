#include <iostream>
#include <queue>
using namespace std;

const int Max = 100000;
int N, T, G;
bool visited[Max];
int cnt = 0, t=0;
bool fail = false;
int B(int idx) {
	idx *= 2;
	int x = idx;
	int num = 1;
	while (x) {
		x /= 10;
		num *= 10;
	}
	
	return idx - num/10;
}
void BFS(int n) {
	queue<int> q;
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		int size = q.size();
		if (cnt > T) break;
		while (size--) {
			int n = q.front();
			if (n == G) return;
			
			q.pop();
			if (n < Max - 1 && !visited[n + 1]) {
				visited[n + 1] = true;
				q.push(n + 1);
			}
			if (n * 2 >= Max) continue;
			if (n * 2 < Max && !visited[B(n)]) {
				visited[B(n)] = true;
				q.push(B(n));
			}
		}
		cnt++;
	}
	cout << "ANG" << '\n';
	fail = true;
	return;
}
int main() {
	cin >> N >> T >> G;
	int Bnum = 0;
	BFS(N);
	if (fail) return 0;
	cout << cnt << '\n';
	
}