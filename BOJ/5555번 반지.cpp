#include <iostream>
#include <string>
#include <vector>
using namespace std;

int m = 0;
int main() {
	string s; cin >> s;// ã���� �ϴ� ���ڿ�
	int N; cin >> N; //���� ����
	vector<string> v(N); //�������ڿ�
	for (int i = 0; i < N; i++) { //i��° ����
		cin >> v[i];
		bool ring = false;
		for (int j = 0; j < v[i].length(); j++) { //j��° ����
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