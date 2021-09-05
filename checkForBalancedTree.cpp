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

int height(Node * root, int & maxi) {
    if (root == NULL) {
        return 0;
    }

    int lheight = height(root -> left, maxi);
    int rheight = height(root -> right, maxi);
    maxi = max(abs(lheight - rheight), maxi);

    return 1 + max(lheight, rheight);
}

bool isBalanced(Node * root) {
    int maxi = INT_MIN;

    height(root, maxi);

    if (maxi <= 1) {
        return true;
    }
    return false;

}

int main() {

    return 0;
}