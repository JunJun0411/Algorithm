#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;


vector<pair<int, int> > grape[20001];

vector<int> dijkstra(int src, int v) {
	vector<int> dist(v+1, INF);
	dist[src] = 0;
	
	// 가중치, 정점
	priority_queue<pair <int, int> > pq;
	pq.push({ 0, src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		// 이미 더 짧은 경로가 있는 경우 무시
		if (dist[here] < cost) continue;

		for (int i = 0; i < grape[here].size(); i++) {
			int dis = cost + grape[here][i].first;
			int there = grape[here][i].second;

			if (dist[there] > dis) {
				dist[there] = dis;
				pq.push({ -dis, there });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 정점, 간선, 시작정점
	int V, E, K;
	int u, v, w;
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;		

		// 가중치, 연결정점
		grape[u].push_back({ w, v });
	}

	vector<int> vec = dijkstra(K, V);
	for (int i = 1; i <= V; i++) {
		if(vec[i] != INF) cout << vec[i] << '\n';
		else cout << "INF" << '\n';
	}

	return 0;
}