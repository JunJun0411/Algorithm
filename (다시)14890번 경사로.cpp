#include <iostream>
#include <vector>
#include <math.h>
#define INF 987654321
using namespace std;


int N, L;
int map[102][102];

int slide2(vector<int> map) {
	int i;
	int c = 1;
	for (i = 0; i < N - 1; i++) {
		if (map[i] == map[i + 1]) c++;
		else if (map[i] + 1 == map[i + 1] && c >= L) c = 1;	// ���� �� ���� ���
		else if (map[i] - 1 == map[i + 1] && c >= 0) c = -L + 1; // ���� �� ���� ���
		else break;
	}
	if (i == N - 1 && c >= 0) return 1;
	return 0;
}

int slide(vector<int> map){
	int answer = 0;
	int idx = 0;
	int tmp = map[idx];
	int cnt = 0;
	for (int j = idx + 1; j < N; j++) {
		// ���� �ٸ��� check
		if (tmp != map[j]) {
			// 2�̻� ���� ���� ��� �Ǵ� ���� ��ġ���̿��ٸ� ������ �� �ִ� �濡�� ����
			if (abs(map[j] - tmp) > 1 || cnt) {
				cout << "1 ";
				answer++;
				break;
			}
			// ����� ������ ���
			if (tmp < map[j]) {
				// ���� �������� check 
				if (j - idx >= L) { // �����ϴٸ�
					idx = j;
					tmp = map[idx];
				}
				else {
					cout << "2 ";
					answer++;
					break;
				}
			}
			// ����� ���� ���
			else {
				cnt++;
				idx = j;
				tmp = map[idx];
				if (cnt == L) {
					cnt = 0;
					// ���� �� �ִٸ� ���
					if (j + 1 < N) {
						// ���� ����� ���� ���
						if (map[j] < map[j + 1]) {
							cout << "4 ";
							answer++;
							break;
						}
						// ���� ��� ���� �������� ���� ����
						else if (map[j] == map[j + 1]) {
							idx = ++j;
							tmp = map[idx];
						}
						// ���� ��� ���� �������� ����
						else {
							idx = j;
							tmp = map[idx];
						}
					}
				}
			}
		}
		else {
			// ���� ��ġ���̶��
			if (cnt) {
				cnt++;
				// ��ġ�Ϸ�
				if (cnt == L) {
					cnt = 0;
					// ���� �� �ִٸ� ���
					if (j + 1 < N) {
						// ���� ����� ���� ���
						if (map[j] < map[j + 1]) {
							cout << "5 ";
							answer++;
							break;
						}
						// ���� ��� ���� �������� ���� ����
						else if (map[j] == map[j + 1]) {
							idx = ++j;
							tmp = map[idx];
						}
						// ���� ��� ���� �������� ����
						else {
							idx = j;
							tmp = map[idx];
						}
					}
				}
				// ���� ��ġ �ȵȰ��
				else {
					// ���� �� ����
					if (j + 1 < N) {
						idx = j;
						tmp = map[idx];
					}
					// ���� �� ����X,,
					else {
						cout << "6 ";
						answer++;
						break;
					}
				}
			}
		}
	}
	if (!answer) cout << "����";
	else cout << "��� ";
	cout << '\n';
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	int size = N + N;
	vector<vector <int> > m(size);
	// ���� �Է�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			m[i].push_back(map[i][j]);
			m[N + j].push_back(map[i][j]);
		}
		// ���� ���� ���� �����.
		map[i][N] = INF;
		map[N][i] = INF;
	}

	int answer = 0;

	for (int i = 0; i < 2 * N; i++) {
		answer += slide2(m[i]);

	}

	//for (int i = 0; i < N; i++) {
	//	int idx = 0;
	//	int tmp = map[i][idx];
	//	int cnt = 0;
	//	for (int j = idx + 1; j < N; j++) {
	//		// ���� �ٸ��� check
	//		if (tmp != map[i][j]) {
	//			// ����� ������ ���
	//			if (tmp < map[i][j]) {
	//				// 2�̻� ���� ���� ��� �Ǵ� ���� ��ġ���̿��ٸ� ������ �� �ִ� �濡�� ����
	//				if (map[i][j] - tmp > 1 || cnt) {
	//					cout << "1 ";
	//					answer--;
	//					break;
	//				}
	//				else {
	//					// ���� �������� check 
	//					if (j - idx >= L) { // �����ϴٸ�
	//						idx = j;
	//						tmp = map[i][idx];
	//					}
	//					else {
	//						cout << "2 ";
	//						answer--;
	//						break;
	//					}
	//				}
	//			}
	//			// ����� ���� ���
	//			else {
	//				// 2�̻� ���� ���� ��� �Ǵ� ���� ��ġ���̿��ٸ� ������ �� �ִ� �濡�� ����
	//				if (tmp - map[i][j] > 1 || cnt) {
	//					cout << "3 ";
	//					answer--;
	//					break;
	//				}
	//				else {
	//					cnt++;
	//					idx = j;
	//					tmp = map[i][idx];
	//					if (cnt == L) {
	//						cnt = 0;
	//						// ���� �� �ִٸ� ���
	//						if (j + 1 < N) {
	//							// ���� ����� ���� ���
	//							if (map[i][j] < map[i][j + 1]) {
	//								cout << "4 ";
	//								answer--;
	//								break;
	//							}
	//							// ���� ��� ���� �������� ���� ����
	//							else if (map[i][j] == map[i][j + 1]) {
	//								idx = ++j;
	//								tmp = map[i][idx];
	//							}
	//							// ���� ��� ���� �������� ����
	//							else {
	//								idx = j;
	//								tmp = map[i][idx];
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//		else {
	//			// ���� ��ġ���̶��
	//			if (cnt) {
	//				cnt++;
	//				// ��ġ�Ϸ�
	//				if (cnt == L) {
	//					cnt = 0;
	//					// ���� �� �ִٸ� ���
	//					if (j + 1 < N) {
	//						// ���� ����� ���� ���
	//						if (map[i][j] < map[i][j + 1]) {
	//							cout << "5 ";
	//							answer--;
	//							break;
	//						}
	//						// ���� ��� ���� �������� ���� ����
	//						else if (map[i][j] == map[i][j + 1]) {
	//							idx = ++j;
	//							tmp = map[i][idx];
	//							continue;
	//						}
	//						// ���� ��� ���� �������� ����
	//						else {
	//							idx = j;
	//							tmp = map[i][idx];
	//							continue;
	//						}
	//					}
	//				}
	//				// ���� ��ġ �ȵȰ��
	//				else {
	//					// ���� �� ����
	//					if (j + 1 < N) {
	//						idx = j;
	//						tmp = map[i][idx];
	//					}
	//					// ���� �� ����X,,
	//					else {
	//						cout << "6 ";
	//						answer--;
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	cout << '\n';
	//}
	//for (int i = 0; i < N; i++) {
	//	int idx = 0;
	//	int tmp = map[idx][i];
	//	int cnt = 0;
	//	for (int j = idx + 1; j < N; j++) {
	//		// ���� �ٸ��� check
	//		if (tmp != map[j][i]) {
	//			// ����� ������ ���
	//			if (tmp < map[j][i]) {
	//				// 2�̻� ���� ���� ��� �Ǵ� ���� ��ġ���̿��ٸ� ������ �� �ִ� �濡�� ����
	//				if (map[j][i] - tmp > 1 || cnt) {
	//					cout << "7 ";
	//					answer--;
	//					break;
	//				}
	//				else {
	//					// ���� �������� check 
	//					if (j - idx >= L) { // �����ϴٸ�
	//						idx = j;
	//						tmp = map[idx][i];
	//					}
	//					else {
	//						cout << "8 ";
	//						answer--;
	//						break;
	//					}
	//				}
	//			}
	//			// ����� ���� ���
	//			else {
	//				// 2�̻� ���� ���� ��� �Ǵ� ���� ��ġ���̿��ٸ� ������ �� �ִ� �濡�� ����
	//				if (tmp - map[j][i] > 1 || cnt) {
	//					cout << "9 ";
	//					answer--;
	//					break;
	//				}
	//				else {
	//					cnt++;
	//					idx = j;
	//					tmp = map[idx][i];
	//					if (cnt == L) {
	//						cnt = 0;
	//						// ���� �� �ִٸ� ���
	//						if (j + 1 < N) {
	//							// ���� ����� ���� ���
	//							if (map[j][i] < map[j + 1][i]) {
	//								cout << "10 ";
	//								answer--;
	//								break;
	//							}
	//							// ���� ��� ���� �������� ���� ����
	//							else if (map[j][i] == map[j + 1][i]) {
	//								idx = ++j;
	//								tmp = map[idx][i];
	//								continue;
	//							}
	//							// ���� ��� ���� �������� ����
	//							else {
	//								idx = j;
	//								tmp = map[idx][i];
	//								continue;
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//		else {
	//			// ���� ��ġ���̶��
	//			if (cnt) {
	//				cnt++;
	//				// ��ġ�Ϸ�
	//				if (cnt == L) {
	//					cnt = 0;
	//					// ���� �� �ִٸ� ���
	//					if (j + 1 < N) {
	//						// ���� ����� ���� ���
	//						if (map[j][i] < map[j + 1][i]) {
	//							cout << "11 ";
	//							answer--;
	//							break;
	//						}
	//						// ���� ��� ���� �������� ���� ����
	//						else if (map[j][i] == map[j + 1][i]) {
	//							idx = ++j;
	//							tmp = map[idx][i];
	//							continue;
	//						}
	//						// ���� ��� ���� �������� ����
	//						else {
	//							idx = j;
	//							tmp = map[idx][i];
	//							continue;
	//						}
	//					}
	//				}
	//				// ���� ��ġ �ȵȰ��
	//				else {
	//					// ���� �� ����
	//					if (j + 1 < N) {
	//						idx = j;
	//						tmp = map[idx][i];
	//					}
	//					// ���� �� ����X,,
	//					else {
	//						cout << "12 ";
	//						answer--;
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	cout << '\n';
	//}

	cout << answer << '\n';

	return 0;
}

/*
8 3
1 2 2 2 2 2 2 1
1 2 2 2 3 3 3 4
1 1 1 2 2 2 3 3
1 1 1 1 2 2 2 3
2 1 1 1 1 1 1 2
2 1 1 1 1 1 2 2
2 2 1 1 1 1 1 2
3 2 2 2 2 2 2 3


*/