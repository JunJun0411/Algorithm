#include <iostream>
#include <queue>
using namespace std;

int M, N, H, cnt;

int tomato[102][102][102];
bool visited[102][102][102];
int idx[6][3] = { {1,0,0}, {-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

struct xyz
{
	int x, y, z;
};
queue<xyz> q;

int BFS() {
	if (cnt==0) return 0;

	int day = 1;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			xyz loc = q.front();
			q.pop();
			int x = loc.x, y = loc.y, z = loc.z;

			if(visited[x][y][z]) continue;
			else visited[x][y][z] = true;

			for (int i = 0; i < 6; i++) {
				int xNext = x + idx[i][0];
				int yNext = y + idx[i][1];
				int zNext = z + idx[i][2];

				if (xNext < 0 || xNext >= H)
					continue;
				if (yNext < 0 || yNext >= N)
					continue;
				if (zNext < 0 || zNext >= M)
					continue;
				if (tomato[xNext][yNext][zNext] == -1)
					continue;
				if (tomato[xNext][yNext][zNext] == 0) {
					tomato[xNext][yNext][zNext] = 1;
					q.push({ xNext, yNext, zNext });
					cnt--;
				}
				if (cnt == 0) return day;
			}
		}
		day++;
	}
	return -1;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 0) cnt++;
				if (tomato[i][j][k] == 1) q.push({ i,j,k });
			}
		}
	}
	cout << BFS() << '\n';
	return 0;
}