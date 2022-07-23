/*
function to locate a node in a linked list

*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *link;
};

typedef Node* NodePtr;

NodePtr search(NodePtr head, int target);

int main(){
    return 0;
}



NodePtr search(NodePtr head, int target){
    NodePtr here = head;


//----------------
    if(here == NULL){//empty
        return NULL;
    }else{
        while(here->data != target && here->link != NULL){
            here = here->link;
        }

        if(here->data == target){
            return here;
        }else{
            return NULL;
        }
    }
//----------------
//USING FOR LOOP
Node* iter;
for(iter = head; iter!= NULL; iter = iter->link){
    cout <<(iter->data)<<endl;
}




}