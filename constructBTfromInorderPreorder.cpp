#include <bits/stdc++.h>

using namespace std;

class TreeNode {
  public:
    int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

};

int find(vector < int > & inorder, int low, int high, int key) {
  for (int i = low; i <= high; i++) {
    if (inorder[i] == key) {
      return i;
    }
  }
  return -1;
}
TreeNode * build(vector < int > & preorder, vector < int > & inorder, int low, int high) {
  if (preorder.size() == 0 || low > high) {
    return NULL;
  }
  int ele = preorder.back();
  preorder.pop_back();
  int idx = find(inorder, low, high, ele);
  TreeNode * root = new TreeNode(ele);

  root -> left = build(preorder, inorder, low, idx - 1);
  root -> right = build(preorder, inorder, idx + 1, high);

  return root;

}
TreeNode * buildTree(vector < int > & preorder, vector < int > & inorder) {

  int low = 0;
  int high = inorder.size();

  reverse(preorder.begin(), preorder.end());

  TreeNode * root = build(preorder, inorder, low, high);

  return root;

}