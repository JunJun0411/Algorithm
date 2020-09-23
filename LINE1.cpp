#include <iostream>
#include <string>
#include <vector>
#define MAX 1000001
using namespace std;

bool visited[MAX];

int solution(vector<vector<int>> boxes) {
	int answer = 0;

	int size = boxes.size();
	for (int i = 0; i < size; i++) {
			if (!visited[boxes[i][0]]) visited[boxes[i][0]] = true;
	}
	
	for (int i = 0; i < size; i++) {
		if (visited[boxes[i][1]]) visited[boxes[i][1]] = false;
	}
	

	for (int i = 0; i < MAX; i++) 
		if (visited[i]) 
			answer++;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> boxes = { {1,2},{2,1},{3,3},{4,5},{5,6},{7,8} };
	cout << solution(boxes);

	return 0;
}