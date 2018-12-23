#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int A, B, C; cin >> A >> B >> C;
	int D = A*B*C;
	vector<int> v(10);
	string s;
	char c;
	for (int i = 0; D / 10 != 0;i++) {
		c = (D % 10) + '0';
		s.push_back(c);
		D /= 10;
	}
	s.push_back(D+'0');
	
	for (int i = 0; i < s.length(); i++) v[s[i]-'0']++;
	for (int i = 0; i < 10; i++) {
		cout << v[i] << '\n';
	}
}