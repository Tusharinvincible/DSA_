// {
//     Name   => Prasad Zore;
// }

#include <iostream>

using namespace std;

struct BinarySearchTree{
    
    int data;
    
    BinarySearchTree *right, *left;

    int minNode;

    int nodesInLongestPath;
    
    BinarySearchTree() {
        this->right = nullptr;
        this->left = nullptr;
        this->nodesInLongestPath = 0;
    }
    BinarySearchTree(int initValue) {
        this->minNode = initValue;
        this->data = initValue;
        this->right = nullptr;
        this->left = nullptr;
        this->nodesInLongestPath = 0;
    }

    BinarySearchTree* insert(int insertValue, BinarySearchTree* rootNode) {
        if(rootNode==nullptr){
            return new BinarySearchTree(insertValue);
        }
        else if(rootNode->data > insertValue) {
            rootNode->left = insert(insertValue, rootNode->left);
        }
        else{
            rootNode->right = insert(insertValue, rootNode->right);
        }
        return rootNode;
    }

    void inorder(BinarySearchTree* rootNode, int count){
        if(rootNode==nullptr){
            if (count > this->nodesInLongestPath){
               this->nodesInLongestPath = count;
            }
            count = 0;
            return;
        }
        count = count + 1;
        inorder(rootNode->left, count);
        if(rootNode->data<this->minNode){
            this->minNode = rootNode->data;
        }
        cout << rootNode->data << "  ";
        inorder(rootNode->right, count);
    }

    void setNodesInLogestPath(BinarySearchTree* rootNode){
        int tempCount = 0;
        this->inorder(rootNode, tempCount);
    }

    string searchNode(BinarySearchTree* rootNode, int searchElement){
        if(rootNode==nullptr){
            return "Element Not Found";
        }
        if(rootNode->data==searchElement){
            return "Element Found";
        }
        else if(rootNode->data>searchElement){
            return searchNode(rootNode->left, searchElement);
        }
        else{
            return searchNode(rootNode->right, searchElement);
        }
    }

    static void mirrorTree(BinarySearchTree* binaryTree, BinarySearchTree* rootNode){
        binaryTree->data = rootNode->data;
        if(rootNode->left){
            binaryTree->right = new BinarySearchTree();
            mirrorTree(binaryTree->right, rootNode->left);
        }
        if(rootNode->right){
            binaryTree->left = new BinarySearchTree();
            mirrorTree(binaryTree->left, rootNode->right);
        }
        return;
    }

    static void inorderTraversal(BinarySearchTree* rootNode){
        if(rootNode==nullptr){
            return;
        }
        inorderTraversal(rootNode->left);
        cout << rootNode->data << "  ";
        inorderTraversal(rootNode->right);
    }
};

int main()
{
    cout << "Hello World" << endl;
    int count = 0;
    BinarySearchTree b(0), b1(0), *root = NULL, *root1=NULL;
    root = &b;
    b.insert(50, root);
    b.insert(30, root);
    b.insert(20, root);
    b.insert(40, root);
    b.insert(70, root);
    b.insert(60, root);
    b.insert(80, root);
 
    b.inorder(root, count);
    cout << "\nNodes in Longest Path are: " << b.nodesInLongestPath << endl;
    cout << "Smallest Node Value is: " << b.minNode << endl;
    cout << b.searchNode(root, 120) << endl;
    BinarySearchTree::mirrorTree(&b1,&b);
    root1 = &b1;
    cout << "Mirrored Tree: ";
    BinarySearchTree::inorderTraversal(root1);
    // b1.inorder(root1, count);
    cout << endl;
    
    return 0;
}
