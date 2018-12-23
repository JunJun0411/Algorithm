#include <iostream> 
#include <deque>
#include <string>
using namespace std;

int main() {
	deque<int> D;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		int x;
		if (input == "push_front") {
			cin >> x;
			D.push_front(x);
		}
		else if (input == "push_back") {
			cin >> x;
			D.push_back(x);
		}
		else if (input == "pop_front") {
			if (D.empty())
				cout << "-1" << endl;
			else {
				cout << D.front() << endl;
				D.pop_front();
			}
		}
		else if (input == "pop_back") {
			if (D.empty())
				cout << "-1" << endl;
			else {
				cout << D.back() << endl;
				D.pop_back();
			}
		}
		else if (input == "size") {
			cout << D.size() << "\n";
		}
		else if (input == "empty") {
			if (D.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if (input == "front") {
			if (D.empty())
				cout << "-1" << "\n";
			else 
				cout << D.front() << "\n";
		}
		else if (input == "back") {
			if (D.empty())
				cout << "-1" << "\n";
			else
				cout << D.back() << "\n";
		}
	}
}

