//the pointer calue NULL is used to indicate anempty list


#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    double data;
    Node* next;
};

typedef Node* Pointer;

int main(){
    Pointer p1, p2;

    //7. points to the next node on this linked list
    p1 = p1->next;

    //8. delete the node after the node pointed to by p2
    Pointer discard;
    discard = p2->next;
    delete discard;


    return 0;
}
