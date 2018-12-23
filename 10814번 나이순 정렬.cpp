#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first < b.first) return true;
	else if (a.first < b.first) return false;
	return false;
}
int main() {
	int T; cin >> T;
	vector<pair<int, string>> A(T);
	for (int i = 0; i < T; i++) {
		cin >> A[i].first >> A[i].second;
	}
	stable_sort(A.begin(), A.end(), cmp);
	
	for (int i = 0; i < T; i++) {
		cout << A[i].first <<" "<< A[i].second << '\n';
	}
}