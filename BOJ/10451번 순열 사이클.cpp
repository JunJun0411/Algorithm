#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int Max = 1001;
vector<int> graph[Max];
bool visited[Max]; //�湮 �ߴ��� Ȯ��
int N; //������ ����
int n = 0;
void DFS(int idx) {
	if (visited[idx] == true) { n++; return; }
	else {
			visited[idx] = true;
			DFS(graph[idx][0]);
	}
	
}
int main() {
	int T; //�׽�Ʈ ���̽� ����
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			int x;  cin >> x;
			graph[i].push_back(x);
		}
		for (int i = 1; i <= N; i++) {
			if (visited[i] == false)
				DFS(i);
		}
		cout << n <<'\n';
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= N; i++) graph[i].clear();
		n = 0;
	}
}