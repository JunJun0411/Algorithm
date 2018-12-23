#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char c[100];
	cin >> c;
	int i = 0;
	while(i<strlen(c)) {
		cout << c[i];
		i++;
		if (i % 10 == 0) {
			cout << '\n';
		}
	}
}