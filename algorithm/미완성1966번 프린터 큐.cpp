#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	queue<pair<int, int> > Q, P;
	vector<pair<int, int> > vec;
	int N, M, t, target; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (i == M) target = t;
		P.push(make_pair(t, i));
	}cout << "target" << target << '\n';
	int idx = 0, count = 0;
	for (int i = 0; i < N; i++) {
		if (target <= P.front().first) {
			Q.push(make_pair(P.front().first,idx));
			idx++;
			if (target == P.front().first) count++;
		}
		P.pop();
	}
	if (count == 1) {
		for (int i = 0; i < idx; i++) {
			vec.push_back(Q.front());
			Q.pop();
		}
		sort(vec.begin(), vec.end());
		
		for (int j = 1; j <= idx; j++) {
			if (vec.back().first == target) cout << j << '\n';
			vec.pop_back();
		}
	}
	else {

	}



}