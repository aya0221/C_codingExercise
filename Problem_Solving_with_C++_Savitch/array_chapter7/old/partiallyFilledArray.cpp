/*
QUESTION

fillArray(score, MAX_NUMBER_SCORES, numberUsed);   //passing [MAX_NUMBER_SCORES]???
*/

#include<iostream>

const int MAX_NUMBER_SCORES = 10;

//----------------------------
void fillArray(int a[], int size, int& numberUsed);

double computeAverage(const int a[], int numberUsed);

void showDifference(const int a[], int numberUsed);
//----------------------------

int main (){
    using namespace std;

    int score[MAX_NUMBER_SCORES];
    int numberUsed;

    cout<< "This program reads golf scores and shows\n"
        << "how much each differs from the average.\n"
        << "Enter golf scores:\n";

        fillArray(score, MAX_NUMBER_SCORES, numberUsed);   //passing [MAX_NUMBER_SCORES]???

        showDifference(score, numberUsed); //using the referenced(updated) value in numberUsed

    return 0;
}

void fillArray(int a[], int size, int& numberUsed){
    using namespace std;
    
    int next;
    int index = 0;

    cout<< "Enter up to " << size << " nonnegative whole numbers.\n"
        << "Make the end of the list with a negative number. \n";

    cin >> next;
    while((next >= 0) && (index < size)){
        a[index] = next;
        index++;
        cin >> next;
    }
    numberUsed = index;
}

double computeAverage(const int a[], int numberUsed){
    double total = 0;

    for(int index =0; index < numberUsed; index++){
        total += a[index];
    }

    if(numberUsed > 0){
        return (total / numberUsed);
    }else{
        using namespace std;
        cout<< "ERROR. conputeAverage returns 0.\n";
        return 0;
    }
}

void showDifference(const int a[], int numberUsed){
    using namespace std;

    double average = computeAverage(a, numberUsed);   //call the previous return-function

    cout<< "Average of the " << numberUsed << " scores = "
        <<average<<endl
        << "The scores are:\n";

        for(int index = 0; index < numberUsed; index++){
            cout<< a[index]
                << " differs from averager by "
                << (a[index] - average) << endl;
        }
}

