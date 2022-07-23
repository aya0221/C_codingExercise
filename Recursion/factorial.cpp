#include<iostream>
using namespace std;

int factorial(int n){
    if(n <= 1){
        return n;
    }else{
        int previewResult;
        previewResult = factorial(n-1);
        return n * previewResult;
    }
}

int main(){
    cout<<factorial(5);
    return 0;
}