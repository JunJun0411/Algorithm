#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 91;

int N;
long long cache[MAXN];

long long Fibo(int X) {
	long long &ret = cache[X];
	if (ret != -1) return ret;
	if (X == 1) return ret;

	return ret = Fibo(X - 1) + Fibo(X - 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	memset(cache, -1, sizeof(cache));
	cache[0] = 0; cache[1] = 1;

	cout <<	Fibo(N) <<'\n';

	return 0;
}