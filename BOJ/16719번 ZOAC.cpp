#include <iostream>
#include <string>
using namespace std;
#define INF 999

bool is[101];
string s;

void rec(int a, int b) {
	int min = INF; int idx = -1;
	for (int i = a; i < b + 1; i++) {
		if (!is[i] && min > s[i]) {
			min = s[i];
			idx = i;
		}
	}
	if (min == INF) return; //변함 없으면 탈출
	is[idx] = true;
	for (int j = 0; s[j]; j++) {
		if (is[j]) cout << s[j];
	}
	cout << '\n';
	rec(idx + 1, b);#include <iostream>
#include <string>
using namespace std;
#define INF 999

bool is[101];
string s;

void rec(int a, int b) {
	int min = INF; int idx = -1;
	for (int i = a; i < b + 1; i++) {
		if (!is[i] && min > s[i]) {
			min = s[i];
			idx = i;
		}
	}
	if (min == INF) return; //변함 없으면 탈출
	is[idx] = true;
	for (int j = 0; s[j]; j++) {
		if (is[j]) cout << s[j];
	}
	cout << '\n';
	rec(idx + 1, b);
	rec(a, idx - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	rec(0, s.size() - 1);
}
	rec(a, idx - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	rec(0, s.size() - 1);
}