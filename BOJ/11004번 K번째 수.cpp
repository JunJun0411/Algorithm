#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int A, K, X; cin >> A >> K;
	vector<int> v(A);
	for (int i = 0; i < A; i++) {
		cin >> X;
		v[i] = X;
	}
	sort(v.begin(), v.end());
	cout << v[K-1] << '\n';
}