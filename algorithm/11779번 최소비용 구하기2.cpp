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
		// �̹� �� ª�� ��ΰ� �ִٸ� �н�
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