#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;
int Map[21][21];
bool visited[21];
int s1[21];
int s2[21];
int idx;
int answer = INF;

void solve(int cnt) {
	int res = 0;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			res += Map[s1[i]][s1[j]];
			res -= Map[s2[i]][s2[j]];
		}
	}
	// ���밪�� �ּҰ�?
	answer = min(abs(answer), abs(res));
}

void dfs(int num, int cnt) {
	// S1 ���� N/2���� �ϼ��� ���
	if (cnt == N / 2) {
		for (int i = 0, j = 0, idx2 = 0; i < N; i++) {
			if (i == s1[j]) {
				if (j < cnt - 1)
					j++;
			}
			else {
				s2[idx2++] = i;
			}
			
		}
		// �����
		/*for (int i = 0; i < cnt; i++) {
			cout << s1[i] << " ";
		}
		cout << " S2: ";
		for (int i = 0; i < cnt; i++) {
			cout << s2[i] << " ";
		}
		cout << '\n';*/
		
		// �� ���� ���� ���ϱ�
		solve(cnt);
	}

	for (int i = num+1; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		s1[idx++] = i;
		dfs(i, cnt + 1);
		idx--;
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];

	// �� ������
	visited[0];
	s1[idx++] = 0;
	dfs(0, 1);
	idx--;
	visited[0] = false;
	
	cout << answer << '\n';
	return 0;
}