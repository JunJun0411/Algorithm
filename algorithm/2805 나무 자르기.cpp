#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Tree[1000001];
int main() {

	long long N, M, mid;
	long long max = 0;
	long long result = 0;
	cin >> N >> M; //나무의 수, 구하는 나무의 길이
	
	for (int i = 0; i < N; i++) {
		cin >> Tree[i]; // 나무 높이
		if (max < Tree[i]) max = Tree[i];
	}
	long long left = 0;
	long long right = max;
	while (left <= right) {
		long long sum = 0;
		mid = (left + right) / 2;

		for (int i = 0; i < N; i++) {
			if (Tree[i] > mid)
				sum += Tree[i] - mid;
		}
		
		if (M <= sum) { //구하는 나무길이보다 자른 나무길이가 크거나 같을 경우
			if (result < mid) result = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << result << '\n';
}