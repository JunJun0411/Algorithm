#include <iostream>
#include <math.h>
using namespace std;

int N;

bool sosu(int X) {
	if (X == 1) return false;
	int route = sqrt(X);
	for (int i = 2; i <= route; i++) 
		if (X%i == 0) 
			return false;
	
	return true;
}

int main() {
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int X; cin >> X;
		sum += sosu(X);
	}
	cout << sum << '\n';

	return 0;
}