#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int N;

string stringAdd(string N1) {
	string s = N1;
	int num;
	bool check = false;
	int i = N1.size() - 1, j = N1.size() - 1;
	if (N1[0] - '0' >= 5) {
		j++; s.append("0");
	}
	for (; i >= 0; i--, j--) {
		num = (N1[i] - '0') * 2;
		if (check) {
			num++;
			check = false;
		}
		if (num >= 10) {
			check = true;
		}
		s[j] = (num % 10) + '0';
	}
	if (check) s[0] = 1 + '0';
	return s;
}

string minusOne(string s) {
	int LastNum = s[s.size() - 1] - '0';
	s[s.size() - 1] = (LastNum - 1) + '0';
	return s;
}

void Hanoi(int N, int F, int S, int T) {
	if (N == 0) return;
	Hanoi(N - 1, F, T, S);
	cout << F << " " << T << '\n';
	Hanoi(N - 1, S, F, T);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	unsigned long long sum = pow(2, N);

	if (N < 63) {
		cout << sum - 1 << '\n';
	}
	else {
		string s = "4611686018427387904"; // 2^62 = 4611686018427387904
		for (int i = 62; i < N; i++) {
			s = stringAdd(s);
		}
		cout << minusOne(s) << '\n';
	}
	
	if (N <= 20) 
		Hanoi(N, 1, 2, 3);
	return 0;
}