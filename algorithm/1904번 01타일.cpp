#include <iostream> 
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000001;
int N;
unsigned short cache[MAXN];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	memset(cache, -1, sizeof(cache));
	cache[1] = 1; cache[2] = 2;
	for (int i = 3; i <= N; i++) {
		cache[i] = ((cache[i - 1]) + (cache[i - 2])) % 15746;
	}
	cout << cache[N] % 15746 << '\n';


	return 0;
}