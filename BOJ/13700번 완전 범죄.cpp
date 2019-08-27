#include <iostream>
#include <queue>
using namespace std;

int N, S, D, F, B, K, I;
bool check[100001];

void BFS(int s) {
	queue<int> q;
	q.push(s);
	check[s] = true;
	int level = 0;

	while (!q.empty()) {
		level++;
		int size = q.size();
		while (size--) {
			int locate = q.front();
			q.pop();
			int next = locate + F, before = locate - B;
			if (next == D || before == D) {
				cout << level << '\n';
				return;
			}

			if (!check[next] && next <= N) {
				q.push(next);
				check[next] = true;
			}
			if (!check[before] && before > 0) {
				q.push(before);
				check[before] = true;
			}
		}
	}
	cout << "BUG FOUND" << '\n';
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S >> D >> F >> B >> K;
	for (int i = 0; i < K; i++) {
		cin >> I;
		check[I] = true;
	}

	BFS(S);
	return 0;
}