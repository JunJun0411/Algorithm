#include <iostream>
#include <algorithm>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int result = 0, sum = 0, maxn = -1001;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		result = max(result, sum += x);
		if (sum < 0) sum = 0;
		maxn = max(maxn, x);
		if (x >= 0) flag = true;
	}
	if (!flag) cout << maxn << '\n';
	else cout << result << '\n';
	return 0;
}