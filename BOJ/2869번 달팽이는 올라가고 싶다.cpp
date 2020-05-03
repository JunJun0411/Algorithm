#include <iostream>
using namespace std;

int main() {
	int A, B, V, day;
	cin >> A >> B >> V;
	int C = V - A;
	int D = A - B;

	if (C == 0) day = 1;
	else day = C%D ? C/D+2 : C/D+1;
	


	cout << day << '\n';
	return 0;
}