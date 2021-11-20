#include <bits/stdc++.h>
using namespace std;

//vector <int> dp(1000,INT_MAX);

// int minCost(int n){
//     if(dp[n]!=INT_MAX){
//         return dp[n];
//     }
//     if(n==0){
//        dp[n]=0;
//        return dp[n];
//     }
    
//     for(int i=1;i<=sqrt(n);i++){
    
//         dp[n]=min(dp[n],1+minCost(n-i*i));
        
//     }
//     return dp[n];


// }
/*
    dp[0]=0;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=sqrt(i);j++){
          dp[i]=min(dp[i],dp[i-j*j]);
      }
  }

  return dp[n];



*/

//  1 2 3 4 5 6 7 8 9 

// quantity change 

int main(){
    int n;
    cin>>n;
    
   // minCost(n);
    vector <int> dp(n+1,INT_MAX);

     dp[0]=0;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=sqrt(i);j++){
          dp[i]=min(dp[i],dp[i-j*j]+1);
      }
  }

  //return dp[n];

  for(int x: dp){
      cout<<x<<" ";
  }
  cout<<endl;

    cout<<"Ans is:  "<<dp[n]<<endl;


    return 0;
}