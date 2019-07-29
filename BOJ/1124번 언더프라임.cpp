#include <iostream>
#include <math.h>
using namespace std;

const int MAX_N = 100001;
int sosu[MAX_N];
int n, m, k;
int result = 0;
int main() {
	cin >> n >> k;

	int sqrtn = int(sqrt(k));
	sosu[0] = sosu[1] = -1;
	for (int i = 2; i < k; i++) {
		sosu[i] = i;
	}
	for (int i = 2; i <= sqrtn; i++) {
		if (sosu[i] == i) {
			for (int j = i*i; j <= k; j += i) {
				sosu[j] = i;
			}
		}
	}

	for (int a = n; a <= k; a++) {
		m = a;
		int cnt = 0;
		int sqrtn = int(sqrt(m));

		for (int i = 2; i <= sqrtn; i++) {
			if (sosu[i] == i) {
				while (m%i == 0) {
					m /= i;
					cnt++;
				}
			}
		}
		if (m != 1) cnt++;
		if (sosu[cnt] == cnt) result++;
	}
	cout << result << '\n';
}