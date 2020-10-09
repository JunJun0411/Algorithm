#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s; cin >> s;
	int p = 0, q = 0;
	int mul = 1;
	int sum = 0;
	bool good = true;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') p++;
		else if (s[i] == '[') q++;
		else if (s[i] == ')') p--;
		else if (s[i] == ']') q--;
		else good = false;
		if (p < 0 || q < 0) good = false;
	}
	if (p || q) good = false;
	if (good) {
		for (int i = 0; s[i]; i++) {
			if (s[i] == '(') {
				mul *= 2;
				if (s[i + 1] == ')') sum += mul;
			}
			else if (s[i] == '[') {
				mul *= 3;
				if (s[i + 1] == ']') sum += mul;
			}
			else if (s[i] == ')') {
				mul /= 2;
			}
			else if (s[i] == ']') {
				mul /= 3;
			}
			else good = false;
		}
	}
	if (!good) sum = 0;
	cout << sum << '\n';
}