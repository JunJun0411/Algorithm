#include <iostream>
using namespace std;

int main() {
	long long X, Y, W; cin >> X >> Y;
	long long Z = (Y * 100) / X;
	
	long long result = 1000000000;
	long long left = 0, right = 1000000000 ;

	while(left <= right) {
		
		long long mid = (left + right) / 2;
		long long A = Y + mid, B = X + mid;
		W = (A * 100) / B;
		if (mid == 1000000000 && Y != 980000000) {	cout << "-1" << '\n'; return 0;		}
		if (W > Z) {
			right = mid - 1;
			if (result > mid) result = mid;
		}
		else left = mid + 1;
	} 
	cout << result << '\n';
	return 0;
}