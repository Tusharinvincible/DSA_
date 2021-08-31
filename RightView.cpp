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

void rightView(Node* root,vector <int> &ans,int level){
    if(root==NULL){
        return;
    }
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    rightView(root->right,ans,level+1);
    rightView(root->left,ans,level+1);
}

int main(){


    return 0;
}