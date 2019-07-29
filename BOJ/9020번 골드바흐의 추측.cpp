#include <iostream>
using namespace std;

const int MAX_N = 10001;
int sosu[MAX_N];
int T,n;

int main() {
	sosu[0] = sosu[1] = -1;
	for (int i = 2; i <= MAX_N; i++) {
		sosu[i] = i;
	}
	for (int i = 2; i <= MAX_N; i++) {
		if (sosu[i]) {
			for (int j = i*i; j <= MAX_N; j += i) {
				sosu[j] = i;
			}
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int left, right, mid;
		for (left = right = mid = n / 2; right <= n; left--, right++) {
			if (sosu[left] == left && sosu[right] == right) {
				cout << sosu[left] << " " << sosu[right] << '\n';
				break;
			}
		}
	}
}