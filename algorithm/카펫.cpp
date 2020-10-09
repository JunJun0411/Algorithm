#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int num = brown + yellow;
	for (int i = 3; i <= sqrt(num); i++) {
		int j, add;
		if (num % i == 0) {
			j = num / i;
			add = (i + j) * 2 - 4;
			if (brown == add) {
				answer.push_back(j);
				answer.push_back(i);
				break;
			}
		}
	}

	return answer;
}

int main() {
	int b, y;
	cin >> b >> y;
	vector<int> answer = solution(b, y);
	cout << answer[0] <<", "<< answer[1] << '\n';
}