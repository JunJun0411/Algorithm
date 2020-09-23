#include <iostream>
#include <string>
#include <vector>
#define MAX 1000001
using namespace std;

bool visited[MAX];
vector<int> buffer;

vector<int> solution(vector<int> ball, vector<int> order) {
	vector<int> answer;
	int size = ball.size();
	int front = 0, end = size - 1;
	int bufsize = 0;

	for (int i = 0; i < size; i++) {
		// 꺼낼 공의 번호
		int cur = order[i];

		// 앞 뒤 확인 있으면 answer에 push하고 cnt++ 버퍼 뒤져서 꺼낼 거 있는지 확인
		if (end >= front && ball[front] == cur || ball[end] == cur) {
			answer.push_back(cur);
			if (ball[front] == cur) front++;
			else if (ball[end] == cur) end--;

			// 버퍼 확인
			for (int j = 0; j < bufsize; j++) {
				cur = buffer[j];
				// 버퍼 내 확인한 공이 이미 쓰였다면 continue
				if (!visited[cur]) continue;
				// 버퍼에서 찾으면 버퍼 처음부터 확인 시작
				if (ball[front] == cur || ball[end] == cur) {
					answer.push_back(cur);
					visited[cur] = false;
					if (front <= end && ball[front] == cur) front++;
					else if (end >= front && ball[end] == cur) end--;
					j = -1;
				}
			}
		}
		// 없으면 buffer에 넣는다.
		else {
			buffer.push_back(cur);
			bufsize++;
			visited[cur] = true;
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
}