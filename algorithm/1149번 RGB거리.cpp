#include <iostream>
#include <algorithm>
using namespace std;
int Min(int a, int b){ return a < b ? a : b;}
int Dp[1001][3] = {};
int Ap[1001][3] = {};
int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin>> Ap[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        Dp[i][0] = Min(Dp[i-1][1],Dp[i-1][2]) + Ap[i][0];
        Dp[i][1] = Min(Dp[i-1][0],Dp[i-1][2]) + Ap[i][1];
        Dp[i][2] = Min(Dp[i-1][0],Dp[i-1][1]) + Ap[i][2];
    }
     cout<<Min(Dp[n][0],Min(Dp[n][1],Dp[n][2]))<<'\n';
} 