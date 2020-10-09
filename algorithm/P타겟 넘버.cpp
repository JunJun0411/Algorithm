#include <iostream>	
#include <string>
#include <vector>
using namespace std;

int answer = 0;
int nsize;
void dfs(int idx, int sum, vector<int> numbers, int target) {
	if (idx == nsize) {
		if (sum == target) {
			answer++;
		}
		return;
	}
	dfs(idx + 1, sum + numbers[idx], numbers, target);
	dfs(idx + 1, sum - numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
	nsize = numbers.size();
	dfs(0, 0, numbers, target);
	return answer;
}

int main() {
	vector<int> numbers = { 1,1,1,1,1 };
	
	cout << solution(numbers, 3);
	
	return 0;
}