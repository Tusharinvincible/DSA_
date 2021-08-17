#include <bits/stdc++.h>
using namespace std;
long long recMul(long long a,long long b,long long mod){
    if(b==0){
        return 0;
    }
    if(b%2){
        return (a%mod+recMul(a,b-1,mod)%mod)%mod;
    }
    return ((a%mod)*((b/2)%mod)%mod+recMul(a,b/2,mod)%mod)%mod;
}   

int main(){
   // cout<<410664%235<<endl;
   long long a = 10123465234878998;
   long long b = 65746311545646431;
   long long m = 10005412336548794;
   a%=m;
    
    cout<<recMul(a,b,m)<<endl;



    return 0;
}
