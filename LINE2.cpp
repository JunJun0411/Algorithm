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
		// ���� ���� ��ȣ
		int cur = order[i];

		// �� �� Ȯ�� ������ answer�� push�ϰ� cnt++ ���� ������ ���� �� �ִ��� Ȯ��
		if (end >= front && ball[front] == cur || ball[end] == cur) {
			answer.push_back(cur);
			if (ball[front] == cur) front++;
			else if (ball[end] == cur) end--;

			// ���� Ȯ��
			for (int j = 0; j < bufsize; j++) {
				cur = buffer[j];
				// ���� �� Ȯ���� ���� �̹� �����ٸ� continue
				if (!visited[cur]) continue;
				// ���ۿ��� ã���� ���� ó������ Ȯ�� ����
				if (ball[front] == cur || ball[end] == cur) {
					answer.push_back(cur);
					visited[cur] = false;
					if (front <= end && ball[front] == cur) front++;
					else if (end >= front && ball[end] == cur) end--;
					j = -1;
				}
			}
		}
		// ������ buffer�� �ִ´�.
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