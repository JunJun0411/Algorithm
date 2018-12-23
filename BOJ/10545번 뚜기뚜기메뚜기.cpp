#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> v(9);
	int n;
	for (int i = 1; i < 10; i++) {
		cin >> n;
		v[n - 1] = i;
	}
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('a'<= s[i] && s[i]<='c') {
			if ('a' <= s[i+1] && s[i+1] <= 'c') {
				for (int j = 0; j < s[i] - 'a' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
				cout << "#";
			}
			else {
				for (int j = 0; j < s[i] - 'a' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
			}
		}
		else if ('d' <= s[i] && s[i] <= 'f') {
			if ('d' <= s[i+1] && s[i+1] <= 'f') {
				for (int j = 0; j < s[i] - 'd' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
				cout << "#";
			}
			else {
				for (int j = 0; j < s[i] - 'd' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
			}
		}
		else if ('g' <= s[i] && s[i] <= 'i') {
			if ('g' <= s[i+1] && s[i+1] <= 'i') {
				for (int j = 0; j < s[i] - 'g' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
				cout << "#";
			}
			else {
				for (int j = 0; j < s[i] - 'g' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
			}
		}
		else if ('j' <= s[i] && s[i] <= 'l') {
			if ('j' <= s[i+1] && s[i+1] <= 'l') {
				for (int j = 0; j < s[i] - 'j' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
				cout<< "#";
			}
			else {
				for (int j = 0; j < s[i] - 'j' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
			}
		}
		else if ('m' <= s[i] && s[i] <= 'o') {
			if ('m' <= s[i+1] && s[i+1] <= 'o') {
				for (int j = 0; j < s[i] - 'm' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
				cout << "#";
			}
			else {
				for (int j = 0; j < s[i] - 'm' + 1; j++)
					cout << v[(s[i] - 'a' + 3) / 3];
			}
		}
		else if ('p' <= s[i] && s[i] <= 's') {
			if ('p' <= s[i+1] && s[i+1] <= 's') {
				if (!(s[i] == 's')) {
					for (int j = 0; j < s[i] - 'p' + 1; j++) cout << v[(s[i] - 'a' + 3) / 3]; cout << "#";
				}
				else {
					for (int j = 0; j < s[i] - 'p' + 1; j++) cout << v[(s[i] - 'a' + 2) / 3]; cout << "#";
				}
			}
			else {
				if (!(s[i] == 's')) {
					for (int j = 0; j < s[i] - 'p' + 1; j++) cout << v[(s[i] - 'a' + 3) / 3];
				}
				else {
					for (int j = 0; j < s[i] - 'p' + 1; j++) cout << v[(s[i] - 'a' + 2) / 3];
				}
			}
		}
		else if ('t' <= s[i] && s[i] <= 'v') {
			if ('t' <= s[i+1] && s[i+1] <= 'v') {
				for (int j = 0; j < s[i] - 't' + 1; j++)
					cout << v[(s[i] - 'a' + 2) / 3]; cout << "#";
			}
			else {
				for (int j = 0; j < s[i] - 't' + 1; j++)
					cout << v[(s[i] - 'a' + 2) / 3];
			}
		}
		else if ('w' <= s[i] && s[i] <= 'z') {
			if ('w' <= s[i+1] && s[i+1] <= 'z') {
				if (!(s[i] == 'z')) {
					for (int j = 0; j < s[i] - 'w' + 1; j++) cout << v[(s[i] - 'a' + 2) / 3]; cout << "#";
				}
				else {					for (int j = 0; j < s[i] - 'w' + 1; j++)cout << v[(s[i] - 'a' + 1) / 3]; cout << "#";
				}
			}
			else {
				if (!(s[i] == 'z')) {
					for (int j = 0; j < s[i] - 'w' + 1; j++) cout << v[(s[i] - 'a' + 2) / 3];
				}
				else {
					for (int j = 0; j < s[i] - 'w' + 1; j++) cout << v[(s[i] - 'a' + 1) / 3];
				}
			}
		}
	}
	cout << '\n';
}