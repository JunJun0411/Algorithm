#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> v(26, -1);
	int x = 0;
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if(v[s[i]-'a'] == -1)
			v[s[i] - 'a'] = i;
	}
	for (int j = 0; j < 26; j++) {
		cout << v[j] << " ";
	}
	cout << '\n';
}