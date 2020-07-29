#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	int size = baseball.size(); // 4

	for (int i = 123; i <= 987; i++) {
		int x = i / 100;				// 100ÀÚ¸´¼ö
		int y = (i / 10) % 10;			// 10ÀÚ¸´¼ö
		int z = i % 10;					// 1ÀÚ¸´¼ö
		if (x == 0 || y == 0 || z == 0 || (x == y) || (y == z) || (x == z)) continue;

		for (int j = 0; j < size; j++) {
			int a = baseball[j][0];
			int b = a / 100;			// 100ÀÚ¸´¼ö
			int c = (a / 10) % 10;		// 10ÀÚ¸´¼ö
			int d = a % 10;				// 1ÀÚ¸´¼ö
			int strike = 0;
			int ball = 0;
			
			if (b == 0 || c == 0 || d == 0) break;

			// strike
			if (x == b) strike++;
			if (y == c) strike++;
			if (z == d) strike++;
			if (strike != baseball[j][1]) break;
			
			// ball
			if (b == y || b == z) ball++;
			if (c == x || c == z) ball++;
			if (d == x || d == y) ball++;
			if (ball != baseball[j][2]) break;
			
			if (size - 1 == j) answer++;
			
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> baseball = { {123,1,1},{356,1,0},{327,2,0}, {489,0,1} };

	cout << solution(baseball);
}