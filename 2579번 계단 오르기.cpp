#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int Max = 300;
vector<int> v(Max);
int N;
bool One = false;
bool Two = false;
int BFS() {
	queue<int> q;
	q.push(v[1]);
	q.push(v[2]);

	while (!q.empty()) {

	}
}

int main() {
	cin >> N;
	v[0] = 0;
	for (int i = 1; i <= N; i++){
		cin >> v[i];
	}
}