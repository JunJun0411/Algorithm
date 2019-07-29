#include <iostream>
#include <utility>
using namespace std;
const int Max = 1024 * 1024;
int k = 0;
pair<int, int> arr[Max];
void Hanoi(int N, int F, int S, int T) {
	if (N == 0) return;
	Hanoi(N - 1, F, T, S);
	arr[k++] = make_pair(F,T); 
	Hanoi(N - 1, S, F, T);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	Hanoi(N, 1, 2, 3);
	cout << k << '\n';
	for (int i = 0; i < k; i++) {
		cout << arr[i].first<<" "<<arr[i].second << '\n';
	}
	return 0;
}