#include <iostream>
#include <deque>
using namespace std;

// �� �� �� ��
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

	// �ش� ��ǥ�� ��ü�� �ִ��� ã�� �Լ�
	bool find(int y, int x) {
		int size = this->body.size();
		// ������ �����Ѵ�.
		for (int i = 0; i < size - 1; i++) 
			if (this->body[i].first == y && this->body[i].second == x)
				return true;
		
		return false;
	}

	// �̵�
	void move(int y, int x) {
		this->body.pop_back();
		this->body.push_front({ y, x });
	}

	// ��� �������
	void meetApple(int y, int x) {
		this->body.push_front({ y, x });
	}

	// ���� �ٶ󺸴� ���� ��ȯ
	int getDir() { return this->dir; }

	// �� �Ӹ� ��ġ ��ȯ
	pair<int, int> getHead() {
		return this->body.front();
	}

	void changeDir(char dir) {
		// ��� 90'
		if (dir == 'D') 
			++this->dir %= 4;
		// �·� 90'
		else {
			this->dir += 3;
			this->dir %= 4;
		}			
	}

	// �����̳� �� �ε��� ���
	void kill() {
		this->dead = true;
	}

	// �׾����� Ȯ��
	bool snakeDead() {
		return this->dead;
	}
	// ������
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
	
	// time ��ŭ ����
	for (int i = 0; i < time; i++) {
		cnt++;
		pair <int, int> head = snake.getHead();
		int ny = head.first + dy[dir];
		int nx = head.second + dx[dir];

		// ���� ����ų� ��ü�� ������ ��� return
		if (ny < 1 || ny > N || nx < 1 || nx > N || snake.find(ny, nx)) {
			snake.kill();
			return cnt;
		}
		
		// ����� ����ģ ���
		if (Map[ny][nx] == 1) {
			snake.meetApple(ny, nx);
			Map[ny][nx] = 0;
		}
		// �̵�
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
		Map[y][x] = 1; // ���
	}
	
	cin >> L;
	int lastTime = 0; // ������ �ð� ���
	int time; // ȸ�� ���� ������ �ð�
	for (int i = 0; i < L; i++) {
		char c;
		cin >> time >> c;
		// �׾����� continue
		if (snake.snakeDead()) continue;
		int moveTime = time - lastTime; // ���������ϴ� �ð�
		lastTime = time;

		answer += solution(moveTime);

		// ���� ��ȯ
		snake.changeDir(c);
	}
	cout <<  (snake.snakeDead() ? "dead" : "live") << '\n';

	// ��� ������ȯ �Ŀ��� ������ �� �ִ� ���
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