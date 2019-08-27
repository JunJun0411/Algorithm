#include <iostream>
#include <queue>
using namespace std;

int N, M;
priority_queue<int> Max;
priority_queue<int> Min;
int result[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	Max.push(M);
	int mid = M;
	int idx = 0;
	result[idx++] = mid;
	for (; idx < N; idx++) {
		cin >> M;
		if (M > mid) {
			Min.push(-M);
		}
		else {
			Max.push(M);
		}
		if (Min.size() > Max.size()) {
			mid = -Min.top(); Min.pop();
			Max.push(mid);
		}
		else if (Max.size() > Min.size() + 1) {
			Min.push(-Max.top()); Max.pop();
			mid = Max.top();
		}
		else if (Max.size() >= Min.size()) {
			mid = Max.top();
		}
		result[idx] = mid;
	}
	for (int i = 0; i < idx; i++) {
		cout << result[i] << '\n';
	}
	return 0;
}