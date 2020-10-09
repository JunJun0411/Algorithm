#include <iostream>
#include <string>
using namespace std;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		string s; cin >> s;
		int num = 0;
		bool tr = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				num++;
			}
			else if (s[i] == ')') {
				num--;
				if (num < 0) {
					cout << "NO" << '\n';
					tr = false;
					break;
				}
			}
		}
		if (num == 0) cout << "YES" << '\n';
		else if (num != 0 && tr) cout << "NO" << '\n';
	}
}