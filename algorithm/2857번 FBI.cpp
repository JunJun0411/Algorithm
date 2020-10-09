#include <iostream>
#include <string>
using namespace std;

bool FBI(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'F' && s[i + 1] == 'B' &&s[i + 2] == 'I') {
			return true;
		}
	}
	return false;
}
int main() {
	string c[5];
	for (int i = 0; i < 5; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < 5; i++){
		if(FBI(c[i]))
			cout << i+1 << '\n';
	}
	if (!FBI(c[0]) && !FBI(c[1]) && !FBI(c[2]) && !FBI(c[3]) && !FBI(c[4])) {
		cout << "HE GOT AWAY!" << '\n';
	}
}