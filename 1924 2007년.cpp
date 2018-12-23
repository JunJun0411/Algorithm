#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector<int> v(12);
	v = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string day[7] = { "SUN","MON", "TUE","WED","THU","FRI","SAT" };
	int x, y; cin >> x >> y;
	for (int i = 0; i < x-1; i++) {
		y += v[i];
	}
	int k = y % 7;
	cout << day[k];
}