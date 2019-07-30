#include <iostream>
#include <queue>
using namespace std;

int T, M, S;
queue<int> Q;

void printMid(priority_queue<int> PQ, int size) {
	for (int i = 0; i < size; i++) {
		PQ.pop();
	}
	Q.push(PQ.top());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		priority_queue<int> PQ;
		
		int odd=0;
		cin >> M;
		if (M % 2) odd = 1;
		Q.push(M / 2 + odd);
		for (int i = 1; i <= M; i++) {
			cin >> S;
			PQ.push(S);
			if (i % 2) printMid(PQ, i/2);
		}
	}
	for (int t = 0; t < T; t++) {
		int num = Q.front(); Q.pop();
		cout << num << '\n'; 
		for(int j=0; j<num; j++) {
			cout << Q.front() << " "; Q.pop();
		}
		cout << '\n';
	}
}