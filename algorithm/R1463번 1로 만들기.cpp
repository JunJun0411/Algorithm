#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int Max = 1000001;
int N;
int cache[Max];

int DP(int X) {
	int &result = cache[X];
	if (result != -1) return result;
	if (X == 1) return result;

	int ret = Max;
	if (X % 3 == 0) {
		ret = min(ret, DP(X / 3));
	}
	if (X % 2 == 0) {
		ret = min(ret, DP(X / 2));
	}
	ret = min(ret, DP(X - 1));

	return result = ret + 1;
}

void Input() {
	cin >> N;
}
void Solution() {
	memset(cache, -1, sizeof(cache));
	cache[0] = cache[1] = 0;
	cout <<DP(N) <<'\n';
}

void Solve() {
	Input();
	Solution();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}