#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int R, C, K;
int maxRC[2]; // 행 개수, 열 개수 값 기록
int arr[201][201];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

void calculateR() {
	int r = maxRC[0], c = maxRC[1];
	int maxC = 0;
	for (int i = 0; i < r; i++) {
		vector<pair<int, int> > buf;
		
		sort(arr[i], arr[i] + c, less<int>());
		int num = arr[i][0];
		int count = 1;
		for (int j = 1; j <= c; j++) {
			// 같은 숫자 갯수 count
			if (num == arr[i][j]) {
				count++;
			}
			else {
				buf.push_back({ num, count });
				if (arr[i][j] == INF) break;
				num = arr[i][j];
				count = 1;
			}
		}

		sort(buf.begin(), buf.end(), cmp);
		int size = buf.size();
		for (int j = 0; j < size * 2; j += 2) {
			arr[i][j] = buf[j / 2].first;
			arr[i][j + 1] = buf[j / 2].second;
		}

		// 줄어드는 경우 줄어든 만큼 INF로 채워준다.
		for (int j = size * 2; j < c; j++) {
			arr[i][j] = INF;
		}

		maxC = max(maxC, size * 2);
	}
	maxRC[1] = maxC;

	/*cout << "maxRC[1]: " << maxRC[1] << '\n';
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= maxC; j++)
			if (arr[i][j] != INF) 
				cout << arr[i][j];
		cout << '\n';
	}
	cout << '\n';*/
}

void calculateC() {
	int r = maxRC[0], c = maxRC[1];
	int maxR = 0;
	for (int i = 0; i < c; i++) {
		vector<pair<int, int> > buf;
		vector<int> arr1;
		for (int j = 0; j < r; j++) {
			if (arr[j][i] == INF) continue;
			arr1.push_back(arr[j][i]);
		}
		arr1.push_back(INF);
		

		sort(arr1.begin(), arr1.end(), less<int>());
		/*for (int j = 0; j < arr1.size(); j++) {
			cout << arr1[j] << " ";
		}
		cout << '\n';*/
		int num = arr1[0];
		int count = 1;
		for (int j = 1; j <= r; j++) {
			// 같은 숫자 갯수 count
			if (num == arr1[j]) {
				count++;
			}
			else {
				buf.push_back({ num, count });
				if (arr1[j] == INF) break;
				num = arr1[j];
				count = 1;
			}
		}

		sort(buf.begin(), buf.end(), cmp);
		int size = buf.size();
		/*for (int j = 0; j < size * 2; j += 2) {
			cout << buf[j / 2].first << ", " << buf[j / 2].second << '\n';
		}*/
		for (int j = 0; j < size * 2; j += 2) {
			arr[j][i] = buf[j / 2].first;
			arr[j+1][i] = buf[j / 2].second;
		}

		// 줄어드는 경우 줄어든 만큼 INF로 채워준다.
		for (int j = size * 2; j < r; j++) {
			arr[j][i] = INF;
		}

		maxR = max(maxR, size * 2);
	}
	maxRC[0] = maxR;

	/*cout << "maxRC[0]: " << maxRC[0] << '\n';
	for (int i = 0; i <= maxRC[0]; i++) {
		for (int j = 0; j <= maxRC[1]; j++)
			if (arr[i][j] != INF)
				cout << arr[i][j];
		cout << '\n';
	}*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> K;

	for (int i = 0; i < 201; i++)
		for (int j = 0; j < 201; j++)
			arr[i][j] = INF;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	maxRC[0] = maxRC[1] = 3;

	int time = 0;
	while (arr[R-1][C-1] != K) {
		
		if (maxRC[0] >= maxRC[1]) {
			// 행 갯수 >= 열 개수 이므로 R연산 -> maxRC[1]이 변함
			calculateR();
		}
		else {
			// C연산
			calculateC();
		}

		if (time++ == 100) {
			time = -1;
			break;
		}
	}
	cout << time << '\n';
	return 0;
}