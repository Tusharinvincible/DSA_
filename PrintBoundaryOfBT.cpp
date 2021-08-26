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
void leftBoundary(Node* root,vector <int> &v){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
     v.push_back(root->data);
    if(root->left!=NULL){
       
       leftBoundary(root->left,v);
    }else{
        leftBoundary(root->right,v);

    }
}


void rightBoundary(Node* root,vector <int> &v){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    
    if(root->right!=NULL){
        rightBoundary(root->right,v);
    }
    else{
        rightBoundary(root->left,v);
    }
    v.push_back(root->data);
}

void bottomBoundary(Node* root, vector <int> &v){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        v.push_back(root->data);
    }
    bottomBoundary(root->left,v);
    bottomBoundary(root->right,v);
}






int main(){



    return 0;
}


