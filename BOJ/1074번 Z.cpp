#include <iostream>
#include <math.h>
using namespace std;

void Z(int n, int r, int c, int sum) {
	//기저 사례
	if (n == 1) {
		cout << sum << '\n';
		return;
	}
	int n2 = n / 2;
	// 1사분면
	if (n2 > r && n2 > c) {
		Z(n2, r, c, sum);
	}
	//2사분면
	else if (n2 > r && n2 <= c) {
		Z(n2, r, c - n2, sum + n2*n2);
	}
	//3사분면
	else if (n2 <= r && n2 > c) {
		Z(n2, r - n2, c, sum + 2 * n2*n2);
	}
	//4사분면
	else {
		Z(n2, r - n2, c - n2, sum + 3 * n2*n2);
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, r, c;
	cin >> N >> r >> c;
	int n = pow(2, N);
	
	Z(n, r, c, 0);
	return 0;
}