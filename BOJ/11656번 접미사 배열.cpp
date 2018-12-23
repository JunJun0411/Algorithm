#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string c[1000];
int main() {
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++) {
			c[i].push_back(s[j]);
		}
	}
	sort(c, c + s.length());
	for(int i=0; i<s.length(); i++) cout << c[i] << '\n';
}