#include <bits/stdc++.h>
using namespace std;

/*

Problem Statement
Ninja is learning the Typing course. He is a beginner so he is given a string ‘S’ of size ‘N’ containing only letters ‘a’, ‘b’ , ‘c’, ‘d’ and ‘e’.
Ninja has a strategy in mind that he will keep the fingers of his hands on the keys ‘a’, ‘b’ , ‘c’, ‘d’ and ‘e’ of the keyboard and just press them to avoid shift times. Ninja wants to minimize the absolute difference between the letters he typed with his left hand and the letters he typed with his right hand as he does not like imbalances.
Your task is to find one integer, the minimum absolute difference he can achieve between the letters he typed with his left hand and the letters he typed with the right hand.
Example :
N = 5
S = “abcde”

Explanation : 

If Ninja typed the letters ‘a’, ‘b’ and ‘c’ with left hand and letters ‘d’ and ‘e’ with his right hand, then he typed 3 letters with his left hand and 2 letters with his right hand. The absolute difference will be 1. This is the minimum imbalance he can achieve.
Input Format :
The first line contains an integer 'T' which denotes the number of test cases to be run. Then the test cases follow.

The first line of each test case contains an integer ‘N’.

The second line of each test case contains a string ‘S’ of length ‘N’.
Output Format :
For each test case, print one integer denoting the minimum absolute difference achievable.

Print the output of each test case in a new line.
Note :
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10
1 <= N <= 10^4
‘a’ <= S[i] <= ‘e’   

Time Limit: 1 sec
Sample Input 1 :
2
3
aab
4
abda 
Sample Output 1 :
1
0

*/

#include <bits/stdc++.h>
void pickNotPick(vector <int> v,int n,int idx,int ct,int &mini){
    if(idx==0){
        mini=min(abs(n-2*ct),mini);
        return;
    }
    pickNotPick(v,n,idx-1,ct+v[idx-1],mini);
    pickNotPick(v,n,idx-1,ct,mini);
}
int ninjaTypist(string &s, int n){
    // Write your code here.
    
    unordered_map <char,int> mp;
    int ct=0;
    vector <int> v(5,0);
    for(int i=0;i<n;i++){
        v[s[i]-'a']++;
       
    }
    
//     for(auto it=mp.begin();it!=mp.end();it++){
//         v.push_back(it->second);
//     }
//     int k=v.size();
//     int sum=n/2;
    
//     vector <vector <int>> dp(6,vector <int> (sum+1,0));
//     //  8 7  7
    
//     for(int i=1;i<=5;i++){
//         for(int j=1;j<=sum;j++){
//             if(v[i-1]<=j){
//                 dp[i][j]=max(dp[i][j],v[i-1]+dp[i-1][j-v[i-1]]);
//             }
//             dp[i][j]=max(dp[i][j],dp[i-1][j]);
//         }
//     }
    
//     return abs(n-2*dp[k][sum]);
    
    int mini=INT_MAX;
    pickNotPick(v,n,5,0,mini);
    
    return mini;
    
}