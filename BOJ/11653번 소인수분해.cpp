#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

const long long MAX_N = 10000001;
long long sosu[MAX_N];
queue<int> q;
long long n, m;
int main() {
	cin >> n;
	m = n;
	int sqrtn = int(sqrt(n));
	sosu[0] = sosu[1] = -1;
	for (long long i = 2; i <= n; i++) sosu[i] = i;

	for (long long i = 2; i <= sqrtn; i++) {
		if (sosu[i] == i) {
			for (long long j = i*i; j <= n; j += i) {
				sosu[j] = i;
			}
			while(m%i == 0) {
				q.push(i);
				m /= i;
			}
		}
	}
	if (m != 1) {
		q.push(m); 
	}
	while(!q.empty()) {
		cout << q.front() << '\n';
		q.pop();
	}
}