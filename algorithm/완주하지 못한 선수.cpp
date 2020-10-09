#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
	int size = phone_book.size();
	int psize, ppsize, i, j;
	for (i = 0; i < size - 1; i++) {
		// 첫자리 같으면
		if (phone_book[i][0] == phone_book[i + 1][0]) {
			psize = phone_book[i].size();
			ppsize = phone_book[i + 1].size();
			if (psize >= ppsize) continue;

			for (j = 0; j < psize; j++) {
				if (phone_book[i][j] != phone_book[i + 1][j]) break;
			}
			if (j == psize) return false;
		}
	}

    return answer;
}
int main() { 
	vector<string> a = { "123", "125", "12235", "124" , "567", "88", "111", "000" };
	
	cout << solution(a);
	return 0;
}