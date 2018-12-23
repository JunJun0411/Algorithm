#include <iostream>
#include <string>
using namespace std;

int main() {
	string c;
	getline(cin, c);
	int len = c.length();
	int n = 0;
	for (int i = 0; i < len; i++) {
		while (c[i] == ' ' && c[i + 1] == ' ') i++;
		if (c[i] == ' ') n++;
	}
	if (c[0] == ' ') n--;
	if (c[len - 1] == ' ') n--;
	cout <<  n+1 << '\n';
}