#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int K, N;
int arr[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	set<long long> s;
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	pq.push(1);
	long long maxvalue = 0;
	while (N) {
		long long head = pq.top();
		pq.pop();

		for (int i = 0; i < K; i++) {
			long long ins = head * arr[i];
			
			// N보다 pq사이즈가 큰 상태에서 최대값보다 큰 수는 넘긴다.
			if (pq.size() > N && ins > maxvalue)
				continue;

			// pq에 같은값이 없다면 pq에 넣는다
			if (s.insert(ins).second) {
				maxvalue = max(ins, maxvalue);
				pq.push(ins);
			}
		}
		N--;
	}
	cout << pq.top() << '\n';
	return 0;
}
