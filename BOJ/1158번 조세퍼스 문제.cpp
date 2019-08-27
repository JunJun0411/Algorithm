#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q, p;
	int N, K; cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (q.size() >= 1) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		p.push(q.front()); q.pop();
	}
	cout << "<" << p.front(); p.pop();
	while (!p.empty()) {
		cout << ", " << p.front(); p.pop();
	}
	cout << ">" << '\n';
}