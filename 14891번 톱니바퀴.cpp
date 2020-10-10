#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int wheel[6][8];
int head[6];
int K;

void turn(int X, int dir) {
	if (X < 1 || X > 4) return;
	// 회전
	if (dir == 1) head[X] += 7;
	else head[X]++;
	head[X] %= 8;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	for (int i = 1; i <= 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = atoi(str.substr(j, 1).c_str());
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		bool check[5] = {false, false, false, false, false};
		int X, dir1, dir2; // X = 1, 2, 3, 4
		cin >> X >> dir1;
		dir2 = dir1;
		// j번 바퀴 j+1번 바퀴 맞닿아 있는 부분이 상극인 경우 check
		for(int j=1; j<=3; j++)
			if (wheel[j][(head[j] + 2) % 8] != wheel[j + 1][(head[j + 1] + 6) % 8]) check[j] = true;
		
		// X번째 톱니 회전
		turn(X, dir1);

		// 우측으로 톱니 회전
		for (int j = X; j < 5; j++) {
			if (!check[j]) break;
			turn(j+1, dir1 = -dir1);
		}

		// 좌측으로 톱니 회전
		for (int j = X-1; j >=0; j--) {
			if (!check[j]) break;
			turn(j, dir2 = -dir2);
		}

		/*
		디버깅용
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cout << wheel[i][(head[i] + j) % 8];
			}
			cout << '\n';
		}
		*/
	}
	for (int i = 0; i < 4; i++) {
		if (wheel[i + 1][head[i + 1]]) {
			answer += pow(2, i);
		}
	}

	cout << answer << '\n';

	return 0;
}