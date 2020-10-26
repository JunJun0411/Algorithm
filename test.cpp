#include <cstdio>
#include <iostream>
using namespace std;

int map[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	cout << n <<'\n';
	for (int i = 0; i < n; i++) {
		cout << map[i]<<" ";
	}
}