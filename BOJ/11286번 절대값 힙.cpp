#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
priority_queue<int> mq;
int N, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x < 0) {
			mq.push(x);
		}
		else if (x > 0) {
			pq.push(-x);
		}
		else {
			if (mq.empty() && pq.empty()) cout << x << '\n';
			else if (mq.empty()) {
				cout << -pq.top() << '\n';
				pq.pop();
			}
			else if (pq.empty()) {
				cout << mq.top() << '\n';
				mq.pop();
			}
			else if (-mq.top() <= -pq.top()) {
				cout << mq.top() << '\n';
				mq.pop();
			}
			else {
				cout << -pq.top() << '\n';
				pq.pop();
			}
		}
	}
	return 0;
}