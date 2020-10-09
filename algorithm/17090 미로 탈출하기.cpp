//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//// U R D L
//const int dx[4] = { -1, 0, 1, 0 };
//const int dy[4] = { 0, 1, 0, -1 };
//int cache[501][501];
//char vec[501][501];
//int n, m;
//
//int cha(char a) {
//	switch (a)
//	{
//	case 'U':
//		return 0;
//	case 'R':
//		return 1;
//	case 'D':
//		return 2;
//	case 'L':
//		return 3;
//	}
//}
//
//int DFS(int x, int y) {
//	if (x < 0 || x >= n || y < 0 || y >= m) return 1;
//	if (cache[x][y] != -1) return cache[x][y];
//
//	cache[x][y] = 0;
//
//	int X = cha(vec[x][y]);
//	return cache[x][y] = DFS(x + dx[X], y + dy[X]);
//}
//int solution() {
//	int answer = 0;
//
//	for (int i = 0; i < n; i++) 
//		for (int j = 0; j < m; j++) 
//			answer += DFS(i, j);
//
//	return answer;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	cin >> n >> m;
//	
//	for (int i = 0; i < n; i++) {		
//		for (int j = 0; j < m; j++) {
//			cin >> vec[i][j];
//			cache[i][j] = -1;
//		}
//	}
//	
//	cout << solution() << '\n';
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// U R D L
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int cache[501][501];
char vec[501][501];
int n, m;

int cha(char a) {
	switch (a)
	{
	case 'U':
		return 0;
	case 'R':
		return 1;
	case 'D':
		return 2;
	case 'L':
		return 3;
	}
}

int clea(int x, int y, int num) {
	int ans = 0;
	while (cache[x][y] == 1) {
		if (num == 2) ans++;

		cache[x][y] = num;
		int X = cha(vec[x][y]);
		x = x + dx[X], y = y + dy[X];
		if (x < 0 || x >= n || y <0 || y> m) break;
	}
	return ans;
}

int solution() {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 미확인 지역만 확인
			if (cache[i][j] != 0) continue;
			int x = i, y = j;

			while (1) {
				cache[x][y] = 1;
				int X = cha(vec[x][y]);
				int zx = x + dx[X], zy = y + dy[X];

				// 탈출
				if (zx < 0 || zx >= n || zy < 0 || zy >= m || cache[zx][zy] == 2) {
					answer += clea(i, j, 2);
					break;
				}

				// 꼬리잡기 or 불가한 지역에 빠졌다면
				if (cache[zx][zy] == 1) break;

				// 다음지역이 미확인지역이라면
				if (cache[zx][zy] == 0)
					x = zx, y = zy;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {		
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}
	
	cout << solution() << '\n';

	return 0;
}