#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 4000001;
bool sosu[MAX_N];
int p[MAX_N];

int main() {
	int N; cin >> N;
	memset(sosu, 1, sizeof(sosu));
	sosu[0] = sosu[1] = false;
	int a = 0;
	for (long long i = 2; i <= N; i++) {
		if (sosu[i]) {
			for (long long j = i*i; j <= N; j += i) { 
				sosu[j] = false;
			}
			p[a++] = i;
		}
	}
	int left = 0, right = 0, cnt = 0, sum = 2;
	while ( right < a && left <= right ) {
		if (sum <= N) {
			if (sum == N) cnt++;
			right++;
			if (right >= a) break;
			sum += p[right];
		}
		else {
			sum -= p[left];
			left++;
			if (left > right) {
				right = left;
				if (left < a) sum = p[left];
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}