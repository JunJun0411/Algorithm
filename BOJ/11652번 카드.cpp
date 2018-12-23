#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<long long> A(N);
	vector<int> B(N, 1);
	vector<int>::iterator it;
	int n = 0, m=0;
	for (int i = 0; i < N; i++) {
		long long x; cin >> x;
		A[i] = x;
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			if (A[i] == A[i - 1])
				B[n]++;
			else
				n++;
		}
	}
	it = max_element(B.begin(), B.end());
	for (int i = 0; i < N; i++) {
		m += B[i];
		if (B[i] == *it) {
			cout << A[m-1] << '\n';
			return 0;
		}
	}
}