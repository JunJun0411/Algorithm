#include <iostream>
#include <vector>
#include <cmath>
#define Max 1000000
using namespace std;

bool visited[Max];
vector<int> vec;

// 각자리 p 제곱해서 더한 수 반환
int detach(int n, int p) {
	int sum = 0;
	do {
		sum += pow(n % 10, p);
		n /= 10;
	} while (n);
	return sum;
}

// 반복수열 시작숫자 찾는 함수
int BFS(int a, int p) {
	visited[a] = true;
	vec.push_back(a);

	int next = detach(a, p);

	if (!visited[next]) {
		BFS(next, p);
	}
	else 
		return next;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, P;
	cin >> A >> P;

	// 반복수열을 시작하는 숫자 찾기
	int roopStart = BFS(A, P);

	// 반복수열의 갯수 count
	int count;
	// 반복수열 시작숫자와 다른 숫자갯수 count
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == roopStart) {
			count = i;
			break;
		}
	}

	cout << count << '\n';
	return 0;
}