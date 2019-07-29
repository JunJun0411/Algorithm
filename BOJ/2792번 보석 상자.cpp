#include <iostream>
using namespace std;

long long jew[300001];

int main() {
	long long N, M; cin >> N >> M; //�л��� ��, ������ ��
	long long max = 0;
	for (int i = 0; i < M; i++) {
		cin >> jew[i];
		if (max < jew[i]) max = jew[i];
	}

	long long left = 1, right = max;
	long long result = 1000000000;
	while (left <= right) {
		long long sum = 0; //mid�� �������� �� ���� �� �ִ� �л� ��
		long long mid = (left + right) / 2;
		for (int i = 0; i < M; i++) {
			sum += jew[i] / mid;
			if (jew[i] % mid != 0) sum++; //������ ���� mid ���� �������
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