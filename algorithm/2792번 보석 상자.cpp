#include <iostream>
using namespace std;

long long jew[300001];

int main() {
	long long N, M; cin >> N >> M; //학생의 수, 보석의 수
	long long max = 0;
	for (int i = 0; i < M; i++) {
		cin >> jew[i];
		if (max < jew[i]) max = jew[i];
	}

	long long left = 1, right = max;
	long long result = 1000000000;
	while (left <= right) {
		long long sum = 0; //mid로 나누었을 때 받을 수 있는 학생 수
		long long mid = (left + right) / 2;
		for (int i = 0; i < M; i++) {
			sum += jew[i] / mid;
			if (jew[i] % mid != 0) sum++; //보석의 수가 mid 보다 낮을경우
		}

		if (sum <= N) {
			if (result > mid) result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << result << '\n';
}