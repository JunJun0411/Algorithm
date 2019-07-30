#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 50001

int N, T;
vector<pair<int, int> >vec[MAX];
bool visited[MAX];
int maxcount, dist, vertex;

void DFS(int node, int cost, int num) {
	if (maxcount < num) {
		maxcount = num;
		vertex = node;
		dist = cost;
	}

	else if(maxcount == num && dist > cost) {
				dist = cost;
				vertex = node;
	}

	visited[node] = true;
	for(unsigned int i = 0; i < vec[node].size(); i++) {
		if(!visited[vec[node][i].first])
			DFS(vec[node][i].first, cost + vec[node][i].second ,num + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T;
	int a, b, c;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		vec[a].push_back({ b, c });
		vec[b].push_back({ a, c });
	}
	// 어떤 한 점으로부터 가장 거리가 먼 vertex구하기
	maxcount = 1;
	DFS(1, 0, 1);

	// 다시한번 dist를 초기화 한 후 maxcount만큼 떨어진 vertex까지 최소가 되는 거리 구하기
	maxcount = 1; dist = 0;
	memset(visited, false, sizeof(visited));
	DFS(vertex, 0, 1);

	if (dist % T) dist = dist / T + 1;
	else dist = dist / T;

	cout << dist << '\n';
	return 0;
}