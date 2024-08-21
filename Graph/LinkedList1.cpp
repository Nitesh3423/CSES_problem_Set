#include<bits/stdc++.h>
using namespace std;
// class A{
//     int a, b; //deafault private
//     public:
//     //constructor  function -> private variable
//     void set(int x,int y){   //method
//         a=x;
//         b=y;
//     }
//     void get(){
//         cout<<a<<" "<<b<<endl;
//     }
    
// };

//Node implementation of Linked List of single linked list
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

//print linked list(traversal)
void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//insertion
Node* insertInHead(Node* head , int val){
    Node* temp= new Node(val); //created node
    temp->next=head;
    head=temp;
    return head;
}
Node* insertInTail(Node* head , int val){
    Node* temp= new Node(val); //created node
    Node* t=head;
    while(t->next!=nullptr){
        t=t->next;
    }
    t->next=temp;
    return head;
}
Node* insertAtValue(Node* head , int value,int key){
    Node* temp= new Node(value);
    Node* t=head;
    while(t->value!=key){
        t=t->next;
    }
    Node* Next= t->next;
    t->next=temp;
    temp->next=Next;
    return head;
}
// H.W  comlpete the function of insertion at given position;
Node* insertAtPos(Node* head , int value , int pos){
    
}

int main(){
    Node* head= new Node(1);
    head->next= new Node(2);
    head->next->next= new Node(3);
    head->next->next->next= new Node(4);
    head->next->next->next->next= new Node(5);
    head->next->next->next->next->next= new Node(6);
    
   
    return 0;
}