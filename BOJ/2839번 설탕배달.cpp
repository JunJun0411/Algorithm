#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int a = 0;
	int k, r;
	while (N) {
		r = N - (3 * a);
		if (r % 5 == 0) {
			k = r / 5;
			cout << a + k << '\n';
			N = 0;
		}
		else {
			if (N - (3*a) < 3) {
				cout << "-1" << '\n'; 
				N = 0;
			}
			else
				a++;
		}
	}
}