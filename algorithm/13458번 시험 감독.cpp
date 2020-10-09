#include <iostream>
using namespace std;

const int MAX_N = 1000001;

int N, B, C;
int classes[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long answer = 0;

	cin >> N; // ������ ��
	for (int i = 0; i < N; i++) {
		cin >> classes[i]; // �� ������ ������ ��
	}
	cin >> B >> C; // �Ѱ���, �ΰ��� ���ð��� ��
	answer += N;
	for (int i = 0; i < N; i++) {
		if ((classes[i] -= B) > 0) {
			answer += (classes[i] % C ? classes[i] / C + 1 :classes[i] / C);
		}
	}

	cout << answer << '\n';
	return 0;
}