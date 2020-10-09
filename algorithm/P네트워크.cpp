#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[201];

void dfs(vector<vector<int> > computers, int i, int n) {
	visited[i] = true;

	for (int j = 0; j < n; j++) {
		if (!visited[j] && computers[i][j]) dfs(computers, j, n);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(computers, i, n);
			answer++;
		}
	}

	return answer;
}

int main() {
	vector<vector<int> > vec1 = { {1,1,0},{1,1,1},{0,1,1} };

	cout << solution(3, vec1);

	return 0;
}