#include <iostream>
using namespace std;

int factorial(int x) {
	if(x) return x*factorial(x - 1);
	else return 1;
}
int main() {
	int N, a; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		int Sum = 0;
		for (int b = 0; b <= a / 2; b++) {
			for (int c = 0; c <= a / 3; c++) {
				if (a - 2 * b - 3 * c >= 0)
					Sum += factorial(a - b - 2 * c) / (factorial(a - 2 * b - 3 * c)*factorial(b)*factorial(c));
			}
		}
		cout << Sum << '\n';
	}
}