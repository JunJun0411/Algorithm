#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;


vector<int> Solution(vector<int> answers) {
	vector<int> answer;
	
	int size = answers.size();
	int a = 0, b = 0, c = 0;
	vector<int> a1 = { 1,2,3,4,5 };
	vector<int> a2 = { 2,1,2,3,2,4,2,5 };
	vector<int> a3 = { 3,3,1,1,2,2,4,4,5,5 };
	for (int i = 0; i < size; i++) {
		if (answers[i] == a1[i % 5])
			a++;
		
		if (answers[i] == a2[i % 8])
			b++;
		
		if (answers[i] == a3[i % 10])
			c++;
	}
	int M = max(max(a, b), c);
	if (a == M) answer.push_back(1);
	if (b == M) answer.push_back(2);
	if (c == M) answer.push_back(3);

	return answer;
}

void Solve() {
	cin >> N;
	vector<int> answers(N);

	for (int i = 0; i < N; i++) {
		cin >> answers[i];
	}
	
	vector<int> aa = Solution(answers);
	for (int i = 0; i < aa.size(); i++) {
		cout << aa[i] << " ";
	}

}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);

	Solve();

	return 0;
}