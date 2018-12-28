#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001
bool visited[MAX];
int N, T;

int BFS(int n, int m) {
	int num = 0;
	queue<int> q;
	visited[n] = true;
	q.push(n);

	while (1) {
		int size = q.size();

		for(int i=0; i < size; i++){
			n = q.front();
			q.pop();
			if (n == m)  return num;
			if (n>0 && !visited[n - 1]){//주의 !visited가 앞에 있으면 런타임오류
				q.push(n - 1); 
				visited[n - 1] = true; 
			}
			if ( n<T && n<100000 && !visited[n + 1]){//주의 !visited가 앞에 있으면 런타임오류
				q.push(n + 1); 
				visited[n + 1] = true; 
			}
			if ( n<T && n*2<=100000&&!visited[n * 2]) {//주의 !visited가 앞에 있으면 런타임오류
				q.push(n * 2); 
				visited[n * 2] = true; 
			}
		}
		num++;
	}
}
int main() {
	cin >> N >> T;
	cout << BFS(N, T) << '\n';
	return 0;
}