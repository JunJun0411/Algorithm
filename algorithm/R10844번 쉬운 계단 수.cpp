#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000000;
int N;
int cache[10][101];

int stair(int num, int len) {
	if (num > 9 || num < 0) return 0;
	int &ret = cache[num][len];
	if (ret != -1) return ret;
	
	return ret = (stair(num - 1, len - 1) + stair(num + 1, len - 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < 10; i++) cache[i][1] = 1;

	int sum = 0;
	for (int i = 1; i <= 9; i++) {
		sum += stair(i, N);
		sum %= MOD;
	}

	cout << sum << '\n';

	return 0;
}