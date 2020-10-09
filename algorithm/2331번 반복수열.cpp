#include <iostream>
#include <vector>
#include <cmath>
#define Max 1000000
using namespace std;

bool visited[Max];
vector<int> vec;

// ���ڸ� p �����ؼ� ���� �� ��ȯ
int detach(int n, int p) {
	int sum = 0;
	do {
		sum += pow(n % 10, p);
		n /= 10;
	} while (n);
	return sum;
}

// �ݺ����� ���ۼ��� ã�� �Լ�
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

	// �ݺ������� �����ϴ� ���� ã��
	int roopStart = BFS(A, P);

	// �ݺ������� ���� count
	int count;
	// �ݺ����� ���ۼ��ڿ� �ٸ� ���ڰ��� count
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == roopStart) {
			count = i;
			break;
		}
	}

	cout << count << '\n';
	return 0;
}