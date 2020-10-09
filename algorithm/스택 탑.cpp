#include <iostream>
#include <vector>
#include <utility>
using namespace std;


vector<int> solution(vector<int> heights) {
	vector<int> answer;
	vector<pair<int, int> >stack;

	int size = heights.size();
	
	int x, y;
	answer.resize(size);
	// 스택에 Max 크기 탑이 있다고 가정
	stack.push_back({ 101 , 0 });
	// size만큼 진행
	for (int i = 1; i <= size; i++) {
		int cur = heights[i - 1];
		x = stack.back().first;

		// 뒤 탑이 앞 탑보다 큰 경우
		while (cur >= x) {
			stack.pop_back();
			x = stack.back().first;
		}
		y = stack.back().second;

		answer[i - 1] = y;
		stack.push_back({ cur, i });	
	}


	return answer;
}


int main() {
	vector<int> heights;
	vector<int> answer;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		heights.push_back(a);
	}
	
	answer = solution(heights);
	
	int size = answer.size();
	for (int i = 0; i < size; i++) {
		cout << answer[i];
	}

	return 0;
}