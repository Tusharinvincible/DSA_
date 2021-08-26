<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int _data){
        data=_data;
        next=NULL;
    }
};

Node* reverse(Node* head){
   Node* curr=head;
   Node* prev=NULL;
   Node* nextNode=curr;
   while(curr!=NULL){
       nextNode=nextNode->next;
       curr->next=prev;
       prev=curr;
       curr=nextNode;
   }

   return prev;
}


Node* reverseGroup(Node* head,int k){
    int ct=0;
    Node* curr=head;
    Node* prev=NULL;
    Node* nextNode=curr;
    
    while(ct<k && curr!=NULL){
        nextNode=nextNode->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
        ct++;
    }
    if(curr!=NULL){
        head->next=reverseGroup(curr,k);
    }
    head=prev;
  
    
    return head;
}


int addOne(Node* head){
    if(head==NULL){
        return 1;
    }
    int carry=addOne(head->next);
    head->data=(head->data+carry);

    if(head->data>9){
        head->data=0;
        return 1;
    }
    else{
        return 0;
    }

}




int main(){
    Node* head;

    Node* nn=new Node(1);

    if(addOne(head)){
        nn->next=head;
        head=nn;
    }



    return 0;
=======
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int _data){
        data=_data;
        next=NULL;
    }
};

Node* reverse(Node* head){
   Node* curr=head;
   Node* prev=NULL;
   Node* nextNode=curr;
   while(curr!=NULL){
       nextNode=nextNode->next;
       curr->next=prev;
       prev=curr;
       curr=nextNode;
   }

   return prev;
}


Node* reverseGroup(Node* head,int k){
    int ct=0;
    Node* curr=head;
    Node* prev=NULL;
    Node* nextNode=curr;
    
    while(ct<k && curr!=NULL){
        nextNode=nextNode->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
        ct++;
    }
    if(curr!=NULL){
        head->next=reverseGroup(curr,k);
    }
    head=prev;
  
    
    return head;
}


int addOne(Node* head){
    if(head==NULL){
        return 1;
    }
    int carry=addOne(head->next);
    head->data=(head->data+carry);

    if(head->data>9){
        head->data=0;
        return 1;
    }
    else{
        return 0;
    }

}




int main(){
    Node* head;

    Node* nn=new Node(1);

    if(addOne(head)){
        nn->next=head;
        head=nn;
    }



    return 0;
>>>>>>> 4bdac3835afd50cc30c511c344af5f6a29e7090f
}