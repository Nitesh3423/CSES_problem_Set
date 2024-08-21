#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    //constructor
    Node(int data){
        value=data;
        next=nullptr;
    }
};


Node* deleteLL(Node* head , int val){
   Node* temp=head;
   while(temp->next->value!=val){
    temp=temp->next;
   }
   Node* curr=temp->next;
   temp->next=curr->next;
   curr->next=nullptr;
   return head;
}
//print linked list(traversal)
void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
// HW :- write a function to find length of linked list
//HW :- Search IN linked List

Node* findMiddle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=nullptr and fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    Node* head= new Node(1);
    head->next= new Node(2);
    head->next->next= new Node(3);
    head->next->next->next= new Node(4);
    head->next->next->next->next= new Node(5);
    cout<<"Normal List"<<endl;
    printLL(head);
    Node* middle= findMiddle(head);
    cout<<"middle of linked list is "<<middle->value<<endl;
    return 0;
}