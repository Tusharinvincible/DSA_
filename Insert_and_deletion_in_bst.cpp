#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
Node* insucessor(Node* root){
    Node* temp=root;
    while(temp!=NULL && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;

}
Node* insert(Node* root,int key){
    if(root==NULL){
        return new Node(key);
    }
    else if(key<root->data){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}
Node* delete_node(Node* root,int key){
    if(root==NULL){
        return root;
    }
    else if(key<root->data){
        root->left=delete_node(root->left,key);
    }
    else if(key>root->data){
        root->right=delete_node(root->right,key);
    }
    else{
        if(root->left==NULL && root->right==NULL){
        
            delete root;
            root=NULL;
            return root;
        }
        else if(root->left==NULL){
            Node* temp2=root;
            root=root->right;
            delete temp2;
            return root;

            
        }
        else if(root->right==NULL){
            Node* temp3=root;
            root=root->left;
            delete temp3;
            return root;
        }
        else{
            Node* temp4=insucessor(root->right);
            root->data=temp4->data;
            root->right=delete_node(temp4,temp4->data);
            return root;
        }
    }
    return root;
    }
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void bfs(Node* root){
    if(root==NULL){
        return;
    }
    queue <Node* > q;
    q.push(root);
    q.push(NULL);
    int level=1;
    cout<<"nodes on level "<<level<<endl;
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<"  ";
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }

        if(q.front()==NULL){
            q.pop();
            if(!q.empty()){
                q.push(NULL);
                level++;
                cout<<"\n nodes on level "<<level<<endl;

            }
        }

    }
}
int main(){
    Node* root=NULL;
    root=insert(root,25);
    insert(root,15);
    insert(root,30);
    insert(root,35);
    insert(root,20);
    insert(root,10);
    inorder(root);
    cout<<"\n";
  //  delete_node(root,25);
   // inorder(root);
   bfs(root);
    return 0;
}
