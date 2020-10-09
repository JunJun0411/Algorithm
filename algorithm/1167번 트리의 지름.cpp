#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
#define MAX 100001

int V;
bool visited[MAX];
vector<pair<int, int > >vec[MAX];

int dist = 0, Vertex = 0;

void DFS(int node, int cost) {
	if (visited[node]) return;
	visited[node] = true;

	if (dist < cost) {
		dist = cost;
		Vertex = node;
	}

	for (int i = 0; i < vec[node].size(); i++) {
		DFS(vec[node][i].first, cost + vec[node][i].second);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V; int E1, E2, value;
	for (int i = 0; i < V; i++) {
		cin >> E1;
		while (1) {
			cin >> E2;
			if (E2 == -1) break;
			cin >> value;
			vec[E1].push_back({ E2, value });
		}
	}
	memset(visited, false, sizeof(visited));
	DFS(E1, 0);
	memset(visited, false, sizeof(visited));
	dist = 0;
	DFS(Vertex, 0);
	cout << dist << '\n';
	return 0;
}