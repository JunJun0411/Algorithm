#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1000001
using namespace std;

int N;
int arr1[MAXN];

void mysort(int *arr, int start, int end) {
	if (start >= end) {
		return;
	}
	int tmp;
	int pivot = start;
	int i = start + 1;
	int j = end;

	while (i <= j) {
		while (i <= end && arr[pivot] >= arr[i]) { i++; }
		while (j > start && arr[pivot] <= arr[j]) { j--; }
	
		if (i <= j) {
			// i, j ��ġ�� �ٲ�
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	// i, j ��ġ�� �ٲ�� pivot�� j �ٲ�
	tmp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = tmp;

	mysort(arr, start, j - 1);
	mysort(arr, j + 1, end);
}

void Input() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr1[i];
	}
}

void Solution() {
	mysort(arr1, 0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << arr1[i] << '\n';
	}
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);

	Solve();

	return 0;
}