#include <iostream>
#include <queue>
using namespace std;
int N;

bool Prime(int num) {
	if (num < 2) return false;
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) return false;
	}
	return true;
}

void BFS(int a, int n) {
	if (n==0) cout << a << '\n';

	for (int i = 1; i < 10; i += 2) {
		int tmp = a * 10 + i;
		if (Prime(tmp)) {
			BFS(tmp, n - 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int prime[4] = { 2,3,5,7 };
	for (int i = 0; i < 4; i++) {
		BFS(prime[i], N - 1);
	}
	return 0;

	/*
	//메모리를 많이차지
	sosu[0] = sosu[1] = false;
	for (int i = 2; i < MAX_N; i++) {
		sosu[i] = true;
	}
	for (int i = 2; i*i < MAX_N; i++) {
		if (sosu[i]) {
			for (int j = i*i; j < MAX_N; j += i) {
				sosu[j] = false;
			}
		}
	}
	
	q.push(2); q.push(3); q.push(5); q.push(7);
	
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		if (a>=A && a<B) cout << a << '\n';
		else if(a<A) {
			for (int i = 1; i <= 9; i += 2) {
				if (sosu[a * 10 + i]) q.push(a * 10 + i);
			}
		}
	}*/
}