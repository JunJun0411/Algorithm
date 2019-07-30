#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, parent, X;
int leap = 0;
vector<int> vec[51];
bool visited[51];
int rootidx[51];
int check;
void DFS(int root) {
	
	// 단말 노드 카운트
	if (vec[root].empty()) {
		leap++;
		// 삭제된 노드가 정말 연결리스트중에 있다면
		if (root == X) {
			if(!check)
				leap--;
		}
	}

	// 방문 표시
	visited[root] = true;
	int size = vec[root].size();
	// 단일 노드들로 연결된 트리는 단말노드를 지워도 leap 갯수는 무관하므로
	if (size == 1) check = true;
	else check = false;
	for (int i = 0; i < size; i++) {
		if (!visited[vec[root][i]])
			DFS(vec[root][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int j = 0;
	for (int i = 0; i < N; i++) {
		cin >> parent;
		// 연결리스트 생성
		if (parent != -1)
			vec[parent].push_back(i);
		// parent가 -1인 노드는 루트
		else rootidx[j++] = i;
	}
	// 지울 노드의 연결리스트 삭제
	cin >> X;
	vec[X].clear();

	// root부터 DFS
	for (int i = 0; i < j; i++) {
		DFS(rootidx[i]);
		cout << leap << '\n';
	}

	return 0;
}