#include <iostream>
using namespace std;

int Dp[46] = {};
int main() {
	int T; cin >> T;
	Dp[0] = 0;
	Dp[1] = 1;
	for (int i = 2; i <= T; i++) {
		Dp[i] = Dp[i - 1] + Dp[i - 2];
	}
	cout << Dp[T] << '\n';
}