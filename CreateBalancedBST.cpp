#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};



Node* createBst(int arr[],int i,int j){
    if(i<=j){
        int mid=(i+j)/2;
        Node* root=new Node(arr[mid]);
        root->left=createBst(arr,i,mid-1);
        root->right=createBst(arr,mid+1,j);
        return root;
    }
    return NULL;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}

int main(){
    int arr[]={1,2,5,7,10,13,14,15,22};
    int i=0;
    int j=8;
    Node* root=createBst(arr,i,j);
    inorder(root);

    
    
    return 0;
}
