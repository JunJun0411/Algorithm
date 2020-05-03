#include <iostream> 
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 501;
int N;
int map[MAXN][MAXN];
int cache[MAXN][MAXN];

int DP(int y, int x) {
	int &ret = cache[y][x];
	if (ret != -1) return ret;                           
	if (y == N && x == N) return ret;

	return ret = max(DP(y + 1, x), DP(y + 1, x + 1)) + map[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> map[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= N; i++) {
		cache[N][i] = map[N][i];
	}

	cout << DP(1, 1) << '\n';


	return 0;
}