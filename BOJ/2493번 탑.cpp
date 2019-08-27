#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define INF 100000001

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair <int, int> >vec2;
	vec2.push_back(make_pair(INF, 0));
	int N, M; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> M;
		while (vec2.back().first < M) {
			vec2.pop_back();
		}
		cout << vec2.back().second << " ";
		vec2.push_back(make_pair(M, i));
	}
}