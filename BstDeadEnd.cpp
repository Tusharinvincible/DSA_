//Given a Binary search Tree that contains positive integer values greater then 0. 
//The task is to complete the function isDeadEnd which returns true if the BST contains 
//a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

void inorder(Node* root,unordered_set <int> &allNodes,unordered_set <int> &leafNodes){
    if(root==NULL){
        return;
    }
    allNodes.insert(root->data);
    
    if(root->left==NULL && root->right==NULL){
        leafNodes.insert(root->data);
    }
    inorder(root->left,allNodes,leafNodes);
    inorder(root->right,allNodes,leafNodes);
}
bool isDeadEnd(Node *root)
{
    if(root==NULL){
        return false;
    }
    unordered_set <int> allNodes;
    unordered_set <int> leafNodes;
    allNodes.insert(0);
    
    inorder(root,allNodes,leafNodes);
    
    for(auto it=leafNodes.begin();it!=leafNodes.end();it++){
        
        int x=*it;
        
        if(allNodes.find(x-1)!=allNodes.end() && allNodes.find(x+1)!=allNodes.end()){
            return true;
        }
        
    }
    return false;
    
}
