#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};



class Solution{

    public:
    Node* findTarget(Node* root,int target,map <Node*,Node*> &mp){
        queue <Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            if(curr->data==target){
                return curr;
            }
            
            if(curr->left){
                mp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return NULL;
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        map <Node* ,Node*> mp;
        Node* tarNode=findTarget(root,target,mp);
        if(tarNode==NULL){
            return 0;
        }
        queue <Node*> q;
        q.push(tarNode);
        map <Node* ,bool> vis;
        int ans=target;
        if(k==0){
            return ans;
        }
        vis[tarNode]=true;
        while(!q.empty() && k--){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                Node* curr=q.front();
                q.pop();
                
                if(mp.find(curr)!=mp.end()){
                    if(vis[mp[curr]]==false){
                        ans+=mp[curr]->data;
                        q.push(mp[curr]);
                        vis[mp[curr]]=true;
                        
                    }
                    
                }
                
                if(curr->left){
                    if(vis[curr->left]==false){
                        vis[curr->left]=true;
                        ans+=curr->left->data;
                        q.push(curr->left);
                       
                    }
                }
                
                if(curr->right){
                    if(vis[curr->right]==false){
                        vis[curr->right]=true;
                        ans+=curr->right->data;
                        q.push(curr->right);

                    }
                }
            }
            
        }
        return ans;
        
    }


};