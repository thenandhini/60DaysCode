
//QN1 Find the starting point of the loop
//Qn 2 Remove the loop
//QN 3 Check for Palindrome in Linked list
//Qn 4 Remove the duplicates from sorted linked list
//Qn 5 Remove the duplicates from Unsorted linkedlist

#include <iostream>
using namespace std;
class Node{
 public:
 int data;
 Node* next;

 Node()
 {
 this->data=0;
 this->next=NULL;
 }
 Node(int data)
 {
 this->data=data;
 this->next=NULL;
 }
};

Node* removeLoop(Node* &first) {
  if(first== NULL) {
    cout << "LL is empty "<< endl;
    return NULL;
  }

  Node* slow = first;
  Node* fast = first;
  while(fast != NULL)
  {
    fast = fast -> next;
    if(fast != NULL) 
    {
    fast = fast -> next;
    slow = slow -> next;
    }
    if(slow == fast ) 
    {
       slow = first;
        break;
    }
  }

  Node* prev = fast;
  while(slow != fast)
  {
    prev = fast;
    slow = slow -> next;
    fast =fast -> next;
  }
  prev -> next = NULL;
  return slow;
}

void print(Node* &first)
{
    Node*temp=first;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }
}
int main() {
Node* first= new Node(10);
Node* second= new Node(20);
Node* third= new Node(30);
Node* fourth= new Node(40);
Node* fifth= new Node(50);
Node* sixth= new Node(60);
first->next=second;
second->next=third;
third->next=fourth;
fourth->next=fifth;
fifth->next=sixth;
sixth->next=sixth;
removeLoop(first);
print(first);
}