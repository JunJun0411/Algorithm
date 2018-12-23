#include <iostream>
#include <string>
using namespace std;

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		int o = 0;
		int sum = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'O') {
				o++;
				sum += o;
			}
			else o = 0;
		}
		cout << sum << '\n';
	}
}