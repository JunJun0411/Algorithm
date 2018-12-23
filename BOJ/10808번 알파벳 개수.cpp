#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s; cin >> s;
	vector<int> v(26, 0);
	for (int i = 0; i < s.length(); i++) {
		v[s[i] - 'a']++;
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << '\n';
}