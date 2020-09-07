#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, float> myMap;
int pSsize;
int pPsize;


int priceCheck(vector<string> products, vector<float> productPrices, vector<string> productSold, vector<float> soldPrice) {
	int answer = 0;
	// 물건 배열의 크기
	pPsize = products.size();
	// 판매된 물건 배열의 크기
	pSsize = productSold.size();

	for (int i = 0; i < pPsize; i++) {
		myMap[products[i]] = productPrices[i];
	}
	
	for (int i = 0; i < pSsize; i++) {
		if (myMap[productSold[i]] != soldPrice[i]) {
			answer++;
		}
	}
	return answer;
}

int main() {
	vector<string> products = {"eggs", "milk", "cheese"};
	vector<float> productPrices = {2.89, 3.29, 5.79};
	vector<string> productSold = {"eggs", "eggs", "cheese", "milk"};
	vector<float> soldPrice = {2.89, 2.99, 5.97, 3.29};


	cout<< priceCheck(products, productPrices, productSold, soldPrice);
	return 0;
}