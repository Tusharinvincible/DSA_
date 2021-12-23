/*


Given two integer arrays nums1 and nums2, 
return the maximum length of a subarray that appears in both arrays.




*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int n1=nums1.size();
        int n2=nums2.size();
//         for(int i=0;i<n1;i++){
//             for(int j=0;j<n2;j++){
//                 if(nums1[i]==nums2[j]){
//                     int tempi=i;
//                     int tempj=j;
//                     int ct=0;
//                     while(tempi<n1 && tempj<n2 && nums1[tempi]==nums2[tempj]){
//                         ct++;
//                         tempi++;
//                         tempj++;
                        
//                     }
//                     ans=max(ans,ct);
//                 }
//             }
//         }
//         return ans;
        vector <vector <int>> dp(n1+1,vector <int> (n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
    
};