#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct Game
{
	int Num;
	int strike;
	int ball;
};
vector<Game> vec;
bool canNum[1000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num, s, b; cin >> N;
	Game g;
	for (int i = 0; i < N; i++) {
		cin >> num >> s >> b;
		g.Num = num;
		g.strike = s;
		g.ball = b;
		vec.push_back(g);
	}
	memset(canNum, true, sizeof(canNum));
	for (int i = 123; i < 1000; i++) {
		string A = to_string(i);
		if (A[0] == A[1] || A[0] == A[2] || A[1] == A[2]) canNum[i] = false;
		if (!(A[0] - '0') || !(A[1] - '0') || !(A[2] - '0')) canNum[i] = false;
	}

	for (int i = 0; i < vec.size(); i++) {
		int Num = vec[i].Num;
		int Strike = vec[i].strike;
		int Ball = vec[i].ball;
		string SNum = to_string(Num);
		for (int j = 123; j < 1000; j++) {
			int testS = 0;
			int testB = 0;
			string testN = to_string(j);
			if(canNum[j]){
				for (int p = 0; p < 3; p++) { //vec
					for (int q = 0; q < 3; q++) { //test
						if (p == q && SNum[p] == testN[q]) testS++;
						if (p != q && SNum[p] == testN[q]) testB++;
					}
				}
			}
			if (Strike != testS || Ball != testB) canNum[j] = false;
		}
	}
	int count = 0;
	for (int i = 123; i < 1000; i++) {
		if (canNum[i]) count++;
	}
	printf("%d\n", count);

	return 0;
}