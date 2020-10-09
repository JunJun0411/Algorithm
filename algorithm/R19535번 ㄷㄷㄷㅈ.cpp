#include <iostream> 
#include <vector>
#include <queue>
#define MAX 300001
using namespace std;

int N;
vector<vector<int> > vec(MAX);
bool visited[300001];
int answer = 0;
//vector<int> ex;

void dfs(int k, int idx) {
	if (k == 0) {
		answer++;
		/*for (int i = 0; i < 4; i++) {
			cout << ex[i];
		}
		cout << '\n';*/
	}

	int size = vec[idx].size();
	for (int i = 0; i < size; i++) {
		int X = vec[idx][i];
		if (visited[X] == true) continue;
		visited[X] = true;
//		ex.push_back(X);
		dfs(k - 1, X);
//		ex.pop_back();
		visited[X] = false;
	}
}

int convol(int num) {
	return num * (num - 1)*(num - 2) / 6;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> gg(MAX);
	int gans = 0;
	cin >> N;

	for (int i = 1; i < N; i++) {
		int x, y; cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
		gg[x]++;
		gg[y]++;
	}

	for (int i = 1; i <= N; i++) {
		if (gg[i] < 3) continue;
		gans += convol(gg[i]);
	}
	//DFS방법
//	for (int i = 1; i <= N; i++) {
//		if (vec[i].empty()) continue;
//		visited[i] = true;
////		ex.push_back(i);
//		dfs(3, i);
////		ex.pop_back();
//		visited[i] = false;
//	}
//	answer /= 2;

//	cout << "an: " << answer << " gan: " << gans << '\n';

	// BFS??


	// 출력
	if (gans == 0) cout << "D" << '\n';
	else if (((answer / gans) == 3) && (answer % gans == 0)) cout << "DUDUDUNGA" << '\n';
	else if ((answer / gans) >= 3) cout << "D" << '\n';
	else cout << "G" << '\n';

	return 0;
}