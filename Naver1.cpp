#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(int n, vector<int> p, vector<int> c) {
	string answer = "";
	int i;
	int price = 100, np = 0, ans = 0;
	double ans2 = 0.0;
	string sub;

	for (i = 0; i < n; i++) {
		// 이전 재고와 공급량이 주문량 이상인 경우
		if (np + p[i] - c[i] >= 0) {
			ans += c[i] * price;
			np += p[i] - c[i];
			price = 100;
		}

		// 주문량이 더 많은경우
		else {
			// 계약 종료
			if (price == 25) {
				i++;
				break;
			}
			// 이전 재고 추가, 가격 반값
			np += p[i];
			price /= 2;
		}
	}
	
	ans2 = (float)ans / i;	// 평균 구하기
	ans2 *= 100.0;			// 100.0 곱하고 ( 2째자리 반올림)
	ans = round(ans2);		// 반올림
	answer = to_string(ans);
	sub = answer.substr(answer.size() - 2);
	answer = to_string(ans / 100);
	answer.append(".");
	answer.append(sub);

	return answer;
}

int main() {
	int n = 6;
	int n2 = 7;
	vector<int> p = { 5, 4, 7, 2, 0, 6 };
	vector<int> c = { 4, 6, 4, 9, 2, 3 };
	vector<int> p1 = { 6, 2, 1, 0, 2, 4, 3 };
	vector<int> c1 = { 3, 6, 6, 2, 3, 7, 6 };
	cout << solution(n2, p1, c1) << "\n";

	return 0;
}