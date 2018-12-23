#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int al[26];
int main() {
	string s;
	while (cin >> s) {
		for (int i = 0; i < s.length(); i++) {
			if(s[i]>='a' && s[i]<='z')
				al[s[i] - 'a']++;
		}
		s.clear();
	}
	int Max = al[0];
	for (int i = 1; i < 26; i++) {
		Max = max(al[i], Max);
	}
	for (int i = 0; i < 26; i++) {
		if (Max == al[i]) {
			cout << (char)(i + 'a');
		}
	}
	cout << '\n';
	return 0;
}