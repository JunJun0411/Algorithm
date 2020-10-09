#include <iostream>
using namespace std;

const int MAX_N = 1000001;

int N, B, C;
int classes[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long answer = 0;

	cin >> N; // 시험장 수
	for (int i = 0; i < N; i++) {
		cin >> classes[i]; // 각 시험장 응시자 수
	}
	cin >> B >> C; // 총감독, 부감독 감시가능 수
	answer += N;
	for (int i = 0; i < N; i++) {
		if ((classes[i] -= B) > 0) {
			answer += (classes[i] % C ? classes[i] / C + 1 :classes[i] / C);
		}
	}

	cout << answer << '\n';
	return 0;
}