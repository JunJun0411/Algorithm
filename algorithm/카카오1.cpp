#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";
	int size = new_id.size();
	// 1�ܰ� ��->��
	for (int i = 0; i < size; i++) {
		if (new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] += char('a' - 'A');
	}
	// 2�ܰ� Ư������ ����
	int idx = 0;
	for (int i = 0; i < size; i++) {
		char id = new_id[i];
		if ((id >= 'a' && id <= 'z') || (id >= '0' && id <= '9') || id == '-' || id == '_' || id == '.') new_id[idx++] = id;
	}
	size = idx;
	new_id.resize(size);

	// 3�ܰ� �ߺ� . ����
	idx = 1;
	for (int i = 1; i < size; i++) {
		char id = new_id[i];
		if (id == '.' && new_id[i - 1] == '.') continue;
		new_id[idx++] = id;
	}
	size = idx;
	new_id.resize(size);

	// 4�ܰ� ���� ù ���� .���
	if (new_id[size - 1] == '.') new_id.resize(--size);
	if (new_id[0] == '.') {
		new_id = new_id.substr(1, -1);
		size--;
	}
	// 5�ܰ� �� ���ڿ� 'a' ġȯ
	if (size == 0) {
		new_id = "a";
		size = 1;
	}
	// 6�ܰ� 15�ڷ� ����
	if (size >= 16) {
		size = 15;
		new_id.resize(size);
		if (new_id[size - 1] == '.') new_id.resize(--size);
	}

	if (size <= 2) {
		new_id.resize(3);
		if (size == 1) {
			char id = new_id[0];
			new_id[1] = id;
			new_id[2] = id;
		}
		else {
			new_id[2] = new_id[1];
		}
	}

	return new_id;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string str = "...!@BaT#*..y.abcdefghi klm";
	string str2 = "=.=";
	cout << solution(str2) << '\n';

	return 0;
}