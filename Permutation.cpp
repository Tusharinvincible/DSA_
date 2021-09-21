#include <bits/stdc++.h>
using namespace std;

int mod=1000000007;
int Permutation(int n,int r,vector <vector <int> > &dp){
    if(dp[n][r]!=-1){
        return dp[n][r];
    }
    if(r>n){
        return 0;
    }
    if(r==0 || n==r){
        dp[n][r]=1;
        return dp[n][r];
    }
    dp[n][r]=(Permutation(n-1,r-1,dp)+Permutation(n-1,r,dp))%mod;
    return dp[n][r];
}
    int nCr(int n, int r){
        
        vector <vector <int> > dp(n+1,vector <int> (r+1,-1));
        
        return Permutation(n,r,dp);
      
        
        
        
    }

int main(){


    return 0;
}