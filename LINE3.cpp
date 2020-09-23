#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int MIN;
int N;

int po(int n) {
	/* n이 몇자리 수 인지 구해주는 함수 */
	if (n == 0) return 1;
	int cnt = 0;
	while (n) {
		cnt++;
		n /= 10;
	}
	return cnt;
}

void dfs(int n, int cnt, int size) {
	// 기저 사례: n이 1자릿 수 일때
	if (size == 1) {
		// 최소 카운트라면 저장
		if (MIN >= cnt) {
			MIN = cnt;
			N = n;
		}
		return;
	}

	// n을 잘라서 재귀
	for (int i = 1; i < size; i++) {
		int a = pow(10, i);
		int left = n / a;
		int right = n % a;
		// right 앞에 0이 나오면
		if (po(left) + po(right) != size) continue;
		dfs(left + right, cnt + 1, po(left + right));
	}
}

vector<int> solution(int n) {
	vector<int> answer;
	// 최소값 찾기
	MIN = po(n);

	dfs(n, 0, MIN);

	answer.push_back(MIN);
	answer.push_back(N);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	vector<int> a = solution(N);
	for (int i = 0; i < 2; i++) {
		cout << a[i] << " ";
	}
	return 0;
}