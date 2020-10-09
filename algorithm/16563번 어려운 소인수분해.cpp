#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
const int MAX_N = 5000001;
int sosu[MAX_N];
queue<int> q;
vector<int> vec(MAX_N);
int T, n;
int cnt = 0;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sqrtn1 = int(sqrt(MAX_N));
	sosu[0] = sosu[1] = -1;
	for (int i = 2; i <= 5000000; i++) {
		sosu[i] = i;
	}
	for (int i = 2; i <= sqrtn1; i++) {
		if (sosu[i] == i) {
			for (int j = i*i; j <= 5000000; j += i) {
				sosu[j] = i;
			}
			vec[cnt++] = i;
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int m = n;
		int sqrtn = int(sqrt(n));
		for (int i = 0; i < cnt; i++) {
				while (m % vec[i] == 0) {
					q.push(vec[i]);
					m /= vec[i];
				}
				if (m == 1) break;
		}
		if (m != 1) q.push(m);

		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << '\n';
	}
}