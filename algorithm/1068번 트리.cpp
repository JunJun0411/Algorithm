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
	
	// �ܸ� ��� ī��Ʈ
	if (vec[root].empty()) {
		leap++;
		// ������ ��尡 ���� ���Ḯ��Ʈ�߿� �ִٸ�
		if (root == X) {
			if(!check)
				leap--;
		}
	}

	// �湮 ǥ��
	visited[root] = true;
	int size = vec[root].size();
	// ���� ����� ����� Ʈ���� �ܸ���带 ������ leap ������ �����ϹǷ�
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
		// ���Ḯ��Ʈ ����
		if (parent != -1)
			vec[parent].push_back(i);
		// parent�� -1�� ���� ��Ʈ
		else rootidx[j++] = i;
	}
	// ���� ����� ���Ḯ��Ʈ ����
	cin >> X;
	vec[X].clear();

	// root���� DFS
	for (int i = 0; i < j; i++) {
		DFS(rootidx[i]);
		cout << leap << '\n';
	}

	return 0;
}