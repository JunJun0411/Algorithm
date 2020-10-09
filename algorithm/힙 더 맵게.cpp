#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int first, second;
	priority_queue<int> sco;
	int size = scoville.size();
	for (int i = 0; i < size; i++) {
		sco.push(-scoville[i]);
	}
	while ((first = -sco.top()) < K) {
		sco.pop();
		if (!sco.size()) return -1;
		second = -sco.top();
		sco.pop();
		sco.push(-(first + (second * 2)));
		answer++;
		
	}

	return answer;
}

int main() {
	vector<int> scoville;
	int K; 
	int N; cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		scoville.push_back(a);
	}

	cout << solution(scoville, K);

	return 0;
}