#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string N; cin >> N;
	int i;
	int a=0, k=0;
	vector<int> result(34);
	for (i = N.length() - 1; i >= 0; i--) {
		
		
		if (i%3 == (N.length()-1)%3) {
			a = 0;
			if (N[i]-'0') result[k/3]++;
		}
		else {
			if (N[i]-'0')	a = 2 * (k%3);
			else a = 0;
		}
		result[k/3] += a;
		k++;
	}
	k--;
	for (int j = k/3; j >=0; j--) {
		cout << result[j];
	}
	cout << '\n';
}