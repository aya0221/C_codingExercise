#include<iostream>
#include<string>
using namespace std;


struct Node{
    string name;
    int number;
    Node *next;
};


int main(){
    // typedef Box* BoxPtr;

    // BoxPtr head;
    Node* head = new Node();

    // head = new Box;

    head->name= "aya";

    //set the value of the member variable 'next' to this node equal to NULL
    head->next = NULL;

    //destroy the dynamic variable pointed to by head and return the memory it uses to the freestore so that 
    //it can be reused to create new dynamic variables
    delete head;

    return 0;
}
