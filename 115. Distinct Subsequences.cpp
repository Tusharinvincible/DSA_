/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//     int disSub(string s,string t,int n1,int n2){
//         if(n2==0){
//             dp[n1][n2]=1;
//             return dp[n1][n2];
//         }
//         if(n1==0){
//             dp[n1][n2]=0;
//             return dp[n1][n2];
//         }
        
//         if(s[n1-1]==t[n2-1]){
//             dp[n1][n2]=
//         }
//     }
    int count(int n1,int n2,string& s,string& t,vector<vector<int> >& dp)
{
    
   if(!n1&&n2) return 0;
   if(!n2)return 1;
    
   if(dp[n1][n2]!=-1) return dp[n1][n2];
    
    //   0123456
    //  "rabbbit"
    //  "rabbit"
    
   if(s[n1-1]==t[n2-1])
   {
       return  dp[n1][n2]=count(n1-1,n2-1,s,t,dp)+count(n1-1,n2,s,t,dp);
   }
    return  dp[n1][n2]=count(n1-1,n2,s,t,dp);
}
    int numDistinct(string s, string t) {
//         int n1=s.size();
//         int n2=t.size();
//         vector <vector <long long>> dp(n1+1,vector <long long> (n2+1,0));
//         for(int i=0;i<=n1;i++){
//             for(int j=0;j<=n2;j++){
//                 if(j==0){
//                     dp[i][j]=1;
//                 }
//                 else if(i==0){
//                     dp[i][j]=0;
//                 }
//                 else {
//                     long long sum=0;
//                     if(s[i-1]==t[j-1]){
//                         sum=dp[i-1][j-1]+dp[i-1][j];
//                     }
//                     else
//                     sum=dp[i-1][j];
                    
//                     dp[i][j]=sum;
//                 }
//             }
//         }
//         return int(dp[n1][n2])>INT_MAX ?-1:dp[n1][n2];
        
        int n1 = s.size();
    int n2 = t.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    return count(n1,n2,s,t,dp);
        
    }
};