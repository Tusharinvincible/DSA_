/*

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.




*/

#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


unordered_map <TreeNode*,int> dp;

class Solution {
public:
//     int maxRob(TreeNode* root,bool istaken){
//         if(root==NULL){
//             return 0;
//         }
//         if(dp.find(root)!=dp.end()){
//             return dp[root];
//         }
//         if(istaken==false){
//             dp[root]=max({root->val+maxRob(root->left,true)+maxRob(root->right,true),maxRob(root->left,false)+maxRob(root->right,false)});
//         }
//         else{
//             dp[root]=max(maxRob(root->left,false),maxRob(root->right,false));
//         }
//         return dp[root];
        
        
       
//     }
    int maxRob(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(dp[root]){
            return dp[root];
        }
        int lmax=0;
        int rmax=0;
        if(root->left){
            lmax=maxRob(root->left->left)+maxRob(root->left->right);
        }
        if(root->right){
            rmax=maxRob(root->right->right)+maxRob(root->right->left);
        }
        
        dp[root]=max(root->val+lmax+rmax,(maxRob(root->left)+maxRob(root->right)));
        
        return dp[root];
    }
    int rob(TreeNode* root) {
//         vector <int> vec;
//         queue <TreeNode* > q;
//         q.push(root);
        
//         while(!q.empty()){
//             int ct=0;
            
//         }
        maxRob(root);
        int ans=0;
        
      for(auto it=dp.begin();it!=dp.end();it++)
          ans=max(ans,it->second);
//             cout<<it->first->val<<"  "<<it->second<<"\n";
        
       return dp[root];
    }
};