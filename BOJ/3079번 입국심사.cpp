#include <iostream>
using namespace std;

long long Time[100001];

int main() {
	int N; long long M; cin >> N >> M;
	long long max = 0;
	for (int i = 0; i < N; i++) {
		cin >> Time[i];
		if (max < Time[i]) max = Time[i];
	}
	long long left = 1, right = max * M;
	long long result = max * M;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += mid / Time[i];
		}

		if (sum >= M) {
			if (result > mid) result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << result << '\n';

}