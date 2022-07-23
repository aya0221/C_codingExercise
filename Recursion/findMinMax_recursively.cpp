/*
divide-and-conquer algorithm for finding the maximum and minimum:
    split the input into two halves
    Recursively find the maximum and minimum of each half
    In two additional comparisons produce the maximum and minimum for the entire problem.
*/

#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

class Generator{
    public:
        //  CONSTRUCTOR (create new vector / initialize result vector)
        Generator(int numOfElements);   
        
        //  RECURSIVE FUNCTION
        vector<int> findMinMax(vector<int>& vec, int left, int right);

        // ACCESSOR / print
        void printArr();
        int getNumOfElements(){return this->numOfElements;};

        // VECTORS
        vector<int> vecInClass; //original vector (containing all elements)
        vector<int>resVec;  //result vector (0:min 1:max)
    
    private:
        int numOfElements;  //given by user
};

Generator::Generator(int num)   //given the number of elements by user
: numOfElements(num)
{
    srand(time(NULL));
    int min, max;
    for(int i=0; i<num; i++){
        int num = rand() % 50 + 1;
        vecInClass.push_back(num);  //store into orriginal array
    }
    printArr(); //print original array

    //Initialize the result vector
    resVec.push_back(0);
    resVec.push_back(1);
}

void Generator::printArr(){
    cout<<"The original vector contains { ";
    for(int i=0; i<getNumOfElements(); i++){
        cout<<vecInClass[i]<<" ";
    }
    cout<<"}"<<endl;
}

vector<int> Generator::findMinMax(vector<int>& vec, int left, int right){

    // //BASE
    if(left == right){
        resVec[0] = vec[left];
        resVec[1] = vec[left];
    }else if(left == right - 1){
        if(vec[left] < vec[right]){
            resVec[0] = vec[left];
            resVec[1] = vec[right];
        }else{
            resVec[0] = vec[right];
            resVec[1] = vec[left];
        }
    }

    // RECURSIVE CASE
    if(left < right){
        int middle = (left + right) / 2;
        int lowLeft = left;
        int highLeft = middle;
        int lowRight = middle+1;
        int highRight = right;

        // RECURSIVE CALL
        vector<int> leftVecTmp = findMinMax(vec, lowLeft, highLeft);   //LEFT
        vector<int> rightVecTmp = findMinMax(vec, lowRight, highRight);   //RIGHT

        //COMPARISON between left and right values
            //MIN
        if(leftVecTmp[0] < rightVecTmp[0])
            resVec[0] = leftVecTmp[0];
        else
            resVec[0] = rightVecTmp[0];
            //MAX
        if(leftVecTmp[1] < rightVecTmp[1])
            resVec[1] = rightVecTmp[1];
        else
            resVec[1] = leftVecTmp[1];
    }
    return resVec;  //returning the vector which only contains two elements(min and max)
}


int main(){
    
    Generator classObj(8);    //create a vector containing (#) random elements
    
    vector<int>resVec(2,0);
    resVec = classObj.findMinMax(classObj.vecInClass, 0, classObj.getNumOfElements() -1);

    cout<<"The min value is "<<resVec[0]<<", and the max value is "<<resVec[1]<<'.'<<endl;

    return 0;
}