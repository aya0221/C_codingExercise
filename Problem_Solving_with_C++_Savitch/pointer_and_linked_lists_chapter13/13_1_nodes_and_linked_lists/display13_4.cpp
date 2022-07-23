/*
function to add a node a the head of a linked list

*/

#include<iostream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node *link;
    
};
typedef Node* NodePtr;

void headInsert(NodePtr& head, int theNumber);

int main(){

    return 0;
}


void headInsert(NodePtr& head, int theNumber){
    NodePtr tempPtr;
    tempPtr = new Node;
    tempPtr -> data = theNumber;

    //CHANGE
    tempPtr->link = head;
    head = tempPtr;
}