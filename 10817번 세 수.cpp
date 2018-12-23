#include <iostream>
#include <vector>
using namespace std;

int main() {
	int A, B, C; cin >> A >> B >> C;
	vector<int> v{ A, B, C }; 
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (v[i] < v[j]) {
				int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	cout << v[1];
}