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


Node* lowestCommonAncestor(Node* root,Node* p,Node* q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    Node* leftNode=lowestCommonAncestor(root->left ,p,q);
    Node* rightNode=lowestCommonAncestor(root->right,p,q);

    if(leftNode==NULL){
        return rightNode;
    }
    else if(rightNode==NULL){
        return leftNode;
    }
    else{
        return root;
    }

}

int main(){

    return 0;
}