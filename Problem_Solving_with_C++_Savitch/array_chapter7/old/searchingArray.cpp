/*
Searches a partially filled array of nonnegative integers.
*/

#include<iostream>
using namespace std;

const int DECLARED_SIZE = 20;

//----------------
void fillArray(int a[], int size, int& numberUsed);
int search(const int a[], int numberUsed, int target);
//----------------

int main (){
    using namespace std;

    int arr[DECLARED_SIZE];
    int listSize, target;
    
    char ans;
    int result;

    fillArray(arr, DECLARED_SIZE, listSize);

    do{
        cout<< "Enter a number to search for: ";
        cin>> target;

        result = search(arr,listSize, target);  //call "search" function and assign the value in result variable
        if(result == -1){
            cout<<target<<" is not on the list.\n";
        }else{
            cout<<target<<" is stored in array position "
                <<result<<endl
                <<" noted that the first position is 0.\n";
        }

        cout<<"search agian?(y/n followd by Return): ";
        cin>>ans;
    }while((ans != 'n') && (ans != 'N'));

    cout<<endl;
    return 0;
}


void fillArray(int a[], int size, int& numberUsed){
    int inp;
    cin >> inp;

    int index = 0;
    while((index < size) && (inp >= 0)){
        a[index] = inp;
        index++;
        cin >> inp;
    }
    numberUsed = index +1; //the last index# + 1
}

int search(const int a[], int numberUsed, int target){
    bool found = false; //initialize the flag down
    int index = 0;

    while((!found) && (index < numberUsed)){
        if(target == a[index]){
            found = true;    //assign "true" in flag = get out of this loop 
        }else{
            index++;
        }
    }
    if(found){  //get out of the loop
        return index;   //return the last index evaluated in while loop
    }else{
        return -1;
    }
}