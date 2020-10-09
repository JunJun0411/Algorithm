#include <iostream>
using namespace std;
const int Max = 50;
int main() {
	int N; cin >> N;
	char s[Max];
	int sum = 1;
	bool SS = true;
	for (int i = 0; i <N; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < N; i++) {
		if (s[i] == 'S'){
			sum++;
		}
		else if (s[i] == 'L') {
			i++;
			sum++;
			SS = false;
		}
	}
	if (SS) sum -= 1;
	cout << sum << '\n';
}