#include <iostream>
#include <string>
using namespace std;

int main() {
	int T = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		bool Group = true;
		for (int i = 0; i < s.length(); i++) {
			for (int j = i + 2; j < s.length(); j++) {
				if (s[i] != s[i + 1]) {
					if (s[i] == s[j]) {
						Group = false;
					}
				}
			}
		}
		if (Group) T++;
	}
	cout << T;
}