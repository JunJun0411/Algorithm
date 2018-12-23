#include <iostream>
using namespace std;

bool baesu(int x) {
	while (x != 1 && x%2 ==0) {
		x /= 2;
	}
	if (x == 1) return true;
	else return false;
}
int main() {
	while (1) {
		int X; cin >> X;
		int Y = X;
		int n = 0, m = 0;
		while (X != 1) {
			if (X % 3 == 0) {
				X /= 3;
				n++; m++;
			}
			else if (X % 3 == 1 && !baesu(X)) {
				X -= 1;
				n++;
			}
			else if (X % 2 == 0) {
				X /= 2;
				n++;
			}
			else {
				X -= 1;
				n++;
			}
			cout << X << " " << n << '\n';
		}
	}
}