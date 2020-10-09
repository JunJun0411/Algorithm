#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10001;
int N;
int arr[MAXN];
int cache[MAXN] = { 0, };

int DP() {
	cache[1] = arr[1];
	cache[2] = arr[1] + arr[2];

	if (N == 1) return cache[1];
	else if (N == 2) return cache[2];
	else {
		for (int i = 3; i <= N; i++) {
			cache[i] = max(cache[i - 1], max(arr[i] + cache[i - 2], arr[i] + arr[i - 1] + cache[i - 3]));
		}
		return cache[N];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> arr[i];
	
	cout << DP() << '\n';

}