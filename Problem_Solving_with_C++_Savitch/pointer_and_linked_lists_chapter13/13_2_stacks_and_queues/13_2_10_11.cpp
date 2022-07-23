//p805  Display 13.17
//10: definition of the member function push 
//11: copy constructor
#include<iostream>
using namespace std;

class StackFrame{
    public:
        char data;
        StackFrame *link;
};

typedef StackFrame* StackFramePtr;

class Stack{
    public:
        Stack();    //initializes the object to an empty stack
        Stack(const Stack& aStack); //COPY CONSTRUCTOR
        ~Stack();   //destroys the stack and returns all the memory to the freestore

        void push(char theSymbol);
        char pop();
        bool empty()const;
    private:
        StackFramePtr top;  //!!!!!! can I replace this to "StackFrame* top" ?? or will it be an issue?
};

Stack::Stack():top(NULL){}
Stack::Stack(const Stack& aStack){
    if(aStack.top == NULL)
        top = NULL;
    else{
        StackFramePtr startPtr = aStack.top;
        StackFramePtr endPtr = new StackFrame;
        endPtr->data = startPtr->data;
        top = endPtr;
        while(startPtr!= NULL){
            endPtr->link = new StackFrame;
            endPtr = endPtr->link;  //next node
            endPtr->data = startPtr->data;  //startPtr does not need to move to the next?!(the below line doesnt have to come first?!)
            startPtr = startPtr->link;
        }
        endPtr->link = NULL;
    }
}
Stack::~Stack(){
    char next;
    while(!empty()){
        next = pop();
    }
}
bool Stack::empty()const{return top == NULL;}
void Stack::push(char theSymbol){
    StackFramePtr tempPtr;
    tempPtr = new StackFrame;
    tempPtr->data = theSymbol;
    tempPtr->link = top;
    top = tempPtr;
}
char Stack::pop(){
    if(empty())
        cout<<"error: popping an empty stack\n";
    char result = top->data;
    StackFramePtr tempPtr;
    tempPtr = top;
    top = top->link;    //why pointing to the next link(memory address)? it shouldnt be the one before(left)?
    delete tempPtr;
    return result;
}

int main(){
    Stack s;
    char next, ans;

    do{
        cout<<"enter a word:";
        cin.get(next);
        while(next != '\n'){
            s.push(next);
            cin.get(next);
        }

        cout<<"written backword that is:";
        while(!s.empty()){
            cout<<s.pop();
            cout<<endl;
        }
        cout<<"Again?(y/n):";
        cin>>ans;
        cin.ignore(1000, '\n');
    }while(ans!= 'n' && ans!= 'N'); 
    
    return 0;
}