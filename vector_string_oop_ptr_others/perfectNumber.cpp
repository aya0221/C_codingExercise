/*
output:
- All the perfect numbers between 2 and M
- All pairs of amicable numbers that are between 2 and M
*/

#include <iostream>
#include <cmath>
using namespace std;

void printPerfect(int num);
//print all the perfect numbers between 2 and M

void printAmicable(int num);
//print all pairs of amicable numbers that are between 2 and M

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);  //(a)
//get the sum and the number of perfect divisors of num

bool isPerfect(int num);    //(b)
//check if num is perfect number or not

int main() {
    int num;

    cout<< "Enter a positive integer M (>= 2): ";
    cin>>num;
    cout<<"All the perfect numbers between 2 and M: \n";
    printPerfect(num);  //print all perfect numbers
    
    cout<<"\nAll pairs of amicable numbers that are between 2 and M:\n";
    printAmicable(num); //print all pairs of amicable numbers

    cout<<endl;
    return 0;
}

void printPerfect(int num){
    for(int i = 2; i < num; i++) {  //1 is not included
        if(isPerfect(i)) {  
            cout<<i<<endl;
        }
    }
}

bool isPerfect(int num) {
    int outCountDivs, outSumDivs;

    analyzeDivisors(num, outCountDivs, outSumDivs);
    return outSumDivs == num;   //num is perfect number if num is equal to the sum of its proper divisors
}

// running time: Θ√n
void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    int sqrt = pow(num, 0.5), countDivs = 1 , sumDivs = 1;  //search(loop) only half  -- Θ√n

    for(int i = 2; i <= sqrt; i++) {
        if(num % i == 0) {  //getting proper divisors
            if(num/i != i){
                countDivs += 2;
                sumDivs += (i + num / i);
            }else{
                countDivs++;    //around middle num could be the same number
                sumDivs += i;
            }
        }
    }
    outCountDivs = countDivs;   //these values will be refered in another function
    outSumDivs = sumDivs;
}

void printAmicable(int num){    //(c)
    int numOfAmicable = 0;
    for(int i = 2; i <= num; i++) {    //compare two perfect numbers which should be next each other
        int count1, sum1;   
        int count2, sum2;

        analyzeDivisors(i, count1, sum1);   //first, use "i" to get the sum of its proper divisors
        analyzeDivisors(sum1, count2, sum2);    //second, get the sum of "the sum of i's proper divisors"

        if((i == sum2) && (i < sum1)) { //compare i-value is the sum of the proper divisors of the next value of i
            cout << '{' << i << ", " << sum1 << "}\n";
            numOfAmicable++;
        }
    }
    if(numOfAmicable == 0){ //if there is no pairs of amicable numbers
        cout<<"There are not pairs of amicable numbers in the range.\n";
    }
}