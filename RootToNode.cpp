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

bool rootToNode(Node* root,vector <int> &v,int val){
    if(root==NULL){
        return false;

    }

    v.push_back(root->data);

    if(root->data==val){
        //Printing 

        return true;

    }
    if(rootToNode(root->left,v,val) || rootToNode(root->right,v,val)){

        return true;
    }
    v.pop_back();
    return false;
}

int main(){

    return 0;
}