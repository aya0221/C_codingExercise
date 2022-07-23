//p796
/*
QUESTIONS

    typedef Node* NodePtr;
        ->Is it okay not to define this, and simply use "Node* " to create pointer obj in other functions?
    
    void headInsert(NodePtr& head, int theNumber){ 
        -> "&" ? head is a pointer variable, so the value will be passed without being referenced right?     

    private:
        Node *link;
            ->Is this automatically set as the "next node" when constructor is called? (memory address next to the head?) 


*/



#include<iostream>
#include<fstream>
using namespace std;

class Node{
    public:
        Node();
        Node(int value, Node *next);
        //constructor to initialize a node

        int getData()const;
        //retrieve value for this node

        Node *getLink()const;
        //retrieve next node in the list

        void setData(int value);

        void setLink(Node *next);
        //use to change the reference to the next node

    private:
        int data;
        Node *link; //is this automatically set as the "next node"? (memory address next to the head?)
};

    //-- 
typedef Node* NodePtr;

    //-- constructor
Node::Node():data(0), link(NULL){}
Node::Node(int value, Node* next):data(value), link(next){}

    //-- accessor and mutator methods for Node-class
int Node::getData()const{return data;}
Node *Node::getLink()const{return link;}
void Node::setData(int value){data = value;}
void Node::setLink(Node *next){link = next;}

 

    //-- function to insert a new node onto the head of the list
void headInsert(NodePtr& head, int theNumber){  
   NodePtr tempPtr; //can we write "Node* tempPtr" ??
   tempPtr = new Node(theNumber, head);
   head = tempPtr; 
}

int main(){
    NodePtr head, tmp;

    //--CREATE A LIST OF NODES 4->3->2->1->0
    head = new Node(0, NULL);
    for(int i=1; i<5; i++){
        headInsert(head, i);
    }

    //--ITERATE THROUGH THE LIST AND DISPLAY EACH VALUE
    tmp = head;
    while(tmp!= NULL){
        cout<<tmp->getData()<<endl;
        tmp = tmp->getLink();   //get next link
    }

    //--DELETE ALL NODES IN THE LIST BEFORE EXITING

    tmp = head;
    while(tmp!= NULL){
        NodePtr nodeToDelete = tmp;
        tmp = tmp->getLink();
        delete nodeToDelete;
    }
    return 0;
}