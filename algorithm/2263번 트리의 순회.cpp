#include <iostream>
using namespace std;
#define MAX 100001

int N, j; int idx = 1, p=0;
int inOrder[MAX];
int postOrder[MAX];
int index[MAX];
bool check;
void change(int i_begin, int i_end, int p_begin, int p_end) {
	if (i_begin > i_end || p_begin > p_end) return;
	int root = postOrder[p_end];
	
	cout << root << " ";

	change(i_begin, index[root]-1, p_begin, p_begin + (index[root]-i_begin)-1);
	change(index[root]+1, i_end, p_begin + (index[root] - i_begin), p_end - 1);
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> inOrder[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> postOrder[i];
	}
	for (int i = 1; i <= N; i++) {
		index[inOrder[i]]=i;
	}
	change(1, N, 1, N);
	cout << '\n';
	return 0;
}