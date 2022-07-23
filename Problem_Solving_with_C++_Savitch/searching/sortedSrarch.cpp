/*
running time of Binary Search: T(n) = theta(log n) ... Logarithmic
        (cutting half!!)
*/
#include<iostream>
using namespace std;

int sortedSrarch(int srtArr[], int srtArrSize, int val);

int main(){
    int srtArr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout<<sortedSrarch(srtArr, 10, 13)<<endl;
    return 0;
}


int sortedSrarch(int srtArr[], int srtArrSize, int val){
    int low, high, mid;
    bool found;
    int ind;

    low = 0;
    high = srtArrSize - 1;
    found = false;

    while(found == false && (low <= high)){
        mid = (low + high) /2;
        if(srtArr[mid] == val){
            ind = mid;
            found = true;
        }else if(val <srtArr[mid]){
            high = mid-1;
        }else{  //val > srtArr[mid]
            low = mid + 1;
        }
    }
    if(found == true){
        return ind;
    }else{
        return -1;
    }
}