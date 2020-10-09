#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int size = commands.size();
	for (int a = 0; a < size; a++) {
		int i = commands[a][0];
		int j = commands[a][1];
		int k = commands[a][2] - 1;
		vector<int> vec;
		vec.resize(array.size());
		copy(array.begin() + i - 1, array.begin() + j, vec.begin());
		vec.resize(j-i+1);
		sort(vec.begin(), vec.end());
		answer.push_back(vec[k]);
	}
	return answer;
}

int main() {
	vector<int> array(7);
	vector<vector<int> > commands;
	array = { 1, 5, 2, 6, 3, 7, 4 };
	commands = {
		{2,5,3}, {4,4,1}, {1,7,3}
	};

	solution(array, commands);


	return 0;
}