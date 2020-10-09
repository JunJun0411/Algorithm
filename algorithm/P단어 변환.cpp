#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int nsize, wsize;
bool visited[51];
bool check;


bool checkStr(string a, string b) {
	int n = 0;
	for (int i = 0; i < wsize; i++) 
		if (a[i] != b[i]) n++;
	
	if (n == 1) return true;
	return false;
}

int bfs(string begin, string target, vector<string> words) {
	queue<string> q;
	q.push(begin);
	int cnt = 0;

	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {
			string cur = q.front(); q.pop();
			for (int i = 0; i < nsize; i++) {
				if (visited[i]) continue;
				if (checkStr(cur, words[i])) {
					// ã���� return
					if (words[i] == target) return cnt;
					
					// �湮ǥ�� �� queue�� push
					visited[i] = true;
					q.push(words[i]);
				}
			}
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	nsize = words.size(); // words ���� ��
	wsize = begin.size(); // �ܾ� ����
	
	// words �� target ���� check
	for (int i = 0; i < nsize; i++) {
		if (target == words[i]) check = true;
	}
	if (!check) return 0;	

	return bfs(begin, target, words);
}

int main() {
	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log" };

	cout << solution(begin, target, words);
	return 0;
}