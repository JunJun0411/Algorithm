#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

vector<pair<int, int> > grape[801];

vector<int> dijkstra(int src, int n) {
	vector<int> dist(n + 1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push({ 0, src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		// 더 짧은 경로 있다면 패스
		if (dist[here] < cost ) continue;

		for (int i = 0; i < grape[here].size(); i++) {
			int nextDist = cost + grape[here][i].first;
			int there = grape[here][i].second;

			if (dist[there] > nextDist ) {
				dist[there] = nextDist;
				pq.push({ -nextDist, there });

			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, E;
	cin >> N >> E;
	
	for (int i = 0; i < E; i++) {
		// a번 정점에서 b번 정점까지 양방향 길이 c
		int a, b, c;
		cin >> a >> b >> c;

		grape[a].push_back({ c, b });
		grape[b].push_back({ c, a });
	}

	// 반드시 거쳐야 하는 정점 번호
	int V1, V2;
	cin >> V1 >> V2;

	vector<int> first = dijkstra(1, N);
	vector<int> second = dijkstra(V1, N);
	vector<int> third = dijkstra(V2, N);

	int R1 = first[V1] + second[V2] + third[N];
	int R2 = first[V2] + third[V1] + second[N];

	if (R1 < 0 || R1 >= INF) R1 = INF;
	if (R2 < 0 || R2 >= INF) R2 = INF;

	if (R1 == INF || R2 == INF) {
		if (R1 == INF && R2 == INF) cout << "-1" << '\n';
		else if (R1 == INF) cout << R2 << "\n";
		else cout << R1 << '\n';
	}
	else {
		if (R1 <= R2) cout << R1 << '\n';
		else cout << R2 << '\n';
	}

	return 0;
}