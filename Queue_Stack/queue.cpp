/*
Queues (FIFO)
*/

#include<iostream>
#include<queue>
#include<time.h>
#include<vector>
using namespace std;


class QueVec{
    public:
        QueVec(){};   //default constructor (base class need to have a default constructor)
        QueVec(int x); //initialize QueVector
        ~QueVec();

        void copy_Que_to_vec();
        void removeFromVec();

        vector<int>vec; 
        queue<int> q;//queue initialized by constructor

        int front = 0;
        int back = -1;
};

QueVec::QueVec(int x){
    srand(time(NULL));

    cout<<"the contents of queue:\n";
    for(int i=0; i<x; i++){
        int num = rand()% 10;
        cout<<num<<" ";
        q.push(num);
    }
    cout<<endl;
}
QueVec::~QueVec(){
    if(front > back)
        vec.clear();
}

void QueVec::copy_Que_to_vec(){
    while(!(q.empty())){
        vec.push_back(q.front());
        back++;
        q.pop();
    }
}

void QueVec::removeFromVec(){
    int i = 0;
    while(vec.size() > 0){
        int remove = vec.front();  
        cout<<"removed "<<remove<<" from a vector \n";
        vec.erase(vec.begin());
    }
}



int main(){
    QueVec QueVecObj(10);  // Queue will be initialized by a constructor

    QueVecObj.copy_Que_to_vec();
    QueVecObj.removeFromVec();

    return 0;
}