#include <bits/stdc++.h>
<<<<<<< HEAD
=======

>>>>>>> 4bdac3835afd50cc30c511c344af5f6a29e7090f
using namespace std;

class Node {
    public:
<<<<<<< HEAD
    int data;
=======
        int data;
>>>>>>> 4bdac3835afd50cc30c511c344af5f6a29e7090f
    Node * left;
    Node * right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

<<<<<<< HEAD
  int solveS(Node* root,int mx){
        if(root==NULL){
            return 0;
        }
        if(root->data>=mx){
            mx=root->data;
            return 1+solveS(root->left,mx)+solveS(root->right,mx);
            
        }
        return solveS(root->left,mx)+solveS(root->right,mx);
        
    }
    int goodNodes(Node* root) {
        int mx=INT_MIN;
        
        return solveS(root,mx);
        
    }



int main(){

    Node* root=NULL;
    cout<<goodNodes(root);

}
=======
int solveS(Node * root, int mx) {
    if (root == NULL) {
        return 0;
    }
    if (root -> data >= mx) {
        mx = root -> data;
        return 1 + solveS(root -> left, mx) + solveS(root -> right, mx);

    }
    return solveS(root -> left, mx) + solveS(root -> right, mx);

}
int goodNodes(Node * root) {
    int mx = INT_MIN;

    return solveS(root, mx);

}

int main() {

    Node * root = NULL;
    cout << goodNodes(root);

}
>>>>>>> 4bdac3835afd50cc30c511c344af5f6a29e7090f
