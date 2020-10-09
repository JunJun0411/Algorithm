#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int parent[100001];
struct chain
{
	int cost, h1, h2;
};
chain map[10000001];

int getparent(int num) {
	while (parent[num] != num) 
		num = parent[num];

	return num;
}

int solution() {
	int answer = 0;
	int ma = 0;
	for (int i = 0; i < M; i++) {
		int a = getparent(map[i].h1), b = getparent(map[i].h2);
		// 부모가 다르다면 합병
		if (a != b) {
			if (a < b) parent[b] = a;
			else parent[a] = b;
			answer += map[i].cost;
			ma = max(ma, map[i].cost);
		}
	}
	return answer - ma;
}

bool cmp(const chain &p1, const chain &p2) {
	return p1.cost < p2.cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)	parent[i] = i;
	
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		map[i] = { z, x, y };
	}
	sort(map, map+M, cmp);
	
	cout << solution();

	return 0;
}