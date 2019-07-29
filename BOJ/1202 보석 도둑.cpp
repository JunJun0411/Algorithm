#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 300000;
int N, K;
int bag[MAX];
pair<int, int> jew[MAX];

int main() {
	cin >> N >> K; //보석 수 , 가방 수
	for (int i = 0; i < N; i++) {
		cin >> jew[i].first >> jew[i].second;
	}	
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}
	sort(jew, jew + N);
	sort(bag, bag + K);
	
	long long sum = 0;
	int j=0;
	priority_queue<int> pq;
	for (int i = 0; i < K; i++) {
	
		for (; bag[i] >= jew[j].first && j < N; j++) {
			pq.push(jew[j].second);
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum << '\n';
}