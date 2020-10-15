#include <iostream>
using namespace std;

// ºÏ µ¿ ³² ¼­, ³² µ¿ ºÏ ¼­
const int dy[8] = {-1, 0, 1, 0 , 1, 0, -1, 0 };
const int dx[8] = { 0, 1, 0, -1, 0, 1, 0, -1 };

int R, C, T;
int room[51][51];
int dRoom[51][51];
int air[2]; // Ã»Á¤±â y ÁÂÇ¥


void spread() {
	int dust;

	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			dRoom[y][x] = 0;

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if ((dust = room[y][x]) < 5) {
				dRoom[y][x] += room[y][x];
				continue;
			}

			int dusty = dust / 5;
			int idx = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || room[ny][nx] == -1) continue;
				dRoom[ny][nx] += dusty;
				idx++;
			}
			dRoom[y][x] += dust - (dusty * idx);
		}
	}


	//for (int y = 0; y < R; y++) {
	//	for (int x = 0; x < C; x++)
	//		cout << room[y][x]<< "  ";
	//	cout << '\n';
	//}
	//cout << '\n';

	//for (int y = 0; y < R; y++) {
	//	for (int x = 0; x < C; x++)
	//		cout << dRoom[y][x] << "  ";
	//	cout << '\n';
	//}
	//cout << '\n';

}

void wind() {
	int ny = air[0] - 1;
	int nx = 0;
	
	// À­ÂÊ 
	for (int i = 0; i < 4; i++) { // ºÏ µ¿ ³² ¼­
		while (room[ny][nx] != -1) {
			ny = ny + dy[i];
			nx = nx + dx[i];
			if (ny >= 0 && ny <= air[0] && nx >= 0 && nx < C)
				if (dRoom[ny][nx] == -1) dRoom[ny - dy[i]][nx - dx[i]] = 0;
				else dRoom[ny - dy[i]][nx - dx[i]] = dRoom[ny][nx];
			else break;
		}
		ny = ny - dy[i];
		nx = nx - dx[i];
	}

	// ¾Æ·§ÂÊ Ã»Á¤±â
	ny = air[1] + 1;
	nx = 0;
	// À­ÂÊ 
	for (int i = 4; i < 8; i++) { // ºÏ µ¿ ³² ¼­
		while (room[ny][nx] != -1) {
			ny = ny + dy[i];
			nx = nx + dx[i];
			if(ny >= air[1] && ny < R && nx >= 0 && nx < C)
				if (dRoom[ny][nx] == -1) dRoom[ny - dy[i]][nx - dx[i]] = 0;
				else dRoom[ny - dy[i]][nx - dx[i]] = dRoom[ny][nx];
			else break;
		}
		ny = ny - dy[i];
		nx = nx - dx[i];
	}

	/*for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++)
			cout << dRoom[y][x] << "  ";
		cout << '\n';
	}
	cout << '\n';*/

	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++) {
			room[y][x] = dRoom[y][x];
			dRoom[y][x] = 0;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) {
				air[0] = i - 1;
				air[1] = i;
			}
		}
	}

	while (T--) {
		// È®»ê
		spread();

		// ¼øÈ¯
		wind();
	}

	int res = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			res += room[i][j];
		}
	}
	cout << res + 2 << '\n';
	return 0;
}