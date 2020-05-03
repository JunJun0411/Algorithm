#include <iostream>
#include <cstring>	
using namespace std;

const int MAXN = 101;
int T, N;
long long cache[MAXN] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	cache[0] = 0; cache[1] = 1;
	cache[2] = 1; cache[3] = 1;
	cache[4] = 2; cache[5] = 2;
	cache[6] = 3; cache[7] = 4;
	for (int i = 8; i < MAXN; i++) {
		cache[i] = cache[i - 1] + cache[i - 5];
	}
	while(T--) {
		cin >> N;
		cout << cache[N] << '\n';
	}

	return 0;
}