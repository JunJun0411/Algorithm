#include <iostream>
#include <algorithm>
using namespace std;

// ºÏ µ¿ ³² ¼­
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
const int numdir[5] = { 4, 2, 4, 4, 1 };

int map[10][10];
int N, M;
int c = 0;
int arr[8];
int answer = 100;

class cctv {
public:
	int num;
	int y, x;
	cctv(){}
	cctv(int num, int y, int x): num(num), y(y), x(x){}
	void insert(int num, int y, int x) {
		this->num = num;
		this->y = y;
		this->x = x;
	}
	int howMany() {
		return numdir[this->num];
	}
};

cctv cc[8];

void draw(int y, int x, int dir) {
	while (map[y + dy[dir]][x + dx[dir]] != 6) {
		y += dy[dir];
		x += dx[dir];
		if (map[y][x] == 0)
			map[y][x] = 7;

	}
}

void drawWay(cctv ct, int num) {
	int y = ct.y;
	int x = ct.x;
	switch (ct.num) {
	case 1:
		draw(y, x, num);
		break;
	case 2:
		draw(y, x, num);
		draw(y, x, (num + 2));
		break;
	case 3:
		draw(y, x, num);
		draw(y, x, (num + 1) % 4);
		break;
	case 4:
		draw(y, x, num);
		draw(y, x, (num + 1) % 4);
		draw(y, x, (num + 2) % 4);
		break;
	case 5:
		for (int i = 0; i < 4; i++)
			draw(y, x, i);
		break;
	}
}

int search() {
	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (map[i][j] == 0) ans++;

	return ans;
}

void dfs(int cnt) {
	if (cnt == c) {
		int ans = search();
		answer = ans <= answer ? ans : answer;
		return;
	}

	int copy_map[10][10];

	for (int i = 1; i <= N ; i++) 
		for (int j = 1; j <= M; j++) 
			copy_map[i][j] = map[i][j];
		
	
	
	for (int i = 0; i < numdir[cc[cnt].num - 1]; i++) {
		drawWay(cc[cnt], i);
		dfs(cnt + 1);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				map[i][j] = copy_map[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= M+1; j++) {
			if (i >= 1 && i <= N && j >= 1 && j <= M) {
				cin >> map[i][j];
				if (map[i][j] > 0 && map[i][j] < 6) {
					cc[c++].insert(map[i][j], i, j);
				}
			}
			else
				map[i][j] = 6;
		}
	}
	dfs(0);
	cout << answer << '\n';
	return 0;
}