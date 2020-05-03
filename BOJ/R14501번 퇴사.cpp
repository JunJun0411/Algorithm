#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 20;
int T[Max], P[Max];
int N;
int cache[Max];

int solve(int day) {
	if (day > N) {
		return 0;
	}
	int &ret = cache[day];
	if (ret != -1) return ret;

	if(day+T[day] <= N+1)
		ret = solve(day + T[day]) + P[day];
	return ret = max(ret, solve(day+1));
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
}

void Solution() {
	memset(cache, -1, sizeof(cache));
	int ans = solve(1);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solution();

	return 0;
}