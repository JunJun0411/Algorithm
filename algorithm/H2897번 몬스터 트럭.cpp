#include <iostream>
#include <string>
using namespace std;

int A[5];
string s[50];


int main() {
	int R, C; cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> s[i];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i < R - 1 && j < C - 1) {
				int X = 0;
				if (s[i][j] == '#' || s[i][j + 1] == '#' || s[i + 1][j] == '#' || s[i + 1][j + 1] == '#') continue;
				if (s[i][j] == 'X') X++;
				if (s[i][j + 1] == 'X') X++;
				if (s[i + 1][j] == 'X') X++;
				if (s[i + 1][j + 1] == 'X') X++;
				A[X]++;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		cout << A[i] << '\n';
}