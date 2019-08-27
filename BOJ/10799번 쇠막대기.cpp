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
		else { // s[i] == ')' �� ���
			T.pop();
			if (s[i - 1] == '(') { //�������� ���
				count += T.size();
			}
			else { 
				count++;
			}
		}
	}
	cout << count << '\n';
}