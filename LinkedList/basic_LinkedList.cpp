#include<iostream>
using namespace std;

class Node{
    public:

        Node(){next = nullptr; headNode = nullptr;};
        Node(int x, string y):data(x), name(y){};
        Node(int x, string y, Node* headptr):data(x), name(y), headNode(headptr){};
        ~Node(){};

        void assignHeadNode(Node* head) {headNode = head;};

        int data;
        string name;

        Node* next;
        Node* headNode;
        friend class NodeControl;
   
};


class NodeControl{
    public:
        NodeControl(){};
        void insertIntoHead(Node** head, const int x, const string y);
};


void NodeControl::insertIntoHead(Node** head, const int x, const string y){
    Node* thisNode = new Node(x, y);
    thisNode->next = *head;
    *head = thisNode;
    Node objTmp;
    objTmp.assignHeadNode(thisNode);
}


int main(){
    Node* head, end, tmp;

    head = new Node(2, "name", head);
    NodeControl obj;
    for(int i=0; i<5; i++){
        obj.insertIntoHead(&head, i, "hi");
    }


    //delete
    Node* toBeDeleted;
    Node* tmpDelete;
    tmpDelete = head;
    while(tmpDelete != nullptr){
        toBeDeleted = tmpDelete;
        tmpDelete = tmpDelete->next;
        delete toBeDeleted;
    }

    return 0;
}