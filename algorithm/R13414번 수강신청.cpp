#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int K, L;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	set<string> s;
	vector<string> vec;
	vector<string> vec1;
	int idx = 1;
	cin >> K >> L;
	
	for (int i = 0; i < L; i++) {
		string X; cin >> X;
		vec.push_back(X);
	}
	
	for (int i = L-1; i >=0; i--) {
		string X = vec[i];
		if(s.insert(X).second){
			vec1.push_back(X);
		}
	}
	
	int size = vec1.size();
	for (int i = size - 1; i >= size-K && i>=0; i--) {
		cout << vec1[i] << '\n';
	}

	return 0;	
}