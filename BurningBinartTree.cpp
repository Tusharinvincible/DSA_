#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node * left;
    Node * right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* findNode(Node* root,map <Node* ,Node*> &mp,int key){
    queue <Node*> q;
    q.push(root);

    Node* req=NULL;

    while(!q.empty()){
        Node* curr=q.front();
        q.pop();

        if(curr->data==key){
            req=curr;
        }
        if(curr->left){
            q.push(curr->left);
            mp[curr->left]=curr;
        }
        if(curr->right){
            q.push(curr->right);
            mp[curr->right]=curr;
        }
    }
    return req;

}

int burningTree(Node* root,int key){
    map <Node* ,Node*> mp;
    Node* req=findNode(root,mp,key);

    queue <Node*> q;
    q.push(req);

    map <Node*,int> isBurned; 
    isBurned[req]=1;
   int time=0;

    while(!q.empty()){
        
        int n=q.size();
        bool anyOne=false;
       
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(isBurned[mp[curr]]==0){
                isBurned[mp[curr]]=1;
                anyOne=true;
                q.push(mp[curr]);
            }

            if(curr->left && isBurned[curr->left]==0){
                anyOne=true;
                isBurned[curr->left]=1;
                q.push(curr->left);
            }

            if(curr->right && isBurned[curr->right]==0){
                anyOne=true;
                isBurned[curr->right]=1;
                q.push(curr->right);
            }
        }


        if(anyOne){
            time++;
        }
        return time;
    }
    
}


int main(){




    return 0;
}