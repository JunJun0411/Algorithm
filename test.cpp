#include <iostream>
using namespace std;
int Dp[1001][3]={};
int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>> Dp[i][j];
        }
    }
    
} 