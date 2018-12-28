#include <iostream>
using namespace std;
int z=0, o=0;
int fibonacci(int n) {
    if (n == 0) {
        z++;
        return 0;
    } else if (n== 1) {
        o++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main(){
    int T,N; cin>>T;
    for(int i=0; i<T; i++){
        printf("%d",)
        fibonacci(N);
        cout<<z <<" "<<o<<'\n';
        z=0;
        o=0;
    }
}