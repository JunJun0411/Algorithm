#include <iostream>
#include <math.h>
using namespace std;

int N;
int mino[2][24];



void debugg() {
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 4; k++) {
				if (mino[i][j * 4 + k] > 9) cout << mino[i][j * 4 + k] % 10 + 1;
				else cout << mino[i][j*4 + k];
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

void insert(int t, int y, int x, int cnt) {
	int block[2][2];

	block[0][0] = x;
	block[1][0] = 3 - y;
	block[0][1] = -1;
	block[1][1] = -1;

	if (t == 2) {
		block[0][1] = x + 1;
		block[1][1] = 7 - y;

	}
	else if (t == 3) { 
		block[0][1] = x + 4;
		block[1][1] = 2 - y;
	}


	for (int i = 0; i < 2; i++) {
		// 위 아래
		if (block[i][1] - block[i][0] == 4 && block[i][1] != -1) {
			int next = block[i][1] + 4;
			while (next < 24 && !mino[i][next]) {
				next += 4;
			}
			mino[i][next - 4] = cnt;
			
			next = block[i][0] + 4;
			while (next < 24 && !mino[i][next]) {
				next += 4;
			}
			mino[i][next - 4] = cnt;
		}
		// 나란히
		else if (abs(block[i][1] - block[i][0]) == 1 && block[i][1] != -1) {
			int n1 = block[i][1] + 4;
			int n2 = block[i][0] + 4;
			while (n1 < 24 && n2 < 24 && !mino[i][n1] && !mino[i][n2]) {
				n1 += 4;
				n2 += 4;
			}
			mino[i][n1 - 4] = cnt;
			mino[i][n2 - 4] = cnt;
		}
		else if(block[i][1] == -1){
			int next = block[i][0] + 4;
			while (next < 24 && !mino[i][next]) {
				next += 4;
			}
			mino[i][next - 4] = cnt;
		}
	}
	
}

int domino() {
	int point = 0;
	for (int i = 0; i < 2; i++) {
		bool del = false;
		for (int j = 2; j < 6; j++) {
			int add = 0;
			for (int k = 0; k < 4; k++) {
				if(mino[i][j * 4 + k])
					add++;
			}
			if (add == 4) {
				del = true;
				point++;
				for (int k = 0; k < 4; k++) {
					mino[i][j * 4 + k] = 0;
				}
//				cout << "삭제" << '\n';
			}
		}
		if (del) {
			//debugg();
			// 점수 먹고 사라진 칸 채우기
			for (int j = 19; j >= 0; j--) {
				if (!mino[i][j]) continue;
				int ad = 0;
				bool flag = false;
				for (int k = 1; k < 3; k++) {// 인접한 블록 갯수 구하기
					if (j - k >= (j / 4 * 4) && mino[i][j] == mino[i][j - k]) ad++;
					else break;
				}
				//cout << "j: " << j << ", ad: " << ad << '\n';
				if (ad == 0) {
					int cnt = mino[i][j];
					int next = j + 4;
					while (next < 24 && !mino[i][next]) {
						next += 4;
						flag = true;
					}
					if(flag)
						mino[i][next - 4] = cnt;
				}
				else if (ad == 1) {
					int cnt1 = mino[i][j];
					int cnt2 = mino[i][j - 1];
					int next = j + 4;
					while (next < 24 && !mino[i][next] && !mino[i][next - 1]) {
						next += 4;
						flag = true;
					}
					if (flag) {
						mino[i][next - 4] = cnt1;
						mino[i][next - 5] = cnt2;
					}
				}
				//else { // ad == 2
				//	int cnt1 = mino[i][j];
				//	int cnt2 = mino[i][j - 1];
				//	int cnt3 = mino[i][j - 2];
				//	int next = j + 4;
				//	while (next < 24 && !mino[i][next] && !mino[i][next - 1] && !mino[i][next - 2]) {
				//		next += 4;
				//	}
				//	mino[i][next - 4] = cnt1;
				//	mino[i][next - 5] = cnt2;
				//	mino[i][next - 6] = cnt3;
				//}

				// 블록이 내려가기 전 원래 위치는 0으로 초기화
				if(flag)
					for (int k = 0; k <= ad; k++) 
						mino[i][j - k] = 0;
				

				j -= ad;
			}
		}
	}
	return point;
}
void newline() {
	for (int i = 0; i < 2; i++) {
		int flag = -1;
		bool check = false;
		for (int j = 0; j < 8; j++) {
			if (mino[i][j] && j < 4) {
				flag = 0;
				check = true;
				break;
			}
			else if (mino[i][j]) {
				flag = 4;
				check = true;
				break;
			}
		}
		//		cout <<"flag: "<< flag << '\n';
		if (check) {
			int arr[16];
			for (int j = 0; j < 16; j++) {
				arr[j] = mino[i][j + flag];
				mino[i][j] = 0;
			}
			for (int j = 0; j < 16; j++) {
				mino[i][j + 8] = arr[j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int point = 0;
	for(int i=1; i<=N; i++) {
		int t, y, x;
		cin >> t >> y >> x;
		// 파랑, 초록 연한 칸에 블록 입력
		insert(t, y, x, i);
	//	cout << "\n 삽입 후 \n";
	//	debugg();
		// 모노미노 실행.
		int res = 0;
		while (res = domino()) point += res;
		
	//	cout << "\n 실행 후 \n";
	//	debugg();
		newline();
	}

	
	// 파란, 초록 칸의 블록 수 print
	int num = 0;
	for (int i = 0; i < 2; i++) 
		for (int j = 8; j < 24; j++) 
			if (mino[i][j]) 
				num++;

	cout << point << '\n';
	cout << num << '\n';
	return 0;
}

/*
TEST CASE

8
2 0 0
2 0 1
3 0 0
2 0 1
1 0 1
1 0 2
3 0 3
3 0 3

10
1 0 1
2 0 2
2 0 1
1 0 1
2 0 2
2 0 0
1 0 2
3 0 3
3 0 0
3 0 0

7
1 0 1
2 0 2
2 0 0
3 0 3
1 0 0
2 0 0
3 0 2

7
1 2 1
3 0 3
3 2 2
2 0 2
1 3 1
3 2 0
2 1 1

5
1 3 3
2 2 2
2 1 1
2 0 0
2 0 2

ans)

2
10

6
2 3 0
1 3 2
1 2 1
2 2 2
2 1 0
2 1 2

ans)

1
16
*/