#include <iostream>
#include <math.h>
using namespace std;

const int MAX_N = 1000001;
int sosu[MAX_N];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sqrtn = int(sqrt(1000000));
	sosu[0] = sosu[1] = -1;
	for (int i = 2; i < MAX_N; i++) {
		sosu[i] = i;
	}
	for (int i = 2; i <= sqrtn; i++) {
		if (sosu[i] == i) {
			for (int j = i*i; j < MAX_N; j += i) {
				sosu[j] = i;
			}
		}
	}
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		int left = 3, right = n - 3;
		while (sosu[left] != left || sosu[right] != right) {
			right -= 2; left += 2;
			if (right < left) break;
		}
		if (right < left) cout << "Goldbach's conjecture is wrong." << '\n';
		else cout << n << " = " << left << " + " << right << '\n';
	}
}