#include <iostream>

using namespace std;

int Dp[41][2] = {};
int main() {

	int N, T; cin >> N;
	for (int i = 0; i < N; i++){
		cin >> T;
		Dp[0][0] = 1;
		Dp[0][1] = 0;
		Dp[1][0] = 0;
		Dp[1][1] = 1;
		for (int i = 2; i <= T; i++) {
			Dp[i][0] = Dp[i - 1][0] + Dp[i - 2][0];
			Dp[i][1] = Dp[i - 1][1] + Dp[i - 2][1];
		}
		cout << Dp[T][0] << " " << Dp[T][1] << '\n';
	}
}