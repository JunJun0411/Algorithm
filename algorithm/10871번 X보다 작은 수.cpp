#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, X; cin >> N>>X;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		A[i] =n;
	}
	for (int i = 0; i < N; i++) {
		if (A[i] < X) cout << A[i] <<" ";
	}
}