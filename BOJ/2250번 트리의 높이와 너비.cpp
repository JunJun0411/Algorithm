#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001
int N, P, L, R;
int a = 1;
struct Node {
	int low; //너비
	int high; //높이
	int left; //왼쪽자식
	int right; //오른쪽자식
	int root; //root를 찾기위한 변수
};
vector<Node> vec(MAX);
int level = 0;
int best = 0, reallevel = 0;

void inOrder(int root) {
	if (root == -1) return;
	inOrder(vec[root].left);
	vec[root].low = a++;
	inOrder(vec[root].right);
}
void BFS(int head) {
	queue<int> q;
	q.push(head);
	while (!q.empty()) {
		level++;
		int size = q.size();
		int min = 12345, max = 0;
		while (size) {
			size--;
			int ABC = q.front(); 
			q.pop();
			vec[ABC].high = level;
			if (min > vec[ABC].low) min = vec[ABC].low;
			if (max < vec[ABC].low) max = vec[ABC].low;
			if (vec[ABC].left != -1) q.push(vec[ABC].left);
			if (vec[ABC].right != -1) q.push(vec[ABC].right);
		}
		if (best < max - min + 1) {
			best = max - min + 1;
			reallevel = level;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P >> L >> R;

		vec[P].root++;
		if(L!=-1) vec[L].root += 2;
		if(R!=-1) vec[R].root += 2;

		vec[P].left = L;
		vec[P].right = R;
	}
	int head;
	for (int i = 1; i <= N; i++) {
		if (vec[i].root == 1) head = i;
	}
	inOrder(head);
	BFS(head);

	cout << reallevel << " " << best << '\n';
	return 0;
}