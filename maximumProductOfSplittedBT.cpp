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
int total=0;
int sumOfNode(Node* root){
    if(root==NULL){
        return 0;
    }
    return root->data+sumOfNode(root->left)+sumOfNode(root->right);
}
int calcMax(Node* root,int &mx){
    if(root==NULL){
        return 0;
    }
    int curr=root->data+calcMax(root->left,mx)+calcMax(root->right,mx);
    mx=max(mx,(total-curr)*curr);
    return curr;
}

int main(){
    Node* root=NULL;
    total=sumOfNode(root);
    int mx=INT_MIN;
    calcMax(root,mx);
    cout<<mx<<endl;



    return 0;

}
