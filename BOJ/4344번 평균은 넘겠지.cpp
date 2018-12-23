#include <iostream>
#include <vector>
using namespace std;

int main() {
	int C; cin >> C;
	for (int i = 0; i < C; i++) {
		float N; cin >> N;
		vector<float> v(N);
		float sum = 0, st = 0;

		for (int i = 0; i < N; i++) {
			cin >> v[i];
			sum += v[i];
		}
		sum /= N;
		for (int i = 0; i < N; i++) {
			if (v[i] > sum) st++;
		}
		cout.setf(ios::fixed);
		cout.precision(3);
		cout << ((st / N) * 100) << "%" << '\n';
	}
}