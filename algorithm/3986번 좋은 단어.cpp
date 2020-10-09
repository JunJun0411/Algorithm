#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		bool good = true;
		int countA = 0;
		for (int i = 0; s[i]; i++) {
			if (s[i] == 'A') countA++;
		}
		int countB = s.length() - countA;
		if (!(countA % 2) && !(countB % 2)) {
			stack<char> T;
			T.push(0);
			T.push(s[0]);
			for (int i = 1; s[i]; i++) {
				if (s[i] == T.top()) T.pop();
				else T.push(s[i]);
			}
			if (T.size() > 4) good = false;
		}
		else good = false;
		if (good) count++;
	}
	cout << count << '\n';
}