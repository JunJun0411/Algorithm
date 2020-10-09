#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v1(8);
	vector<int>	v2(8);
	vector<int>	v3(8);
	int m = 0, n = 0;
	for (int i = 0; i < 8; i++) {
		int X; cin >> X;
		v1[i]=v2[i]=v3[i] = X;
	}
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	reverse(v3.begin(), v3.end());
	for (int i = 0; i < 8; i++) {
		if (v1[i] == v2[i]) m++;
		else if (v1[i] == v3[i]) n++;
	}
	if (m == 8) cout << "ascending" << '\n';
	else if (n == 8) cout << "descending" << '\n';
	else cout << "mixed" << '\n';
}