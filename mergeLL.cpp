#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
        
    }
};
Node* insert(Node* &head,int x){
    Node* nn=new Node(x);
    if(head==NULL){
        head=nn;
        return nn;
    
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nn;
    return nn;
}

void print(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<"\n";

}

Node* merge(Node* &head1,Node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* k;
    if(head1->data<=head2->data){
        k=head1;
        head1->next=merge(head1->next,head2);
    }
    else{
        k=head2;
        head2->next=merge(head1,head2->next);
    }
    return k;
}

int main(){
    Node* head1=NULL;
    head1=insert(head1,1);
    insert(head1,3);
    Node* head2=NULL;
    head2=insert(head2,2);
    insert(head2,4);

    print(head1);
    print(head2);
    Node* head3=merge(head1,head2);

    print(head3);


    return 0;
}


