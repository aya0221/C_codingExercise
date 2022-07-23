#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class EnhancedQueue{
    public:
        void enqueue(int x);
        void dequeue(int x);
        int front();//get front element(assuming its int)
        bool isEmpty();//return if the queue is empty or not
        int size(); //return the size of the queue
        bool contains(int x);//return if x is in the queue
        void clear();//O(n)-clear queue

        vector<int>list;
        EnhancedQueue * next;
};
//-------------------------------------------------------------------
void EnhancedQueue::enqueue(int x){
    list.push_back(x);
}
void EnhancedQueue::dequeue(int x){
    if(isEmpty()){
        cout<<"the queue is already empty"<<endl;
        exit(1);
    }

    for(int i=0; i<size(); i++){
        if(list[i] == x){
            list.pop_back();
        }
    }
    return;
}
int EnhancedQueue::front(){    //get front element(assuming its int)
    return list.front();
}

bool EnhancedQueue::isEmpty(){    //return if the queue is empty or not
    return list.empty();
}

int EnhancedQueue:: size(){//return the size of the queue
    return list.size();
} 
bool EnhancedQueue::contains(int x){    //return if x is in the queue
    if(isEmpty()){
        cout<<"the queue is already empty"<<endl;
        return 0;
    }

    for(int i=0; i<size(); i++){
        if(list[i] == x){
            return 1;
        }
    }
}
void EnhancedQueue:: clear(){    //O(n)-clear queue
    // if(!(isEmpty())){
        list.clear();
    
}
//-------------------------------------------------------------------


int main(){
    EnhancedQueue obj;
    obj.enqueue(5);//enque 5 into queue
    obj.enqueue(4);//enque 5 into queue
    obj.dequeue(4);
    cout<<obj.front()<<endl;
    obj.isEmpty();
    cout<<obj.size()<<endl;;
    obj.contains(3);
    obj.clear();

    return 0;
}