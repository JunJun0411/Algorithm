#include <iostream>
using namespace std;
long long Dp[91] = {};
int main() {
	int N; cin >> N;
	Dp[1] = 1;
	Dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		Dp[i] = Dp[i - 1] + Dp[i - 2];
	}
	cout << Dp[N] << '\n';
}