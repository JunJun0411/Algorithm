#include <iostream>
#include <deque>
using namespace std;

// 동 남 서 북
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
const int MAX_MAP_SIZE = 101;

class Snake {
public:
	int dir;
	bool dead;
	deque<pair<int, int> > body;

	// init
	Snake() {};
	Snake(int dir, int y, int x, bool dead = false) :dir(dir), dead(dead) {
		this->body.push_front({ y, x });
	}

	// 해당 좌표에 몸체가 있는지 찾는 함수
	bool find(int y, int x) {
		int size = this->body.size();
		// 꼬리는 제외한다.
		for (int i = 0; i < size - 1; i++) 
			if (this->body[i].first == y && this->body[i].second == x)
				return true;
		
		return false;
	}

	// 이동
	void move(int y, int x) {
		this->body.pop_back();
		this->body.push_front({ y, x });
	}

	// 사과 만난경우
	void meetApple(int y, int x) {
		this->body.push_front({ y, x });
	}

	// 현재 바라보는 방향 반환
	int getDir() { return this->dir; }

	// 뱀 머리 위치 반환
	pair<int, int> getHead() {
		return this->body.front();
	}

	void changeDir(char dir) {
		// 우로 90'
		if (dir == 'D') 
			++this->dir %= 4;
		// 좌로 90'
		else {
			this->dir += 3;
			this->dir %= 4;
		}			
	}

	// 몸통이나 벽 부딪힌 경우
	void kill() {
		this->dead = true;
	}

	// 죽었는지 확인
	bool snakeDead() {
		return this->dead;
	}
	// 디버깅용
	void info() {
		int size = this->body.size();
		cout << "bodySize: " << size << '\n';
		for (int i = 0; i < size; i++)
			cout << this->body[i].first << ", " << this->body[i].second << " - ";
		cout << '\n';
		cout << this->dir << '\n';
	}
};

int N, K, L;
Snake snake(0, 1, 1);
int Map[MAX_MAP_SIZE][MAX_MAP_SIZE];

int solution(int time) {
	int cnt = 0;
	int dir = snake.getDir();
	
	// time 만큼 진행
	for (int i = 0; i < time; i++) {
		cnt++;
		pair <int, int> head = snake.getHead();
		int ny = head.first + dy[dir];
		int nx = head.second + dx[dir];

		// 범위 벗어나거나 몸체를 만나는 경우 return
		if (ny < 1 || ny > N || nx < 1 || nx > N || snake.find(ny, nx)) {
			snake.kill();
			return cnt;
		}
		
		// 사과를 마주친 경우
		if (Map[ny][nx] == 1) {
			snake.meetApple(ny, nx);
			Map[ny][nx] = 0;
		}
		// 이동
		else {
			snake.move(ny, nx);
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		Map[y][x] = 1; // 사과
	}
	
	cin >> L;
	int lastTime = 0; // 움직인 시간 기록
	int time; // 회전 까지 움직인 시간
	for (int i = 0; i < L; i++) {
		char c;
		cin >> time >> c;
		// 죽었으면 continue
		if (snake.snakeDead()) continue;
		int moveTime = time - lastTime; // 움직여야하는 시간
		lastTime = time;

		answer += solution(moveTime);

		// 방향 전환
		snake.changeDir(c);
	}
	cout <<  (snake.snakeDead() ? "dead" : "live") << '\n';

	// 모든 방향전환 후에도 움직일 수 있는 경우
	if (!snake.snakeDead()) answer += solution(N);

	cout << answer << '\n';
    snake.info();
	return 0;
}

/*
testCase

100
3
1 2
2 2
2 1
1
1 

6
4
1 2
1 3
1 4
1 5
5
0 D
5 D
6 D
10 D
11 D


6
19
1 2
1 3
1 4
1 5
1 6
2 6
3 6
4 6
5 6
6 6
6 5
6 4
6 3
6 2
6 1
5 1
4 1
3 1
2 1
3
5 D
10 D
14 D

10
8
2 7
1 4
1 5
1 3
1 2
1 6
1 7
8 8
4
8 D
10 D
12 D
14 D


10
7
2 7
1 4
1 5
1 3
1 2
1 6
1 7
14
5 D
6 D
7 D
11 L
12 L
17 D
18 D
23 L
24 L
29 D
30 D
34 L
37 D
39 D
*/