#include <iostream>
using namespace std;

long long city[10001];

int main() {
	int N, M; cin >> N;
	long long max = 0;
	for (int i = 0; i < N; i++) {
		cin >> city[i];
		if (max < city[i]) max = city[i];
	}
	cin >> M;
	long long left = 0;
	long long right = max;
	long long result = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		int sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid > city[i]) sum += city[i];
			else sum += mid;
		}
		if (sum > M) {
			right = mid - 1;
		}
		else {
			if (result < mid) result = mid;
			left = mid + 1;
		}
	}
	cout << result << '\n';
	return 0;
}