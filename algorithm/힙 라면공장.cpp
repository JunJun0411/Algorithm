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
		// 재고로 견딜 수 있는 배송 날의 받을 수 있는 공급량을 큰 순서대로 Q에 넣는다.
		for (; j < size; j++) {
			if (dates[j] > stock) break;
			Q.push({ supplies[j], dates[j] });
		}
		// 가장 큰 물량을 재고에 합한다.
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