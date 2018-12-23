#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	pair<int, int> v[100001];
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v, v + N);
	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
}