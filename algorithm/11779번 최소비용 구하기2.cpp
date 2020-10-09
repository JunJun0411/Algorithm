#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#define INF 987654321
using namespace std;

vector<pair<int, int> > grape[1001];

int dijkstra(int src, int e, int n, int *trace) {
	vector<int> dist(n + 1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push({ 0, src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		// 이미 더 짧은 경로가 있다면 패스
		if (dist[here] < cost) continue;

		for (int i = 0; i < grape[here].size(); i++) {
			int nextDist = cost + grape[here][i].first;
			int there = grape[here][i].second;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				trace[there] = here;
				pq.push({ -nextDist, there });
			}
		}
	}
	return dist[e];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;

	cin >> N >> M;
	// 도시 u 에서 도시 v 로 가는 가중치 w
	int u, v, w;

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;

		// 가중치, 도착도시
		grape[u].push_back({ w, v });
	}
	// 출발지 도시, 목적지 도시
	int S, E;
	cin >> S >> E;

	int trace[1001];

	cout << dijkstra(S, E, N, & *trace) << '\n';
	
	stack<int> tra;
	int A = E;
	while (A != S) {
		tra.push(A);
		A = trace[A];
	}
	tra.push(A);
	
	cout << tra.size() << '\n';
	
	while (!tra.empty()) {
		cout << tra.top() << " ";
		tra.pop();
	}
	cout << '\n';

	return 0;
}