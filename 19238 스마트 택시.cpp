#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

int N, M, oil;
vector<int>road[21][21];
int taxi[2];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int fromTo(int num) {
	//num == 500이면 승객을 태우러, num < 0 이면 승객을 싣고 목적지로 향하는 택시
	if (road[taxi[0]][taxi[1]].back() > 0 && road[taxi[0]][taxi[1]].back() != INF && num == 500) {// 택시위치에 승객이 있다면 바로 태운다. 
		int c = road[taxi[0]][taxi[1]].back();
		road[taxi[0]][taxi[1]].pop_back();
		if (!road[taxi[0]][taxi[1]].size()) road[taxi[0]][taxi[1]].push_back(0);
		return c;
	}
	
	vector<pair<int, int> >vec;
	queue<pair<int, int> >q;
	bool visited[21][21] = { false, };
	q.push({ taxi[0], taxi[1] });
	visited[taxi[0]][taxi[1]] = true;
	int vecSize;
	int step = 0;
	while (!q.empty()) {
		if (--oil < 0) return oil = -1;
		step++;
		int size = q.size();
		while (size--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int i=0; i<4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || road[ny][nx].back() == INF) continue;
				if (road[ny][nx].back() > 0 && num == 500) // 승객 태운 경우
					vec.push_back({ ny, nx });

				if (num < 0 && road[ny][nx].front() != 0) {
					int rSize = road[ny][nx].size();
					for (int j = 0; j < rSize; j++) {
						if (road[ny][nx][j] == num) { // 도착지 도착한 경우 road[ny][nx][j]를 빼낸다.
							vec.push_back({ ny, nx });
							for (int k = j + 1; k < rSize; k++) {
								road[ny][nx][k - 1] = road[ny][nx][k];
							}
							road[ny][nx].pop_back();
							if (!road[ny][nx].size()) 
								road[ny][nx].push_back(0);
							break;
						}
					}
				}
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
		// 최단거리 손님들, 목적지를 찾았다면
		if (vecSize = vec.size()) break;
	}
	if (!vecSize) return oil = -1;

	//cout << "step: "<<step << '\n';
	// 승객들 태운거라면
	if (num == 500)
		sort(vec.begin(), vec.end(), cmp);
	else
		oil += step * 2;

	// 현재 택시의 좌표
	int y = vec[0].first, x = vec[0].second;
	int client = road[y][x].back();
	taxi[0] = y, taxi[1] = x;
	if (num == 500) {
		road[y][x].pop_back();
		if (!road[y][x].size())
			road[y][x].push_back(0);
	}
	//cout << "client: " << client << '\n';
	return client;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> oil;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;	cin >> x;
			if (x == 1)
				road[i][j].push_back(INF);
			else
				road[i][j].push_back(x);
		}
	}
	
	cin >> taxi[0] >> taxi[1];
	taxi[0]--;
	taxi[1]--;

	// 손님 출발 목적지 정보
	for (int i = 1; i <= M; i++) {
		int fromY, fromX, toY, toX;
		cin >> fromY >> fromX >> toY >> toX;
		if(road[fromY - 1][fromX - 1].back() == 0)
			road[fromY - 1][fromX - 1].pop_back();
		road[fromY - 1][fromX - 1].push_back(i);
		if (road[toY - 1][toX - 1].back() == 0)
		road[toY - 1][toX - 1].pop_back();
		road[toY - 1][toX - 1].push_back(-i);
	}

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (road[i][j].size() > 1) 
				sort(road[i][j].begin(), road[i][j].end(), less<int>());

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (road[i][j].back() == INF) cout << "9";
			else
				cout << road[i][j].back();
			cout << " ";
		}
		cout << '\n';
	}*/

	int answer = 0;
	while (M--) {
		//cout << "현재 택시의 좌표1: " << taxi[0] << ", " << taxi[1] << '\n';
		// 승객 태우기
		int client = fromTo(500);

		if (oil == -1) break;
		/*cout << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (road[i][j].back() == INF) cout << "9";
				else
					cout << road[i][j].back();
				cout << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/
		// 목적지까지 데려다주기
		/*cout << "현재 택시의 좌표2: " << taxi[0] << ", " << taxi[1] << '\n';
		cout << "데려다주기" << '\n';*/
		fromTo(-client);
		/*if(fromTo(-client) != 0) 
			cout <<"error"<<'\n';
		cout << "현재 택시의 좌표3: " << taxi[0] << ", " << taxi[1] << '\n';
		cout << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (road[i][j].back() == INF) cout << "9";
				else
					cout << road[i][j].back();
				cout << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/

		if (oil == -1) break;
	}

	cout << oil << '\n';
	return 0;
}
/*
TestCase
6 4 200
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 1 0 0
6 5
2 2 5 6
5 4 1 5
4 2 3 5
1 5 1 1

*/