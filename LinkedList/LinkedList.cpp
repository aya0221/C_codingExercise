#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;


//NODE
template<class T, typename I, typename D, typename S>
class Employee{
    public:
        // --LIST CLASS (FRIEND)--
        template<T, I, D, S> friend class LinkedList;

        // --CONSTRUCTOR--
        Employee(){};
        Employee(int newID, double newWorkH, string newName);

        // --ACCESSORS--
        int getID()const{return id;}
        double getWorkH()const{return workH;}
        string getName()const{return name;}


        // --MEMBER VARIABLES--
        int id;
        double workH;
        string name;

        Employee<T, I, D, S>* next;  //pointer to the next node
};
template<class T, typename I, typename D, typename S>
Employee<T, I, D, S>::Employee(int newID, double newWorkH, string newName):id(newID), workH(newWorkH), name(newName){}



template<class T, typename I, typename D, typename S>
class LinkedList{
    public:
        // --INITIALIZE--
        LinkedList(){nodePtr = NULL; headPtr = NULL; tempPtr = NULL;}

        // --BIG 3--
        LinkedList(const LinkedList<T, I, D, S>& copy);
        ~LinkedList<T, I, D, S>(){clear();}

        // --ACCESSOTRS--
        void insertAtHead(int newID, double newWorkH, string newName);
        void insertAtEnd(I newID, D newWorkH, S newName);
        // void insertAtEnd(int newID, double newWorkH, string newName);
        bool isEmpty(){return headPtr == nullptr;}
        void clear();

    private:
        // --NODE POINTERS-- (these node-pointers can point to another node)
        Employee<T, int, double, string>* nodePtr;
        Employee<T, int, double, string>* headPtr;  //begining of the list
        Employee<T, int, double, string>* tempPtr;
};

template<class T, typename I, typename D, typename S>
LinkedList<T, I, D, S>::LinkedList(const LinkedList<T, I, D, S>& copy){
    if(copy.empty()){
        nodePtr = headPtr = tempPtr = NULL;
    }else{
        tempPtr = copy.headPtr; //moves through the nodes from front to back of copy

        nodePtr = new Employee<T, int, double, string>;
        nodePtr->id = tempPtr->id;
        nodePtr->workH = tempPtr->workH;
        nodePtr->name = tempPtr->name;
        nodePtr->next = NULL;
        headPtr = nodePtr;

        tempPtr = tempPtr->next;  //now it points to second node

        while(tempPtr != NULL){
            nodePtr = new Employee<T, int, double, string>;
            nodePtr->id = tempPtr->id;
            nodePtr->workH = tempPtr->workH;
            nodePtr->name = tempPtr->name;
            nodePtr->next = NULL;
            tempPtr = tempPtr->next;
        }
    }
}

template<class T, typename I, typename D, typename S>
void LinkedList<T, I, D, S>::insertAtHead(int newID, double newWorkH, string newName){
    //-- create new node (nodePtr points to the newly created node)
    nodePtr = new Employee<T, int, double, string>;
    //--fillup the data-part of the node
    nodePtr->id = newID;
    nodePtr->workH = newWorkH,
    nodePtr->name = newName;
    // -- head/tempPtr points to the same thing as nodePtr is pointing to
    tempPtr = nodePtr;//this will move later
    headPtr = nodePtr;//this will not be changed
    // --terminate--
    nodePtr->next = NULL;
}

template<class T, typename I, typename D, typename S>
void LinkedList<T, I, D, S>::insertAtEnd(I newID, D newWorkH, S newName){
    if(isEmpty()){
        // insertAtHead(newID, newWorkH, newName, newNext);
        insertAtHead(newID, newWorkH, newName);
    }

    //--create new(additional) node--
    nodePtr = new Employee<T, int, double, string>; //at this points, n points to the new node
    //--fillup the data-part of the node
    nodePtr->id = newID;
    nodePtr->workH = newWorkH,
    nodePtr->name = newName;
    // -- LINK TOGTHER --
    tempPtr->next = nodePtr; //concatinate - look at the node that tempPtr is pointing to, and access the "next" data member inside the node, and make it points to whatever nodePtr is pointing to
    tempPtr = tempPtr->next;  //moves tempPtr to what t->next is pointing to. here, nodePtr and tempPtr point to the same thing
    // --terminate--
    nodePtr->next = NULL;
}

template<class T, typename I, typename D, typename S>
void LinkedList<T, I, D, S>::clear(){
    if(isEmpty()){
        cout<<"there is no elements in a list.\n";
        exit(1);
    }
    while(!isEmpty()){
        Employee<T, int, double, string>* discard = headPtr;
        headPtr = headPtr->next;    //removing the first node to the right
        if(headPtr == NULL){
            cout<<"done removing the last elements from a list\n";
            nodePtr = NULL;
            tempPtr = NULL;
            exit(1);
        }
        delete discard; //deleting the first node
    }
}

void FileReadWrite(ifstream& instream, ofstream& outstream);


int main(){
    LinkedList<int, int,  double,  string>temp; //############# what is T ?! (T store a few variables with different types...)
                    // LinkedList<int>objInt;
                    // LinkedList<double>objDouble;
                    // LinkedList<string>objString;
    temp.insertAtEnd(3, 2.5, "john hopp");


    char ch;
    do{
            // -- READ FROM FILE and STORE INTO THE LIST --
        ifstream instream;
        ofstream outstream;

        FileReadWrite(instream, outstream);


        cout<<"would you like to read another file? (y or n):\n";
        cin >> ch;
    }while(ch != 'n');
    
    return 0;
}

template<class T, typename I, typename D, typename S>
void FileReadWrite(ifstream& instream, ofstream& outstream){
    // --OPEN INP-FILE
    cout<<"enter a file name:";
    string thisFileName;
    cin >> thisFileName;
    instream.open(thisFileName);
    while(!instream){
        cout<<"failed. input file name again:";
        cin >> thisFileName;
        instream.clear();
        instream.open(thisFileName);
    }

    // -- OPEN OUT-FILE
    int id;
    double workH;
    string name;
    outstream.open("out.txt");
    while(instream >> id){
        instream >> workH;
        instream.ignore(5, ' ');   //ignore the space between first and last name
        getline(instream, name);
        outstream << id << ' ' <<workH << ' ' << name <<endl;
    }
    LinkedList<T, I, D, S> temp;
    temp.insertAtEnd(id, workH, name); //store into Linked List

    instream.close();
    outstream.close();
}