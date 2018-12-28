#include <iostream>
using namespace std;
int Max(int a, int b){ return a> b ? a:b;}
int Dp[301] = {};
int Ap[301] = {};
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin >> Ap[i];
    }
    for(int i=1; i<=3&&i<=n;i++){
        if(i!=3) Dp[i] = Ap[i] + Ap[i-1];   
        else Dp[i] = Max(Ap[i]+Ap[i-1], Ap[i]+Ap[i-2]);
    }
    for(int i=4;i<=n;i++){
        Dp[i]= Max(Ap[i] + Ap[i-1] + Dp[i-3], Ap[i] + Dp[i-2] );
    }
    cout<<Dp[n]<<'\n';
}