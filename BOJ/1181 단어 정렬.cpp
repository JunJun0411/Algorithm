#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string& a ,const string& b) {
	if (a.length() == b.length())
		return (a < b);
	else
		return a.length() < b.length();
}
int main() {
	int T; cin >> T;
	vector<string> v(T);
	for (int i = 0; i < T; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < T; i++) {
		if (i == 0)
			cout << v[i] << '\n';
		else
			if (v[i] != v[i - 1])
				cout << v[i] << '\n';
	}
}