#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	queue<int> Q;
	int N, M; cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push") {
			cin >> M;
			Q.push(M);
		}
		else if (s == "front") {
			if (!Q.empty())
				cout << Q.front() << '\n';
			else
				cout << "-1" << '\n';
		}
		else if (s == "back") {
			if(!Q.empty()) 
				cout << Q.back() << '\n';
			else 
				cout << "-1" << '\n';
		}
		else if (s == "size") {
			cout << Q.size() << '\n';
		}
		else if (s == "empty") {
			cout << Q.empty() << '\n';
		}
		else if (s == "pop") {
			if (!Q.empty()) {
				cout << Q.front() << '\n';
				Q.pop();
			}
			else
				cout << "-1" << '\n';
		}
	}
	return 0;
}