#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int a = 0;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		bool T = true;
		for (int i = 2; i < n; i++) {
			if (n%i == 0) T = false;
		}
		if (n == 1) T = false;
		if (T) a++;
	}
	cout << a << '\n';
}