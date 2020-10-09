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
		// �̹� �� ª�� ��ΰ� �ִٸ� �н�
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
	// ���� u ���� ���� v �� ���� ����ġ w
	int u, v, w;
	
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;

		// ����ġ, ��������
		grape[u].push_back({ w, v });
	}
	// ����� ����, ������ ����
	int S, E;
	cin >> S >> E;

	cout << dijkstra(S, E, N) << '\n';

	return 0;
}