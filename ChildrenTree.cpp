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

void childrenTree(Node* root){
    int sum=0;
    if(root==NULL){
        return;
    }
    if(root->left){
        sum+=root->left->data;
    }
    if(root->right){
        sum+=root->right->data;
    }
    if(sum>=root->data){
        root->data=sum;
    }
    else{
        if(root->left) root->left->data=root->data;

        if(root->right) root->right->data=root->data;
    }
    childrenTree(root->left);
    childrenTree(root->right);

    int total=0;
    if(root->left) total+=root->left->data;
    if(root->right) total+=root->right->data;
    if(root->left || root->right) root->data=total;
}


int main(){
    return 0;
    
}