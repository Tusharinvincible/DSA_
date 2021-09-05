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

bool isIsomorphic(Node * root1, Node * root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 != NULL && root2 != NULL) {
        if (root1 -> data == root2 -> data)
            return true && (isIsomorphic(root1 -> left, root2 -> right) && isIsomorphic(root1 -> right, root2 -> left)) || (isIsomorphic(root1 -> left, root2 -> left) && isIsomorphic(root1 -> right, root2 -> right));

        return false;
    }

    return false;
}

int main() {

    return 0;
}