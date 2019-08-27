#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int T, A, B, level;
bool visited[10000];
bool check;

// 변수 X가 소수인지 아닌지 알려주는 함수
bool sosu(int X) {
	for (int i = 2; i <= sqrt(X); i++) {
		if ((X % i) == 0) {
			return false;
		}
	}
	return true;
}

void BFS(int S, int E) {
	queue<int> q;
	memset(visited, false, sizeof(visited));
	check = true;
	int one, two, three, four;
	q.push(S);
	visited[S] = true;
	level = 0;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int Num = q.front(); 
			q.pop();

			if (Num == E) return;
			
			for (int i = 0; i < 10; i++) {
				four = Num % 1000 + i * 1000;
				three = Num - Num % 1000 + Num % 100 + i * 100;
				two = Num - (Num % 100) + Num % 10 + i * 10;
				one = Num - Num % 10 + i;

				if (i > 0 &&!visited[four] && sosu(four)) {
					q.push(four);
					visited[four] = true;
				}
				if (!visited[three] && sosu(three)) {
					q.push(three);
					visited[three]= true;
				}
				if (!visited[two] && sosu(two)) {
					q.push(two);
					visited[two] = true;
				}
				if (i%2 && !visited[one] && sosu(one)) {
					q.push(one);
					visited[one] = true;
				}
			}
		}
		level++;
	}
	check = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		
		BFS(A, B);
		if(check) cout << level++ << '\n';
		else cout << "Impossible" << '\n';
		
	}
	return 0;
}