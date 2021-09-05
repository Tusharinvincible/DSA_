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

int largestSubtree(Node* root,int &maxi){
    if(root==NULL){
        return 0;

    }
    int Sum=root->data+largestSubtree(root->right,maxi)+largestSubtree(root->left,maxi);
   
    maxi=max(maxi,Sum);

    return Sum;
}





int main(){

Node* root=NULL;
root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->right->left=new Node(6);
root->right->right=new Node(7);
int maxi=INT_MIN;
largestSubtree(root,maxi);

cout<<maxi<<endl;


    return 0;
}