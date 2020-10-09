#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Tree[1000001];
int main() {

	long long N, M, mid;
	long long max = 0;
	long long result = 0;
	cin >> N >> M; //������ ��, ���ϴ� ������ ����
	
	for (int i = 0; i < N; i++) {
		cin >> Tree[i]; // ���� ����
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
		
		if (M <= sum) { //���ϴ� �������̺��� �ڸ� �������̰� ũ�ų� ���� ���
			if (result < mid) result = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << result << '\n';
}