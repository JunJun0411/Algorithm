#include <iostream>
using namespace std;

const char color[6] = {'w', 'r', 'b', 'y', 'o', 'g'};
// �ð� ����
const int clock[6][4] = {
	{4, 2, 1, 5},
	{0, 2, 3, 5}, 
	{0, 4, 3, 1},
	{1, 2, 4, 5},
	{0, 5, 3, 2},
	{0, 1, 3, 4} 
};
int N, n;
char cube[6][3][3];

void transpose(int side){
	char temp[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp[i][j] = cube[side][2 - j][i];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[side][i][j] = temp[i][j];
		}
	}
}

void U(int side) {
	char tmp[3];
	for (int j = 0; j < 3; j++) {
		tmp[j] = cube[clock[side][0]][0][j];
		cube[clock[side][0]][0][j] = cube[clock[side][3]][0][j];
		cube[clock[side][3]][0][j] = cube[clock[side][2]][0][j];
		cube[clock[side][2]][0][j] = cube[clock[side][1]][0][j];
		cube[clock[side][1]][0][j] = tmp[j];
	}
}
void F(int side) { 
	char tmp[3];
	// �ð����
	for (int j = 0; j < 3; j++) {
		tmp[j] = cube[clock[side][0]][2][j];
		cube[clock[side][0]][2][j] = cube[clock[side][3]][2 - j][2];
		cube[clock[side][3]][2 - j][2] = cube[clock[side][2]][0][2 - j];
		cube[clock[side][2]][0][2 - j] = cube[clock[side][1]][j][0];
		cube[clock[side][1]][j][0] = tmp[j];
	}
}
void R(int side) {
	char tmp[3];
	// �ð����
	for (int j = 0; j < 3; j++) {
		tmp[j] = cube[clock[side][0]][2 - j][2];
		cube[clock[side][0]][2 - j][2] = cube[clock[side][3]][2 - j][2];
		cube[clock[side][3]][2 - j][2] = cube[clock[side][2]][2 - j][2];
		cube[clock[side][2]][2 - j][2] = cube[clock[side][1]][j][0];
		cube[clock[side][1]][j][0] = tmp[j];
	}
}
void D(int side) {
	char tmp[3];
	// �ð����
	for (int j = 0; j < 3; j++) {
		tmp[j] = cube[clock[side][0]][2][j];
		cube[clock[side][0]][2][j] = cube[clock[side][3]][2][j];
		cube[clock[side][3]][2][j] = cube[clock[side][2]][2][j];
		cube[clock[side][2]][2][j] = cube[clock[side][1]][2][j];
		cube[clock[side][1]][2][j] = tmp[j];
	}
}
void B(int side) {
	char tmp[3];
	// �ð����
	for (int j = 0; j < 3; j++) {
		tmp[j] = cube[clock[side][0]][0][2 - j];
		cube[clock[side][0]][0][2 - j] = cube[clock[side][3]][2 - j][2];
		cube[clock[side][3]][2 - j][2] = cube[clock[side][2]][2][j];
		cube[clock[side][2]][2][j] = cube[clock[side][1]][j][0];
		cube[clock[side][1]][j][0] = tmp[j];
	}
}
void L(int side) {
	char tmp[3];
	// �ð����
	for (int j = 0; j < 3; j++) {
		tmp[j] = cube[clock[side][0]][j][0];
		cube[clock[side][0]][j][0] = cube[clock[side][3]][2-j][2];
		cube[clock[side][3]][2-j][2] = cube[clock[side][2]][j][0];
		cube[clock[side][2]][j][0] = cube[clock[side][1]][j][0];
		cube[clock[side][1]][j][0] = tmp[j];
	}
}

void change(char side, char dir) {
	int d = dir == '+' ? 1 : 3;
	while (d--) {
		switch (side)
		{
		case 'U': // �� ��
			U(0);
			transpose(0);
			break;
		case 'F': // �� ��
			F(1);
			transpose(1);
			break;
		case 'R': // ������ ��
			R(2);
			transpose(2);
			break;
		case 'D': // �Ʒ� ��
			D(3);
			transpose(3);
			break;
		case 'B': // �� ��
			B(4);
			transpose(4);
			break;
		case 'L': // ���� ��
			L(5);
			transpose(5);
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--) {

		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					cube[i][j][k] = color[i];

		cin >> n;

		while (n--) {
			char side, dir;
			cin >> side >> dir;
			change(side, dir);
		}

		for (int i = 0; i < 3; i++) {
			//cout << "    ";
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << '\n';
		}
		// ������
		//for(int k=0; k<6; k++)
		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[5][i][j];
			}
			cout << " ";
			for (int j = 0; j < 3; j++) {
				cout << cube[1][i][j];
			}cout << " ";
			for (int j = 0; j < 3; j++) {
				cout << cube[2][i][j];
			}cout << " ";
			for (int j = 0; j < 3; j++) {
				cout << cube[4][i][j];
			}
			cout << '\n';
		}
		for (int i = 0; i < 3; i++) {
			cout << "    ";
			for (int j = 0; j < 3; j++) {
				cout << cube[3][i][j];
			}
			cout << '\n';
		}*/
	}
	return 0;
}