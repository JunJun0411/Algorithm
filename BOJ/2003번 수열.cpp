#include <iostream>
#include <vector>
using namespace std;

int N,x;
long long M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> x;
		A[i] = x;
	}
	int count = 0;
	int start = -1;
	int end = N-1;
	int mid = -1;
	long long sum = 0;
	while (start < end) {
		
		if (M == sum) {
			count++;
			if (mid < end) {
				++mid;
				sum += A[mid];
				
			}
			else {
				++start;
				sum -= A[start];
			}
		}
		else if (M > sum) {
			if (mid < end) {
				++mid;
				sum += A[mid];
				
			}
			else break;
		}
		else{
			if (mid >= end && M > sum) break;
			++start;
			sum -= A[start];
		}
	}
	cout << count << '\n';
	return 0;
}