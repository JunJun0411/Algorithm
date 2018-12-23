#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int a, b;
	int k = N;
	int i = 0;
	
	do {
		if (N < 10) {
			N = N * 11;
			i++;
		}
		else {
			a = N / 10;
			b = N % 10;
			N = a + b;
			N = b * 10 + N % 10;
			i++;
		}
	} while (N != k);
	cout << i << '\n';
}