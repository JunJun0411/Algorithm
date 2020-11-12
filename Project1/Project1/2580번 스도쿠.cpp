#include <iostream>
using namespace std;

int sudoku[9][9];
pair<int, int> blank[81];
int blank_Size = 0;

void solution(int cnt) {
	if (cnt == blank_Size) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}

	bool check[10] = { false, };
	int y = blank[cnt].first, x = blank[cnt].second;
	for (int i = 0; i < 9; i++) {
		check[sudoku[y][i]] = true; // 행 확인
		check[sudoku[i][x]] = true; // 열 확인
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			check[sudoku[(y / 3) * 3 + i][(x / 3) * 3 + j]] = true; // 정사각형 확인
		}
	}

	// 가능한 숫자 넣고 재귀
	for (int i = 1; i < 10; i++) {
		if (!check[i]) {
			check[i] = true;
			sudoku[y][x] = i;
			solution(cnt + 1);
			sudoku[y][x] = 0;
			check[i] = false;
		}
	}

	return;
}

int main() {
	for(int i=0; i<9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &sudoku[i][j]);
			if (sudoku[i][j] == 0) {
				blank[blank_Size++] = { i, j };
			}
		}

	solution(0);

	return 0;
}