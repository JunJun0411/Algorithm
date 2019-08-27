#include <iostream>
#include <string>
using namespace std;

char str[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, t; cin >> s >> t;
	int idx = 0;
	for (int i = 0; i < s.size(); i++) {
		str[idx++] = s[i];
		int j = t.size();
		if (s[i] == t[--j]) {
			bool check = false;
			for (int k = idx - 1; j >= 0; k--) {
				if (str[k] == t[j--]) {
					check = true;
				}
				else {
					check = false;
					break;
				}
			}
			if (check) idx -= t.size();
		}
	}
	if (idx == 0) {
		cout << "FRULA" << '\n';
	}
	else {
		for (int i = 0; i < idx; i++) {
			cout << str[i];
		}cout << '\n';
	}
	return 0;
}