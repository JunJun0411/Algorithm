#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	long long a = 1;
	long long b = 2;
	long long c;
	for (int i = 3; i <= n; i++) {
		c = (a + b)%10007;
		a = b;
		b = c;
	}
	if (n <=2) c = n;
	cout << c << '\n';
}