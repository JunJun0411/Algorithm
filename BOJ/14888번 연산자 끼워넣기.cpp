#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Max = 12;
int N;	
int arr[Max];	// 수열 N개
int ps[Max];	// 연산자 N-1개
vector<int> vec;
bool visited[Max];
int MI = 987654321;
int MA = -987654321;

int play(int x, int type, int number) {
	switch (type)
	{
	case 0:
		return x + arr[number + 1];
	case 1:
		return x - arr[number + 1];
	case 2:
		return x * arr[number + 1];
	case 3:
		return x / arr[number + 1];
	}
}

void DFS(int cnt) {
	// 연산자 모두 사용한 경우
	if (vec.size() == N-1) {
		int result = arr[0];
		for (int i = 0; i < vec.size(); i ++ ) {
			result = play(result, vec[i], i);
		}
		MA = max(result, MA);
		MI = min(result, MI);
		return;
	}
	

	for (int i = 0; i < N - 1; i++) {
		if (!visited[i]) {
			visited[i] = true;
			vec.push_back(ps[i]);
			DFS(i + 1);
			vec.pop_back();
			visited[i] = false;
		}
	}
}


void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int n;
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> n;
		for (int j = sum; j < sum + n; j++)
			ps[j] = i;
		sum += n;
	}
}

void Solution() {
	DFS(0);
	cout << MA << '\n';
	cout << MI << '\n';
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}