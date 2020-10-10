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
		else if (map[i] + 1 == map[i + 1] && c >= L) c = 1;	// 앞이 더 낮은 경우
		else if (map[i] - 1 == map[i + 1] && c >= 0) c = -L + 1; // 앞이 더 높은 경우
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
		// 높이 다른지 check
		if (tmp != map[j]) {
			// 2이상 차이 나는 경우 또는 경사로 설치중이였다면 지나갈 수 있는 길에서 제외
			if (abs(map[j] - tmp) > 1 || cnt) {
				cout << "1 ";
				answer++;
				break;
			}
			// 언덕이 높아진 경우
			if (tmp < map[j]) {
				// 경사로 가능한지 check 
				if (j - idx >= L) { // 가능하다면
					idx = j;
					tmp = map[idx];
				}
				else {
					cout << "2 ";
					answer++;
					break;
				}
			}
			// 언덕이 낮은 경우
			else {
				cnt++;
				idx = j;
				tmp = map[idx];
				if (cnt == L) {
					cnt = 0;
					// 다음 벽 있다면 고려
					if (j + 1 < N) {
						// 다음 언덕이 높은 경우
						if (map[j] < map[j + 1]) {
							cout << "4 ";
							answer++;
							break;
						}
						// 같은 경우 다음 지점부터 새로 시작
						else if (map[j] == map[j + 1]) {
							idx = ++j;
							tmp = map[idx];
						}
						// 낮은 경우 현재 지점부터 시작
						else {
							idx = j;
							tmp = map[idx];
						}
					}
				}
			}
		}
		else {
			// 경사로 설치중이라면
			if (cnt) {
				cnt++;
				// 설치완료
				if (cnt == L) {
					cnt = 0;
					// 다음 벽 있다면 고려
					if (j + 1 < N) {
						// 다음 언덕이 높은 경우
						if (map[j] < map[j + 1]) {
							cout << "5 ";
							answer++;
							break;
						}
						// 같은 경우 다음 지점부터 새로 시작
						else if (map[j] == map[j + 1]) {
							idx = ++j;
							tmp = map[idx];
						}
						// 낮은 경우 현재 지점부터 시작
						else {
							idx = j;
							tmp = map[idx];
						}
					}
				}
				// 아직 설치 안된경우
				else {
					// 다음 땅 존재
					if (j + 1 < N) {
						idx = j;
						tmp = map[idx];
					}
					// 다음 땅 존재X,,
					else {
						cout << "6 ";
						answer++;
						break;
					}
				}
			}
		}
	}
	if (!answer) cout << "때문";
	else cout << "통과 ";
	cout << '\n';
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	int size = N + N;
	vector<vector <int> > m(size);
	// 지도 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			m[i].push_back(map[i][j]);
			m[N + j].push_back(map[i][j]);
		}
		// 끝에 높은 벽을 세운다.
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
	//		// 높이 다른지 check
	//		if (tmp != map[i][j]) {
	//			// 언덕이 높아진 경우
	//			if (tmp < map[i][j]) {
	//				// 2이상 차이 나는 경우 또는 경사로 설치중이였다면 지나갈 수 있는 길에서 제외
	//				if (map[i][j] - tmp > 1 || cnt) {
	//					cout << "1 ";
	//					answer--;
	//					break;
	//				}
	//				else {
	//					// 경사로 가능한지 check 
	//					if (j - idx >= L) { // 가능하다면
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
	//			// 언덕이 낮은 경우
	//			else {
	//				// 2이상 차이 나는 경우 또는 경사로 설치중이였다면 지나갈 수 있는 길에서 제외
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
	//						// 다음 벽 있다면 고려
	//						if (j + 1 < N) {
	//							// 다음 언덕이 높은 경우
	//							if (map[i][j] < map[i][j + 1]) {
	//								cout << "4 ";
	//								answer--;
	//								break;
	//							}
	//							// 같은 경우 다음 지점부터 새로 시작
	//							else if (map[i][j] == map[i][j + 1]) {
	//								idx = ++j;
	//								tmp = map[i][idx];
	//							}
	//							// 낮은 경우 현재 지점부터 시작
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
	//			// 경사로 설치중이라면
	//			if (cnt) {
	//				cnt++;
	//				// 설치완료
	//				if (cnt == L) {
	//					cnt = 0;
	//					// 다음 벽 있다면 고려
	//					if (j + 1 < N) {
	//						// 다음 언덕이 높은 경우
	//						if (map[i][j] < map[i][j + 1]) {
	//							cout << "5 ";
	//							answer--;
	//							break;
	//						}
	//						// 같은 경우 다음 지점부터 새로 시작
	//						else if (map[i][j] == map[i][j + 1]) {
	//							idx = ++j;
	//							tmp = map[i][idx];
	//							continue;
	//						}
	//						// 낮은 경우 현재 지점부터 시작
	//						else {
	//							idx = j;
	//							tmp = map[i][idx];
	//							continue;
	//						}
	//					}
	//				}
	//				// 아직 설치 안된경우
	//				else {
	//					// 다음 땅 존재
	//					if (j + 1 < N) {
	//						idx = j;
	//						tmp = map[i][idx];
	//					}
	//					// 다음 땅 존재X,,
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
	//		// 높이 다른지 check
	//		if (tmp != map[j][i]) {
	//			// 언덕이 높아진 경우
	//			if (tmp < map[j][i]) {
	//				// 2이상 차이 나는 경우 또는 경사로 설치중이였다면 지나갈 수 있는 길에서 제외
	//				if (map[j][i] - tmp > 1 || cnt) {
	//					cout << "7 ";
	//					answer--;
	//					break;
	//				}
	//				else {
	//					// 경사로 가능한지 check 
	//					if (j - idx >= L) { // 가능하다면
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
	//			// 언덕이 낮은 경우
	//			else {
	//				// 2이상 차이 나는 경우 또는 경사로 설치중이였다면 지나갈 수 있는 길에서 제외
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
	//						// 다음 벽 있다면 고려
	//						if (j + 1 < N) {
	//							// 다음 언덕이 높은 경우
	//							if (map[j][i] < map[j + 1][i]) {
	//								cout << "10 ";
	//								answer--;
	//								break;
	//							}
	//							// 같은 경우 다음 지점부터 새로 시작
	//							else if (map[j][i] == map[j + 1][i]) {
	//								idx = ++j;
	//								tmp = map[idx][i];
	//								continue;
	//							}
	//							// 낮은 경우 현재 지점부터 시작
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
	//			// 경사로 설치중이라면
	//			if (cnt) {
	//				cnt++;
	//				// 설치완료
	//				if (cnt == L) {
	//					cnt = 0;
	//					// 다음 벽 있다면 고려
	//					if (j + 1 < N) {
	//						// 다음 언덕이 높은 경우
	//						if (map[j][i] < map[j + 1][i]) {
	//							cout << "11 ";
	//							answer--;
	//							break;
	//						}
	//						// 같은 경우 다음 지점부터 새로 시작
	//						else if (map[j][i] == map[j + 1][i]) {
	//							idx = ++j;
	//							tmp = map[idx][i];
	//							continue;
	//						}
	//						// 낮은 경우 현재 지점부터 시작
	//						else {
	//							idx = j;
	//							tmp = map[idx][i];
	//							continue;
	//						}
	//					}
	//				}
	//				// 아직 설치 안된경우
	//				else {
	//					// 다음 땅 존재
	//					if (j + 1 < N) {
	//						idx = j;
	//						tmp = map[idx][i];
	//					}
	//					// 다음 땅 존재X,,
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