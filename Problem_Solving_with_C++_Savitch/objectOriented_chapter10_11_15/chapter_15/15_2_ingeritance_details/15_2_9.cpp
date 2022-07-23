#include<iostream>
using namespace std;

class PartFilledArray{
    public:
        PartFilledArray(int arraySize); //constructor (initializer)
        PartFilledArray(const PartFilledArray& obj);    //COPY CONSTRUCTOR
        ~PartFilledArray(); //deconstructor

        void operator =(const PartFilledArray& rhs);    //OVERLOADED ASSIGNMENT OPERATOR
        void addValue(double newEntry);

        int getMaxNum() const {return maxNumber;}
        int getNumberUsed() const {return numberUsed;}

    protected:
        double *ptrArr;
        int maxNumber;
        int numberUsed;
};

//CONSTRUCTOR
PartFilledArray::PartFilledArray(int arraySize)
:maxNumber(arraySize),
 numberUsed(0)
 {
     ptrArr = new double[maxNumber];
 }

//COPY CONSTRUCTOR
PartFilledArray::PartFilledArray(const PartFilledArray& obj)
:maxNumber(obj.maxNumber),
 numberUsed(obj.numberUsed)
{
    ptrArr = new double[maxNumber];
    // delete []ptrArr;    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! can i do this here?
    memcpy(ptrArr, obj.ptrArr, numberUsed);
}

//DECONSTRUCTOR
PartFilledArray::~PartFilledArray(){
    cout<<"this is the deconstructor!"<<endl;
    delete []ptrArr;    //heap will not be deleted automatically, so need to avoid memory leak!
}

// add value into the array
void PartFilledArray::addValue(double newEntry){
    if(numberUsed == maxNumber)  
        exit(1);
    else{
        ptrArr[numberUsed] = newEntry; //here, use OVERLOADED ASSIGNMENT OPERATOR
        numberUsed++;
    }
}

//OVERLOADED ASSIGNMENT OPERATOR

void PartFilledArray::operator =(const PartFilledArray& rhs){
    // if(rhs.maxNumber > maxNumber){  //just to make sure the the current working obj's maxNumber is appropriate, otherwise fix it
    //     delete []ptrArr;
    //     maxNumber = rhs.maxNumber;
    //     ptrArr = new double [maxNumber];
    // }
    // numberUsed = rhs.numberUsed;   //making sure
    for(int i=0; i<numberUsed; i++){    //whenever we do assignment of heap, we want DEEP COPY (create a copy into another memory address)
        ptrArr[i] = rhs.ptrArr[i];
    }
}

int main(){
    PartFilledArray obj(3);
    // PartFilledArray* obj = new PartFilledArray(3);

    obj.addValue(1.55);
    obj.addValue(2.55);

    cout<<obj.getNumberUsed()<<endl;
    cout<<obj.getMaxNum()<<endl;


    return 0;
}
