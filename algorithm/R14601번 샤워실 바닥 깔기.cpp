#include <iostream>
#include <vector>
#include <cmath>	
#define MAX 129
using namespace std;

int k, x, y;	
int map[MAX][MAX];	// 1, 1부터 시작
int label = 1;
void solution(int x1, int y1, int k1, int x2, int y2) {
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> x >> y;
	int d = (int)pow(2, k);
	map[x][d - y + 1] = -1;
	solution(1, 1, k, d, d);
}