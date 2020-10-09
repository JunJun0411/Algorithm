#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> m;
	int csize = clothes.size();
	int msize;
	for (int i = 0; i < csize; i++) {
		m[clothes[i][1]]++;
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		answer *= iter->second + 1;
	}
	
	return answer - 1;
}
int main() {
	vector<vector<string> >clothes = { {"y", "hg"},{"b","ew"},{"t", "hg"} };

	cout<< solution(clothes);
	return 0;
}