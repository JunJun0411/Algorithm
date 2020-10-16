#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int room[21][21];
int answer = 987654321;

void split(int y, int x, int d1, int d2) {
	int sum[5] = { 0, };
	int visited[21][21] = { false, };
	int idx = 0;
	if (d1 > d2) {
		idx = 0;
		for (int i = y; i >= y - d1 + d2; i--) {
			for (int j = x + idx; j <= x + (2 * d2) +idx; j++) {
				sum[4] += room[i][j];
				visited[i][j] = 5;
			}
			idx++;
		}

		int gap = d1 - d2;
		idx = 0;
		for (int i = y - d1; i < y - gap ; i++) {
			for (int j = x + d1 - idx; j < x + d1 + 1 + idx; j++) {
				sum[4] += room[i][j];
				visited[i][j] = 5;
			}
			idx++;
		}

		idx = 0;
		for (int i = y + d2; i > y; i--) {
			for (int j = x + d2 - idx; j < x + d2 + 1 + idx; j++) {
				sum[4] += room[i][j];
				visited[i][j] = 5;
			}
			idx++;
		}
	}
	else {
		for (int i = y; i <= y + d2 - d1; i++) {
			for (int j = x + i - y; j <= x + (2 * d1) + i - y; j++) {
				sum[4] += room[i][j];
				visited[i][j] = 5;
			}
		}

		idx = 0;
		for (int i = y - d1; i < y; i++) {
			for (int j = x + d1 - idx; j < x + d1 + 1 + idx; j++) {
				sum[4] += room[i][j];
				visited[i][j] = 5;
			}
			idx++;
		}

		idx = 0;
		int gap = d2 - d1;
		for (int i = y + d2; i > y + gap; i--) {
			for (int j = x + d2 - idx; j < x + d2 + 1 + idx; j++) {
				sum[4] += room[i][j];
				visited[i][j] = 5;
			}
			idx++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) {
				continue;
			}
			if (i < y && j <= x + d1) {
				visited[i][j] = 1;
				sum[0] += room[i][j];
			}
			else if (d1 >= d2 && i <= y - d1 + 1 && j > x + d1) {
				visited[i][j] = 2;
				sum[1] += room[i][j];
			}
			else if (i <= y - d1 + d2 && j > x + d1) {
				visited[i][j] = 2;
				sum[1] += room[i][j];
			}
			else if (i >= y && j < x + d2) {
				visited[i][j] = 3;
				sum[2] += room[i][j];
			}
			else {
				visited[i][j] = 4;
				sum[3] += room[i][j];
			}
		}
	}

	sort(sum, sum + 5);
	answer = min(answer, sum[4] - sum[0]);

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << room[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < 5; i ++) {
		cout << "sum" << i << ": " << sum[i] << '\n';
	}
	cout <<"sum: "<< sum[4]<< " " << sum[0] <<" "<< sum[4] - sum[0] << '\n';
	cout << '\n';*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> room[i][j];
		}
	}

	for (int y = 1; y < N - 1; y++) {
		for (int x = 0; x < N - 2; x++) {
			for (int d1 = 1; d1 <= y && d1 <= N - x - 2; d1++) {
				for (int d2 = 1; d2 < N - x - d1 && d2 < N - y; d2++) {
					//cout << y << ", " << x << ", " << d1 << ", " << d2 <<'\n';
					split(y, x, d1, d2);
					


				}
			}
		}
	}

	cout << answer << '\n';
	return 0;
}