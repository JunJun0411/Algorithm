#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t; cin >> s >> t;
	int m = 0, n = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < t.length(); j++) {
			if (s[i] == t[j]) { 
				s[i] = 0; 
				t[j] = 1;
				m++;
			}
		}
	}
	cout << s.length() + t.length() - 2 * m;
}