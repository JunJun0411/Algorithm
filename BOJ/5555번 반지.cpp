#include <iostream>
#include <string>
#include <vector>
using namespace std;

int m = 0;
int main() {
	string s; cin >> s;// 찾고자 하는 문자열
	int N; cin >> N; //반지 개수
	vector<string> v(N); //반지문자열
	for (int i = 0; i < N; i++) { //i번째 반지
		cin >> v[i];
		bool ring = false;
		for (int j = 0; j < v[i].length(); j++) { //j번째 문자
			if (s[0] == v[i][j]) {
				bool neg = true;
				for (int k = 0; k < s.length(); k++)
					if (v[i][(j + k) % v[i].length()] != s[k]) {
						neg = false;
						break;
					}
				if (neg) {
					ring = true;
					break;
				}
			}
		}
			if (ring)
				m++;
	}
	cout << m << '\n';
}