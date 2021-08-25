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
