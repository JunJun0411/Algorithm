#include <iostream>
#include <math.h>
using namespace std;
int N;
int k = 0;
int arr[28];

void Moo(int n, int k) {
	//���� ���
	if (k == 0) {
		if (n == 1) cout << "m" << '\n';
		else cout << "o" << '\n';
		return;
	}
	// 1~s[k-1]�� n�� ���ϴ� ���
	if (n <= arr[k - 1]) {
		Moo(n, k - 1);
	}
	// s[k-1]+1 ~ s[k-1]+1 + k+3 �� ���ϴ� ���
	else if (n <= arr[k - 1] + k + 3) {
		if (n == arr[k - 1] + 1) cout << "m" << '\n';
		else cout << "o" << '\n';
		return;
	}
	// s[k-1]+1+k+3 ~ s[k]�� ���ϴ� ���
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