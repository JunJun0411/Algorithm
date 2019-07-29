#include <iostream>
#include <math.h>
using namespace std;

const int MAX_N = 1299710;
int sosu[MAX_N];
int T, k;

int main() {
	int sqrtn = int(sqrt(1299709));
	sosu[0] = sosu[1] = -1;
	for (int i = 2; i <= 1299709; i++) {
		sosu[i] = i;
	}

	for (int i = 2; i <= sqrtn; i++) {
		if (sosu[i] == i) {
			for (int j = i*i; j <= 1299709; j += i) {
				sosu[j] = i;
			}
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;
		int left = k, right = k;

		while (sosu[left] != left || sosu[right] != right)
		{
			if (sosu[left] != left) {
				left--;
			}
			if (sosu[right] != right) {
				right++;
			}
		}
		int result = right - left;
		cout << result << '\n';
	}
}