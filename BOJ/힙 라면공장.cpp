#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<pair<int, int> >Q;
	int j=0;
	int size = dates.size();

	while (stock < k) {
		// ���� �ߵ� �� �ִ� ��� ���� ���� �� �ִ� ���޷��� ū ������� Q�� �ִ´�.
		for (; j < size; j++) {
			if (dates[j] > stock) break;
			Q.push({ supplies[j], dates[j] });
		}
		// ���� ū ������ ��� ���Ѵ�.
		stock += Q.top().first;
		Q.pop();
		answer++;
	}
	return answer;
}

int main() {
	int stock, N, k;
	vector<int> dates, supplies;
	cin >> stock >> N;
	for (int i = 0; i < N; i++) {
		int B; cin >> B;
		dates.push_back(B);
	}
	for (int i = 0; i < N; i++) {
		int B; cin >> B;
		supplies.push_back(B);
	}
	cin >> k;

	cout << solution(stock, dates, supplies, k);

	return 0;
}