#include <bits/stdc++.h>
using namespace std;


bool isPossible(int i,int j,int N,int M){
    if(i>=0 && i<N && j>=0 && j<M){
        return true;
    }
    return false;
}
long long solve(int N, int M)
{
    // write code here
    long long ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int temp=0;
            if(isPossible(i+1,j-2,N,M)){
                temp++;
            }
            if(isPossible(i-1,j-2,N,M)){
                temp++;
            }
            if(isPossible(i-2,j-1,N,M)){
                temp++;
            }
            if(isPossible(i-2,j+1,N,M)){
                temp++;
            }
            if(isPossible(i+1,j+2,N,M)){
                temp++;
            }
            if(isPossible(i-1,j+2,N,M)){
                temp++;
            }
            if(isPossible(i+2,j-1,N,M)){
                temp++;
            }
            if(isPossible(i+2,j+1,N,M)){
                temp++;
            }
            ans=ans%1000000007+((N*M)-1-temp)%1000000007;
        }
    }
    return ans;
    
}


int main(){
    int N,M;
    cin>>N>>M;
    cout<<solve(N,M);

    return 0;

}