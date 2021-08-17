#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

void topView(Node* root){
    queue <pair <Node*,int> > q;
    if(root==NULL){
        return;
    }
    q.push({root,0});
    int left_dist=0;
    int right_dist=0;
    stack <int> st;
    vector <int> v;
    while(!q.empty()){
        Node* par=q.front().first;
        int root_dis=q.front().second;
        int hl=root_dis-1;
        int hr=root_dis+1;
        q.pop();
        if(par->left!=NULL){
            q.push({par->left,hl});
            if(hl<left_dist){
                left_dist=hl;
                st.push(par->left->data);
            }

        }
        if(par->right){
            q.push({par->right,hr});
            if(hr>right_dist){
                right_dist=hr;
                v.push_back(par->right->data);
            }
        }

    }
    cout<<"PRINTING TOP VIEW OF BINARY TREE:  ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<root->data<<" ";

    for(int i=0;i<v.size();i++){

        cout<<v[i]<<" ";

    }
    cout<<"\n";

}



Node* createBst(int arr[],int i,int j){
    if(i<=j){
        int mid=(i+j)/2;
        Node* root=new Node(arr[mid]);
        root->left=createBst(arr,i,mid-1);
        root->right=createBst(arr,mid+1,j);
        return root;
    }
    return NULL;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}

int main(){
    int arr[]={1,2,5,7,10,13,14,15,22};
    int i=0;
    int j=8;
    Node* root=createBst(arr,i,j);
    inorder(root);
    
    cout<<"\n";

    topView(root);

    
    
    return 0;
}