#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 100001;

int N, K;
int x1, y1; // 첫 개구리 위치
string way;
bool odd;

struct plant{
	plant(int x1, int y1)  {
		x = x1;
		y = y1;
		sum = x1 + y1;
		visited = false;
	}
	int sum;
	int x, y;
	bool visited;
};
bool cmp(const plant &p1, const plant &p2) {
	return (p1.sum > p2.sum);
}
plant P[MAXN];
plant frag;
int main() {
	cin >> N >> K;
	cin >> way;
	cin >> x1 >> y1;
	if ((x1 + y1) % 2) odd = true;
	frag.x = x1; frag.y = y1; frag.sum = x1 + y1;
	P[0] = frag;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		if ((X + Y) % 2 == odd) {
			struct plant p(X, Y);
			P[cnt++] = p;
		}
	}
	sort(P, P + cnt - 1, cmp);


	return 0;
}