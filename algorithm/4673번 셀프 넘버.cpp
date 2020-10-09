#include <iostream>
#include <vector>
using namespace std;

int selfnumber(int n) {
	int r = 0; int d = n;
	while (n / 10 != 0) {
		r += n % 10;
		n /= 10;
	}
	return n = n + d + r;
}
int main() {
	vector<int> v(10000);
	for (int i = 0; i < 10000; i++) {
		v[i]= i;
	}
	for (int i = 0; i < 10000; i++) {
		if(selfnumber(i)<10000)
			v[selfnumber(i)] = 0;
	}
	for (int i = 0; i < 10000; i++) {
		if (v[i] != 0)
			cout << v[i] << " ";
	}
}