#include <iostream>
#include <string>
using namespace std;

int main() {
	int N; cin >> N;
	string c; cin >> c;
	int val =0;
	for (int i = 0; i < N; i++) {
		val += c[i] - '0';
	}
	cout << val;
}