#include <iostream>
#include <math.h>
using namespace std;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { 1, 0, -1, 0 };

int N;
int map[101][101];
int dragonCurve[10000];


void draw(int y, int x, int dir, int gen, int num) {
	int size = pow(2, gen);
	map[y][x] = num;
	for (int i = 0; i < size; i++) {
		int ndir = (dir + dragonCurve[i]) % 4;
		y += dy[ndir];
		x += dx[ndir];
		map[y][x] = num;
	}

	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	int size = 1;
	dragonCurve[0] = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < size; j++) 
			dragonCurve[size + size - 1 - j] = (dragonCurve[j] + 1) % 4;
		size *= 2;
	}

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x, y, dir, gen;
		cin >> x >> y >> dir >> gen;
		draw(y, x, dir, gen, i);
	}

	// 네 꼭지점이 모두 드래곤커브의 일부인 것의 개수 확인
	for (int i = 0; i < 100; i++) 
		for (int j = 0; j < 100; j++) 
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				answer++;
		
	cout << answer << '\n';

	return 0;
}