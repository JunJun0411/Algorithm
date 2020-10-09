#include <iostream>
#include <string>
using namespace std;

int N;
int tree[64][64];

void quad(int n, int y, int x) {
	if (n == 1) {
		cout << tree[y][x];
		return;
	}

	bool zero = true, one = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (tree[i][j]) zero = false;
			else one = false;
		}
	}
	if (zero) cout << 0;
	else if (one) cout << 1;
	else {
		cout << "(";
		quad(n / 2, y, x);
		quad(n / 2, y, x + n / 2);
		quad(n / 2, y + n / 2, x);
		quad(n / 2, y + n / 2, x + n / 2);
		cout << ")";
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			tree[i][j] = s[j] - '0';
		}
	}
	quad(N, 0, 0);
	cout << '\n';
	return 0;
}