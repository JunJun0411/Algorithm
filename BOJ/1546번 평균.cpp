#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	float X=0,sum=0;
	vector<float> v(N);
	for (int i = 0; i < N; i++) {
		float X; cin >> X;
		v[i] = X;
	}
	vector<float>::iterator max = max_element(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		X = (v[i]/(*max))*100;
		sum += X;
	}
	cout << sum /N << '\n';
}