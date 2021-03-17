//Insertion in Threaded Binary Tree
#include<iostream>
using namespace std;
class Node{
    public:
	int data;
	Node *left, *right;
    int lth;
    int rth;
    Node(int x){
        data=x;
        left=right=NULL;
        lth=1;
        rth=1;

    }
};      
Node* insert(Node* root,int key){
    Node* parent=NULL;
    Node* curr=root;
    Node* nn=new Node(key);
    
    while(curr!=NULL){
        if(curr->data==key){
            cout<<"Duplicate Found";
            return root;
        }
        parent=curr;
        if(key<curr->data){
            if(curr->lth==0){
                curr=curr->left;
            }
            else{
                break;
            }
        }
        else if(key>curr->data){
            if(curr->rth==0){
                curr=curr->right;
            }
            else{
                break;
            }
        }
    }
    if(parent==NULL){
        root=nn;

    }
    else if(key<parent->data){
        nn->left=parent->left;
        nn->right=parent;
        parent->lth=0;
        parent->left=nn;

    }
    else if(key>parent->data){
        nn->right=parent->right;
        nn->left=parent;
        parent->rth=0;
        parent->right=nn;
    }
    return root;
}
Node* left_ptr(Node* root){
   Node* temp=root;
   while(temp->lth!=1){
      
       temp=temp->left;
   }
   return temp;
   
}
void inorder(Node* root){
    Node* curr=left_ptr(root);
    while(curr!=NULL){
        cout<<curr->data<<" ";
        if(curr->rth==1){
            curr=curr->right;
        }
        else{
            curr=left_ptr(curr->right);
        }
    }
}
int main(){
    Node* root=new Node(14);
    insert(root,10);
    insert(root,5);
    insert(root,12);
    insert(root,15);
    insert(root,6);
    inorder(root);


    return 0;
}
