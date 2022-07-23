/*
Q3.
Input:- sequence of positive integers ending with -1
      - another positive integer num that the user wishes to search for.
Output:print all the line numbers in sequence entered by the user, that contain num, 
        or a message saying that num does not show at all in the sequence.
Note: running time: theta(n)
*/

#include<iostream>
#include<vector>
using namespace std;

int* main1(int& numOfInp); //(a).heap
void main2(vector<int>& storeIntVector, int& size); //(b).vector

void printSearchInt_Array(int* inpArr, const int arrSize, int searchInt); //(a).heap
void printSearchInt_Vector(vector<int> intVector, const int arrSize, int searchInt); //(b).vector

int main(){
    //-------read and store input-------
    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End you input by typing -1."<<endl;
    
    //(a)heap
    cout<<"(a)"<<endl;
    int arrSize;
    int* inpArr = main1(arrSize);
    
    //(b)vector
    cout<<"(b)"<<endl;
    vector<int> intVector;
    int vectorSize;
    main2(intVector, vectorSize);

    //-------read a searching integer-------
    int searchInt;
    cout<<"Please enter a number you want to search."<<endl;
    cin>>searchInt;

    //-------print line# of searching int-------
    //(a)heap
    printSearchInt_Array(inpArr, arrSize, searchInt);
    delete[] inpArr;

    //(b)vector
    printSearchInt_Vector(intVector, vectorSize, searchInt);

    return 0;
}

int* main1(int& numOfInp){ //(a).heap
    bool seenEnd = false;
    int pos = 0;

    int* storeIntArr = nullptr;
    int currArrSize = 5;
    storeIntArr = new int[currArrSize];

    int currInp;
    cin>>currInp;

    while(seenEnd == false){
        if(currInp != -1){
            storeIntArr[pos++] = currInp;
            if(pos >= currArrSize){
                int* tempArr;
                tempArr = new int[currArrSize * 2]; //doubling strategy for the append operation on a dynamic array
                for(int j=0; j<currArrSize; j++){
                    tempArr[j] = storeIntArr[j];
                }
                delete []tempArr;
                currArrSize *= 2;
            }
            cin>>currInp;
        }else{
            seenEnd = true;
        }
    }
    numOfInp = pos;
    return storeIntArr;
    // delete []storeIntArr; 
}

void main2(vector<int>& storeIntVector, int& size){ //(b).vector
    int inp;
    cin>>inp;

    while(inp != -1){
        storeIntVector.push_back(inp);
        cin>>inp;
    }
    size = storeIntVector.size();
}  

void printSearchInt_Array(int* inpArr, const int arrSize, int searchInt){ //(a).heap
    cout<<"(a) "<<searchInt<<" shows in lines ";

    bool checkFirstOutput = true;
    for(int i=0; i<arrSize; i++){
        if(*(inpArr+i) == searchInt){
            if(checkFirstOutput == true){
                cout<<i+1;
                checkFirstOutput = false;
            }else{
                cout<<", "<<i+1;
            }
        }
    }
    cout<<'.'<<endl;
}

void printSearchInt_Vector(vector<int> intVector, const int arrSize, int searchInt){ //(b).vector
    cout<<"(b) "<<searchInt<<" shows in lines ";

    bool checkFirstOutput = true;
    for(int i=0; i<arrSize; i++){
        if(intVector[i] == searchInt){
            if(checkFirstOutput == true){
                cout<<i+1;
                checkFirstOutput = false;
            }else{
                cout<<", "<<i+1;
            }
        }
    }
    cout<<'.'<<endl;
}