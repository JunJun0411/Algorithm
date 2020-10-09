#include <iostream>
using namespace std;

const int MAXN = 5001;
bool visited[MAXN];
int N, K;

int main() {
	cin >> N >> K;

	int cnt = K-1;
	int idx = 0;

	int X = N;
	cout << "<";
	while (X--) {
		while (cnt) {
			++idx;
			idx %= N;
			while (visited[idx]) {
				++idx;
				idx %= N;
			}
			cnt--;
		}
		
		visited[idx] = true;
		cout << idx+1;
		if (X) cout << ", ";
		cnt = K;
	}
	cout << ">";

	return 0;
}