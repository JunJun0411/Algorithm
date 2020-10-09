#include <iostream>
#include <string>
using namespace std;
int main() {
	int al[101] = {};
	string S; cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] - 'a' < 0) al[S[i] - 'A']++;
		else al[S[i] - 'a']++;
	}
	int max = al[0], r = 0;
	for (int i = 1; i < 26; i++) {
		if (max < al[i]) {
			max = al[i];
			r = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (al[i]==al[r] && i != r) {
			cout << "?" << '\n';
			return 0;
		}
	}
	cout <<(char)(r + 'A') << '\n';

}