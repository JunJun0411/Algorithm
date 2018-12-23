#include <iostream>
using namespace std;

int main() {
	int sum=0;
	for (int i = 0; i < 5; i++) {
		int X; cin >> X;
		if (X < 40) X = 40;
		sum += X;
	}
	cout << sum / 5 << '\n';
}