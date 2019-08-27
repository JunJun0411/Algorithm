#include <iostream>
#include <queue>
#include <vector>
#include<functional>
using namespace std;

#define Max 100001

int n, k;
priority_queue< pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;
// 이미 방문했는지 기록
bool visited[Max];

int BFS() {

	pq.push({ 0, n });
	visited[n] = true;

	while (!pq.empty()) {
		int sec = pq.top().first;
		int loc = pq.top().second;
		pq.pop();

		// 만난 경우
		if (loc == k) return sec;

		// 한계점 설정 필요
		if (loc<k && loc * 2 < Max && !visited[loc * 2]) {
			pq.push({ sec, loc * 2 });
			visited[loc * 2] = true;
		}
		if (loc + 1 < Max && !visited[loc + 1]) {
			pq.push({ (sec + 1), loc + 1 });
			visited[loc + 1] = true;
		}
		if (loc - 1 >= 0 && !visited[loc - 1]) {
			pq.push({ (sec + 1), loc - 1 });
			visited[loc - 1] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	
	cout << BFS() << '\n';
	return 0;
}