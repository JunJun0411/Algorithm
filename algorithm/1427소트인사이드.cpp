#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp1(int a, int b) {
	return (a > b);
}
int main() {
	string n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n.length(); i++) {
		v.push_back(n[i]-'0');
	}
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < n.length(); i++) {
		cout << v[i];
	}
	cout << "\n";
}