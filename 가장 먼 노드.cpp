#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 20001

using namespace std;

int N;
bool visited[MAX];
vector<vector<int>> grape(MAX);

int bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = true;
	vector<int> cnt;

	while (!q.empty()) {
		int size = q.size();
		cnt.push_back(size);
		int cnt = size;
		while (size--) {
			int num = q.front();
			q.pop();
			
			int nsize = grape[num].size();
			

			for (int i = 0; i < nsize; i++) {
				// 이미 방문한 노드일 경우 continue
				if (visited[grape[num][i]]) continue;

				q.push(grape[num][i]);
				visited[grape[num][i]] = true;
			}
		}
	}
	return cnt[cnt.size() - 1];
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int size = edge.size();

	for (int i = 0; i < size; i++) {
		grape[edge[i][0]].push_back(edge[i][1]);
		grape[edge[i][1]].push_back(edge[i][0]);
	}
	
	cout << bfs() <<'\n';

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>> edge = { {3,6},{4,3}, {3,2},{1,3},{1,2},{2,4},{5,2} };

	solution(N, edge);

	return 0;
}