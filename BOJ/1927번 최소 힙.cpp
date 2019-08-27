#include <iostream>
#include <queue>
using namespace std;

int N;
int x;
priority_queue<unsigned int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x) q.push(-x);
		else {
			if (q.empty()) cout << x << '\n';
			else {
				cout << -q.top() << '\n';
				q.pop();
			}
		}
	}
	return 0;
}