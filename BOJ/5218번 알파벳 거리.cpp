#include <iostream>
#include <string>
using namespace std;

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string x, y; cin >> x >> y;
		cout << "Distances: ";
		for (int i = 0; i < x.length(); i++) {
			if (x[i] <= y[i]) cout << y[i] - x[i] << " ";
			else cout << (y[i] - 'A') + 26 - (x[i] - 'A') << " ";
		}
		cout << '\n';
	}
}