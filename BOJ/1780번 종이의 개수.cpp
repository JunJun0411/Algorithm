#include <iostream>
using namespace std;

int arr[2187][2187];
int N;
int num[3] = { 0, 0, 0 };	// -1, 0, 1 °¹¼ö

void quad(int n, int y, int x) {
	if (n == 1) {
		num[arr[y][x] + 1]++;
		return;
	}
	bool M = true, Z = true, P = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] == 1) P = false;
			else if (arr[i][j] == 0) Z = false;
			else if (arr[i][j] == -1) M = false;
		}
	}
	if (Z && M) num[2]++;
	else if (M && P) num[1]++;
	else if (Z && P) num[0]++;
	// 9µîºÐ
	else {
		quad(n / 3, y, x);
		quad(n / 3, y, x + (n / 3));
		quad(n / 3, y, x + (n / 3) * 2);
		quad(n / 3, y + (n / 3), x);
		quad(n / 3, y + (n / 3), x + (n / 3));
		quad(n / 3, y + (n / 3), x + ((n / 3) * 2));
		quad(n / 3, y + (n / 3) * 2, x);
		quad(n / 3, y + (n / 3) * 2, x + (n / 3));
		quad(n / 3, y + (n / 3) * 2, x + ((n / 3) * 2));
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	quad(N, 0, 0);
	for (int i = 0; i < 3; i++) {
		cout << num[i] << '\n';
	}
	return 0;
}