#include<iostream>
using namespace std;

struct Score{
    int homeTeam;
    int opponent;
};
Score game[10];

int main(){
    
    int val;
    for(int i; i<10; i++){
        cin >> game[i].homeTeam;
    }
    for(int i; i<10; i++){
        cout << game[i].homeTeam <<endl;
    }


    return 0;
}