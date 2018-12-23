#include <iostream>
#include <string>
using namespace std;

int main() {
	string c;
	int n = 0;
	cin >> c;
	for (int i = 0; i < c.length(); i++) {
		if (c[i] == '1') { n += 2; }
		else if (c[i] == 'A' || c[i] == 'B' || c[i] == 'C') { n += 3; }
		else if (c[i] == 'D' || c[i] == 'E' || c[i] == 'F') { n += 4; }
		else if (c[i] == 'G' || c[i] == 'H' || c[i] == 'I') { n += 5; }
		else if (c[i] == 'J' || c[i] == 'K' || c[i] == 'L') { n += 6; }
		else if (c[i] == 'M' || c[i] == 'N' || c[i] == 'O') { n += 7; }
		else if (c[i] == 'P' || c[i] == 'Q' || c[i] == 'R' || c[i] == 'S') { n += 8; }
		else if (c[i] == 'T' || c[i] == 'U' || c[i] == 'V') { n += 9; }
		else if (c[i] == 'W' || c[i] == 'X' || c[i] == 'Y' || c[i] == 'Z') { n += 10; }
		else if (c[i] == '0') { n += 11; }
	}
	cout << n << '\n';
}