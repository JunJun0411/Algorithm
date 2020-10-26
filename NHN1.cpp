#include <iostream>
#include <vector>
using namespace std;

struct person {
	char name;
	bool fast;
};

// ��� �̸�, �޸��� ���� ���� 
vector<person> vec(27);
// ���� Ƚ��
int sul_count[28] = { 1, };
// ���� ���� �̸�, ��ġ
pair<char, int> sulae = { 'A', 0 }; 

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	vec.resize(numOfAllPlayers - 1);
	// �ʱ�ȭ
	for (char i = 0; i < numOfAllPlayers - 1; i++) {
		vec[i] = {'B' + i , false };
	}
	
	// �޸��� ���� ��� ����
	for (int i = 0; i < numOfQuickPlayers; i++) {
		vec[namesOfQuickPlayers[i] - 'B'].fast = true;
	}

	// ���� ����
	int N = numOfAllPlayers - 1;
	for (int i = 0; i < numOfGames; i++) {
		int cnt = numOfMovesPerGame[i];
		int head = sulae.second;
		cout << head << '\n';
		sulae.second = (head + cnt + (N * 100)) % N;
		cout << sulae.second << '\n';
		// ���� �ɾ��ִ� ����� ������ ���� ����� ���
		if (!vec[sulae.second].fast) {
			// ���� ��ü
			char tmp_name = vec[sulae.second].name;
			vec[sulae.second].name = sulae.first;
			sulae.first = tmp_name;
		}

		// ���� Ƚ�� ++
		sul_count[sulae.first - 'A']++;
	}


	// print
	for (int i = 0; i < numOfAllPlayers - 1; i++) {
		cout << vec[i].name << " " << sul_count[vec[i].name - 'A'] << '\n';
	}
	cout << sulae.first << " " << sul_count[sulae.first - 'A'] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	char namesOfQuickPlayers[2];
	int numOfAllPlayers, numOfQuickPlayers, numOfGames;
	int numOfMovesPerGame[2];
	cin >> numOfAllPlayers >> numOfQuickPlayers;
	for (int i = 0; i < 2; i++) {
		cin >> namesOfQuickPlayers[i];

	}
	cin >> numOfGames;
	for (int i = 0; i < 2; i++) {
		cin >> numOfMovesPerGame[i];
	}
	solution(numOfAllPlayers, numOfQuickPlayers, namesOfQuickPlayers, numOfGames, numOfMovesPerGame);
}

/*
6
2
B C
2
3 -2
*/