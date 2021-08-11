#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*  left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* insert(Node* root,int key){
    if(root==NULL){
        return new Node(key);
    }
    else if(key<root->data){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}

void flatten(Node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        Node* t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;

    }
    flatten(root->right);
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root=NULL;
    root=insert(root,5);
    insert(root,2);
    insert(root,1);
    insert(root,7);
    insert(root,10);
    cout<<"Preorder Before: ";
    preorder(root);
    cout<<"\n";
    cout<<"Preorder After: ";
    flatten(root);
    preorder(root);



    return 0;

}