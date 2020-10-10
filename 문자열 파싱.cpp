#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
	string a[3] = { "10/01", "23:20:25", "30" };
	string b[3] = { "10/01", "23:25:50", "26" };
	int intValue = atoi(a[0].substr(3, 2).c_str());
	cout << intValue;
	string str = "0" +  to_string(intValue);
	cout << str;
	//string str = "java and c and c++ and python";
	//istringstream ss(str);
	//string stringBuffer;
	//vector<string> x;
	//x.clear();
	//cout << "어떻게 잘리는지 확인해봅시다 ->";
	////구분자가 , 이라면 getline(ss, stringBuffer, ',')쓰면됨
	//while (getline(ss, stringBuffer, ' ')) {
	//	if(stringBuffer != "and")
	//		x.push_back(stringBuffer);
	//	cout << stringBuffer << " ";
	//}

	//cout << endl << "vector 값을 출력해보자." << endl;
	//for (int i = 0; i < x.size(); i++) {
	//	cout << x[i] << endl;
	//}

	return 0;
}
