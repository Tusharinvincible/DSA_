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

int maxi(Node * root, int & res) {
    if (root == NULL) {
        return 0;
    }
    int lmax = maxi(root -> left, res);
    int rmax = maxi(root -> right, res);

    int singlePathMax = max(max(lmax, rmax) + root -> data, root -> data);
    int BothPathMax = max(singlePathMax, lmax + rmax + root -> data);
    res = max(res, BothPathMax);

    return singlePathMax;
}
int findMaxSum(Node * root) {
    // Your code goes here
    int res = INT_MIN;
    maxi(root, res);
    return res;

}

int main() {
    Node * root = NULL;
    cout << findMaxSum(root);
    return 0;
}