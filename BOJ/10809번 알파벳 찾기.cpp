#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int idx = 0;
	int arr[26];
	for (int i = 0; i < 26; i++) arr[i] = -1;
	
	int size = s.size();
	for (int i = 0; i < size; i++) 
		if(arr[s[i] - 'a'] == -1) 
			arr[s[i] - 'a'] = i;
	

	for (int i = 0; i < 26; i++) cout << arr[i] << " ";
	cout << '\n';

	return 0;
}