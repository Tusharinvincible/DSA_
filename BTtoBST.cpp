#include <bits/stdc++.h>
using namespace std;

//Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.

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

void insertNode(Node* root,vector <int> &v){
    if(root==NULL){
        return;
    }
    insertNode(root->left,v);
    root->data=v.back();
    v.pop_back();
    insertNode(root->right,v);
}
void inorder(Node* root,vector <int> &v){
    if(root==NULL){
        return;
    }

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

void bstToBT(Node* root){
    vector <int> v;
    inorder(root,v);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    insertNode(root,v);
}



int main(){
    Node* root=NULL;
    root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    inorderPrint(root);

    bstToBT(root);

    cout<<"\n";
    
    inorderPrint(root);
    return 0;
}