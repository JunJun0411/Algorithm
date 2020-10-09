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
			
			// N���� pq����� ū ���¿��� �ִ밪���� ū ���� �ѱ��.
			if (pq.size() > N && ins > maxvalue)
				continue;

			// pq�� �������� ���ٸ� pq�� �ִ´�
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
