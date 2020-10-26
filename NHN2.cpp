#include <iostream>
#include <vector>
using namespace std;

int area[101];

void solution(int day, int width, int **blocks) {
	int sum = 0;
	for (int i = 0; i < day; i++) {
		for (int j = 0; j < width; j++) {
			// 작업 영역에 추가
			area[j] += blocks[i][j];
		}

		for (int head = 0, j = 1; j < width; j++) {
			if (area[head] <= area[j]) {
				for (int k = head + 1; k < j; k++) {
					sum += (area[head] - area[k]);
					area[k] = area[head];
				}
				head = j;
			}
		}

		for (int head = width - 1, int j = width - 2; j >= 0; j++) {
			if (area[head] <= area[j]) {
				for (int k = head - 1; k > j; k--) {
					sum += (area[head] - area[k]);
					area[k] = area[head];
				}
				head = j;
			}
		}
	}
	cout << sum << '\n';
}