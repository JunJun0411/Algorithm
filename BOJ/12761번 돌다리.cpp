#include <iostream>
#include <vector>
using namespace std;

const int Max = 100001;
vector<int> graph[Max];
int visited[Max];
int A, B, N, M;
int n = 0;
void DFS(int idx) {
	if (M == idx) return;
	n++;
	visited[idx] = true;
	if (idx !=1 && !visited[idx]) {
		if (idx * B <= M) DFS(idx*B);
		else if (idx *B > M && idx*A <= M) DFS(idx*A);
		else if (idx *A > M && idx + B <= M) DFS(idx + B);
		else if (idx + B > M && idx + A <= M) DFS(idx + A);
		else if (idx%B == 0 && idx / B >= M) DFS(idx / B);
		else if (idx%A == 0 && idx / B < M && idx / A >= M) DFS(idx / A);
		else if (idx / A < M && idx - B >= M) DFS(idx - B);
		else if (idx - B < M && idx - A >= M) DFS(idx - A);
	}
	else {
		if (idx + B <= M) DFS(idx+B);
		else if (idx +B > M && idx*B <= M) DFS(idx*B);
		else if (idx *B > M && idx + A <= M) DFS(idx + A);
		else if (idx + A > M && idx * A <= M) DFS(idx * A);
	}
}

int main() {
	cin >> A >> B >> N >> M; //A배 B배 동규 주미
	if (A > B) swap(A, B);
	for (int i = 0; i < Max; i++) {
		graph[i].push_back(i + A);
		graph[i].push_back(i + B);
		graph[i].push_back(i * A);
		graph[i].push_back(i * B);
		graph[i + A].push_back(i);
		graph[i + B].push_back(i);
		graph[i*A].push_back(i);
		graph[i*B].push_back(i);
	}
	DFS(N);
	cout << n;
}