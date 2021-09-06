#include <bits/stdc++.h>

using namespace std;
class Node {
  public:
    int data;
  Node * next;
  Node(int _data) {
    data = _data;
    next = NULL;
  }
};
void reverseLL(Node * & sec_head) {
  Node * prev = NULL;
  Node * curr = sec_head;
  Node * next_node = curr;
  while (curr != NULL) {
    next_node = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = next_node;

  }
  sec_head = prev;
}
bool isPalindrome(Node * head) {
  Node * sPtr = head;
  Node * fptr = head -> next;

  while (fptr != NULL && fptr -> next != NULL) {
    sPtr = sPtr -> next -> next;
    fptr = fptr -> next;
  }
  Node * sec_head = NULL;

  if (fptr == NULL) {
    sec_head = sPtr;

  } else {
    sec_head = sPtr -> next;
  }

  reverseLL(sec_head);
  Node * new_head = head;
  while (sec_head != NULL) {
    if (sec_head -> data != new_head -> data) {
      return false;
    }
  }
  return true;

}

int main() {

  return 0;
}