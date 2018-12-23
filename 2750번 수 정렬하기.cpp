#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int N; cin >> N;
	int X;
	for (int i = 0; i < N; i++) {
		cin >> X;
		v.push_back(X);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i] << '\n';
	}
}