#include <iostream>
using namespace std;

long long tile[10001];

int main() {
	int K, N; cin >> K >> N;
	long long max = 0; // 가장 긴 타일의 길이
	for (int i = 0; i < K; i++){
		cin >> tile[i];
		if (max < tile[i]) max = tile[i];
	}
	
	long long left = 1;
	long long right = max; 
	long long result = 0;
	long long mid;
	while (left<=right)	{
		int sum = 0;
		mid = (left + right) / 2;

		for (int j = 0; j < K; j++)  sum += tile[j] / mid;
		
		if (sum >= N) {
			left = mid + 1;
			if (result < mid) result = mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result << '\n';
	return 0;
}