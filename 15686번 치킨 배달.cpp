#include <iostream>
#include <algorithm>
#include <math.h>
#define INF 987654321
using namespace std;

int N, M;
int dist[13][100];

pair<int, int> h[100];
pair<int, int> c[13];
int arr[13];
int hSize = 0, cSize = 0;
int answer = INF;

int dis(int y1, int x1, int y2, int x2) {
	// �Ÿ����
	return abs(y1 - y2) + abs(x1 - x2);
}

int chicDis() {
	// ������ ġŲ�Ÿ� ���ϱ�
	int res = 0;
	for (int i = 0; i < hSize; i++) {
		int m = INF;
		for (int j = 0; j < M; j++) {
			dist[j][i] = dis(h[i].first, h[i].second, c[arr[j]].first, c[arr[j]].second);
			// �� ���� ġŲ�Ÿ� ���ϱ�
			m = min(m, dist[j][i]);
		}
		res += m;
	}
	return res;
}


void dfs(int cnt, int start) {
	// M���� ġŲ�� ���� �����?
	if (cnt == M) {
		/*for (int i = 0; i < M; i++) {
			cout << arr[i];
		}
		cout << '\n';*/
		answer = min(answer, chicDis());
		return;
	}

	for (int i = start; i < cSize; i++) {
		arr[cnt] = i;
		dfs(cnt + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int info; cin >> info;
			if (info == 1) h[hSize++] = { i, j };
			if (info == 2) c[cSize++] = { i, j };
		}
	}

	dfs(0, 0);
	
	
	

	cout << answer << '\n';

	return 0;
}