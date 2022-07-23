/*
13. 
*/

#include<iostream>
using namespace std;

const int RANGE_NUM = 5;

void one_more(int arr[], int range);
void print(int arr[], int range);

int main(){

    int updateValue[RANGE_NUM] = {1,2,3,4,5};

    one_more(updateValue, RANGE_NUM);

    print(updateValue, RANGE_NUM);
    

    return 0;
}

void one_more(int arr[], int range)
{
    for(int index = 0; index < RANGE_NUM; index++)
    {
        arr[index] += 1;
    }
}

void print(int arr[], int range)
{
    for(int index = 0; index < range; index++)
    {
        cout << arr[index] << endl;
    }
}

