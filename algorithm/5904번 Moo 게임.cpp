#include <iostream>
#include <math.h>
using namespace std;
int N;
int k = 0;
int arr[28];

void Moo(int n, int k) {
	//기저 사례
	if (k == 0) {
		if (n == 1) cout << "m" << '\n';
		else cout << "o" << '\n';
		return;
	}
	// 1~s[k-1]에 n이 속하는 경우
	if (n <= arr[k - 1]) {
		Moo(n, k - 1);
	}
	// s[k-1]+1 ~ s[k-1]+1 + k+3 에 속하는 경우
	else if (n <= arr[k - 1] + k + 3) {
		if (n == arr[k - 1] + 1) cout << "m" << '\n';
		else cout << "o" << '\n';
		return;
	}
	// s[k-1]+1+k+3 ~ s[k]에 속하는 경우
	else {
		Moo(n - (arr[k - 1] + k + 3), k - 1);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int b = 3;
	arr[0] = b;
	for (int i = 1; 1000000000 > b;i++) {
		b += pow(2, (i) + 2) - 1;
		arr[i] = b;
		if (N > b) k = i + 1;
	}
	if (N > arr[0] && N <= arr[1]) k = 1;
	Moo(N, k);
	return 0;
}