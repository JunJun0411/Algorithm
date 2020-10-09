#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		string A, c; cin >> A;
		char c1;
		int N; cin >> N;
		deque<int> v(N);
		cin >> c1;
		c.push_back(c1);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			if (i != N - 1) {
				cin >> c1;
				c.push_back(c1);
			}
		}
		cin >> c1;
		c.push_back(c1);
		deque<int>::iterator it_first;
		deque<int>::iterator it_last;
		it_first = v.begin();
		it_last = v.end();
		for (int i = 0; i < A.length(); i++) {
			
			if (A[i] == 'D') {
				if (!v.empty()) {
					v.pop_front();
					c.erase(c.begin() + 1);
				}
				else {
					cout << "error" ;
					
				}
			}
			else if (A[i] == 'R') {
				static bool X = true;
				if(X) v.pop_front =

			}
		}
		for (int i = 0; i < v.size(); i++) {
			cout << c.front();
			c.erase(c.begin());
			cout << v[i];
			if (i == v.size() - 1) {
				cout << c.front();
				c.erase(c.begin());
			}
		}
		cout << '\n';
	}
}