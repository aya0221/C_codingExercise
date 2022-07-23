#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* link;
};

typedef Node* NodePtr;

class List{
    public:
        List();
        List(const List& copy);
        ~List();

        void add(char ch);  //item has been added to the back of the queus
        char remove();
        bool empty()const;

    private:
        NodePtr front;  //points to the head of a linked list. iteams are removed at the head
        NodePtr back;   //points to the node at the other end of the linked list. items are added at this end.
};

List::List():front(NULL), back(NULL){}
List::List(const List& copy){
    if(copy.empty()){
        front = back = NULL;
    }else{
        NodePtr tempPtrOld = copy.front; //moves through the nodes from front to back of copy
        NodePtr tempPtrNew; //to create a new node

        back = new Node;
        back->data = tempPtrOld->data;
        back->link = NULL;
        front = back;

        tempPtrOld = tempPtrOld->link;  //now it points to second node

        while(tempPtrOld != NULL){
            tempPtrNew = new Node;
            tempPtrNew->data = tempPtrOld->data;
            tempPtrNew->link = NULL;
            back->link = tempPtrNew;
            back = tempPtrNew;  //why???
            tempPtrOld = tempPtrOld->link;
        }
    }
}
List::~List(){
    char next;
    while(!empty()){
        next = remove();
    }
}

bool List::empty()const{return(back == NULL);}
void List::add(char ch){
    if(empty()){
        front = new Node;
        front->data = ch;
        front->link = NULL;
        back = front;
    }else{
        NodePtr tempPtr = new Node;
        tempPtr->data = ch;
        tempPtr->link = NULL;
        back->link = tempPtr;
        back = tempPtr;
    }
}

char List::remove(){
    if(empty()){
        cout<<"error...removing an item from an empty queue.\n";
        exit(1);
    }
    char result = front->data;

    NodePtr discard = front;
    front = front->link;    //new front(removing the first node)
    if(front == NULL)   //if we removed the last node (if the link to the curr node is empty)
        back = NULL;
    delete discard;
    return result;

}



int main(){
    List listObj;
    char next, ans;

    do{
        cout<<"enter a word:";
        cin.get(next);
        while(next != '\n'){
            listObj.add(next);
            cin.get(next);
        }

        cout<<"you entered:";
        while(!listObj.empty())
            cout<<listObj.remove();
        cout<<endl;

        cout<<"again?(y / n)";
        cin >> ans;
        cin.ignore(1000, '\n');
    }while(ans != '\n');

    return 0;
}