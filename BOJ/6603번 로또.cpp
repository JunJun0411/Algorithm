#include <iostream>
using namespace std;

int Lotto[6];
int arr[13];

void DFS(int idx1, int idx2, int k) {
	// Lotto �迭�� 6�ڸ� �� ��� �� ��� ���
	if (idx2 == 6) {
		for (int i = 0; i < 6; i++) {
			cout << Lotto[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx1; i < k; i++) {
		Lotto[idx2] = arr[i];
		DFS(i + 1, idx2 + 1, k);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int k; cin >> k;
		// k�� 0�̸� ����
		if (!k) return 0;

		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		DFS(0, 0, k);
		cout << '\n';
	}
	return 0;
}