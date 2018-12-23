#include <iostream>
#include <string>
using namespace std;

int happy(string s) {
	int n = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ':' &&s[i + 1] == '-' && s[i + 2] == ')')
			n++;
	}
	return n;
}
int sad(string s) {
	int n = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ':' &&s[i + 1] == '-' && s[i + 2] == '(')
			n++;
	}
	return n;
}
int main() {
	string s;
	getline(cin, s);

	if (!happy(s) && !sad(s)) cout << "none";
	else if (happy(s) == sad(s)) cout << "unsure";
	else if (happy(s) > sad(s)) cout << "happy";
	else cout << "sad";
}