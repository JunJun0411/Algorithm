#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	stack<char> T;
	int count = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') {
			T.push(s[i]);
		}
		else { // s[i] == ')' 일 경우
			T.pop();
			if (s[i - 1] == '(') { //레이져일 경우
				count += T.size();
			}
			else { 
				count++;
			}
		}
	}
	cout << count << '\n';
}