#include <bits/stdc++.h>
using namespace std;
/*
Given two strings A and B, find the minimum number of times A has to be repeated
 such that B becomes a substring of the repeated A. If B cannot 
 be a substring of A no matter how many times it is repeated, return -1.

Example 1:

Input: A = "abcd", B = "cdabcdab"
Output: 3
Explanation: After repeating A three times, 
we get "abcdabcdabcd".
Example 2:

Input: A = "aa", B = "a"
Output: 1
Explanation: B is already a substring of A.

*/

bool isSubStr(string B,string A){
    int len1=A.size();
    int len2=B.size();

    for(int i=0;i<=(len1-len2);i++){
        int j;
        for(j=0;j<len2;j++){
            if(A[i+j]!=B[j]){
                break;
            }

        }
        if(j==len2){
            return true;
        }
    }
    return false;
}

int repeatedString(string A,string B){
    string s=A;
    int ans=1;

    while(s.size()<B.size()){
        s+=A;
        ans++;
    }

    if(isSubStr(B,s))
        return ans;
    if(isSubStr(B,s+A)){
        return ans+1;
    }

    return -1;
}


int main(){

    string A="abcd";
    string B="abcdab";
    cout<<repeatedString(A,B)<<endl;
    return 0;
}





