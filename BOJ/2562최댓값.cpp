#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> vec(9);
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		vec[i] = x;
	}
	vector<int>::iterator it = max_element(vec.begin(), vec.end());
	cout << *it << endl;
	cout << (it - vec.begin()) + 1 << endl;
}