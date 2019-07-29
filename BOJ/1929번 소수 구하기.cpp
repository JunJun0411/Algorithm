#include <iostream>
using namespace std;

int sosu[1000001] = { 0, 1 };

int main() {
	int M, N, i,j; 
	scanf("%d%d", &M, &N);
	

	for (i = 2; i <= N; i++) {
		for (j = 2; i*j <= N; j++) {
			sosu[i*j] = 1;
		}
	}
	for (int i = M; i <= N; i++) {
		if (!sosu[i]) printf("%d\n", i);
	}
}

