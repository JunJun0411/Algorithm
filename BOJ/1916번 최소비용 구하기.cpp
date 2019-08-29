#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

vector<pair<int, int> > grape[1001];

int dijkstra(int src, int e, int n) {
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

	cout << dijkstra(S, E, N) << '\n';

	return 0;
}