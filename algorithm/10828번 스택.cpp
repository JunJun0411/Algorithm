#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
	int N; cin >> N;
	stack<int> D;
	for (int i = 0; i < N; i++) {
		string c; cin >> c;
		if (c == "push") {
			int x; cin >> x;
			D.push(x);
		}
		else if (c == "pop") {
			if (!D.empty()) {
				cout << D.top() << '\n';
				D.pop();
			}
			else cout << "-1" << '\n';
		}
		else if (c == "size") {
			cout << D.size() << '\n';
		}
		else if (c == "empty") {
			if (D.empty())
				cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if (c == "top") {
			if (D.empty())
				cout << "-1" << '\n';
			else cout << D.top() << '\n';
		}
	}
}