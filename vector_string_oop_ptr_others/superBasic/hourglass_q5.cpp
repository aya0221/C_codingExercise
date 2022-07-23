/*
Question 5:
Write a program that asks the user to input a positive integer n, and prints a textual image of an
hourglass made of 2n lines with asterisks.
For example if n=4, the program should print:
*******
 *****
  ***
   *
   *
  ***
 *****
*******
*/



#include <iostream>

using namespace std;

int main()
{
    int inp;
    int n;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>inp;
    n = inp;
   
    // for loop for lines    
    for (int row = 0; row < inp; row++) { // row from 0 to 3.
        // for printing space
        for (int space = 0; space < row; space++) // space from 0 to row-1
            cout << " ";

        // for    
        for (int star = 0; star < 2*n - 1; star++) { // star from 0 to 4
            cout << "*";
        }
        cout << "\n";
        n--;
    }

    n = 1;
   // for loop for lines    
    for (int row = inp-1; row >=0; row--) { // row from 3 to 0.
        // for printing space
        for (int space = 0; space < row; space++) // space from 0 to row-1
            cout << " ";

        // for    
        for (int star = 0; star < 2*n - 1; star++) { // star from 0 to 4
            cout << "*";
        }
        cout << "\n";
        n++;
    }

    return 0;
}













// #include<iostream>
// using namespace std;

// int main(){
//     int inp;
//     int n;

//     cout<<"Please enter a positive integer: "<<endl;
//     cin>>inp;
    
//     //store the original user input value
//     n = inp;

//     //1. loop the column for hill shape triangle
//     for(int i = n; i >= 1; i++){
//         //increasing triangle - space
//         for(int j=n; j >= 1; j--){
//             cout<<" "; 
//         }
//         //decreasing triangle - *
//         for(int j = i; j < n; j++){
//             cout<<"*";
//         }
//         //decreasing triangle - *
//         for(int j = i; j <= n; j++){
//             cout<<"*";
//         }
//     }

//     //2. loop the column for mountain shape triangle.
//     for(int i = 1; i <= n; i++){
//         //decreasing triangle - space
//         for(int j = i; j <= n; j++){      ////////////////////////especially I dont understand here...
//             cout<<" ";
//         }
//         //increasing triangle - *
//         for(int j = 1; j < i; j++){
//             cout<<"*";
//         } 
//         //increasing triangle - *
//         for(int j = 1; j <= i; j++){
//             cout<<"*";
//         }
//     }

//     return 0;
// }
















// int main(){
//     int n;
//     int n;

//     cout<<"Please input a positive integer: "<<endl;
//     cin>>n;

//     n = n;
//     for(int i = 1; i <= n; i++){
//         for(int j = (n * 2) -1; j <= 1; j++){
//             if(r){

//             }
//             else{
//                 cout<<" ";
//             }
//         }
//     }
//     cout<<endl;

//     return 0;
// }
















// #include<iostream>
// #include<string>
// using namespace std;

// int main(){
//     int n;
//     int count;
//     int n;
//     int currStartsn;
//     char star = '*';
//     char space = ' ';

//     cout<<"Please inpt a positive integer: "<<endl;
//     cin>>n;

//     count = 1;
//     n = n;
//     while(n >= count){
//         count++;
//         currStartsn = (n * 2) - 1;
//         for(int i = 1; i <= currStartsn; i++){
//             cout<<star;
//         }
//         cout<<endl;

//         // cout<<" ";
//         n -= 1;
//     }

//     count = 1;
//     n = 1;
//     while(n >= count){
//         count++;
//         currStartsn = (n * 2) - 1;
//         for(int i = 1; i <= currStartsn; i++){
//             cout<<star;
//         }
//         cout<<endl;
//         cout<<" ";
//         n += 1;
//     }
//     cout<<endl;
//     return 0;
// }
