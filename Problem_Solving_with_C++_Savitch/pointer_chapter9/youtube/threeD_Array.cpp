/*

int[i][j][k]
i two such
j j rows
k k columns

*/
#include<iostream>
using namespace std;

//
void oneD(int one[]);
void twoD(int two[][2]);
void multi_D(int multi[][3][2]);


int main(){
    // int multiD[3][2][2] = {{{2,5}, {7,9}},
    //                        {{1,3}, {5,8}},
    //                        {{7,4}, {6,1}}};
    // //print the ADDRESS (pointer) of the first element of the first 1D of the first 2D
    // cout<< multiD <<endl;
    // cout<< *multiD <<endl;
    // cout<< **multiD <<endl;
    // cout<< &multiD[0][0] <<endl;
    // cout<< &multiD[0][0][0] <<endl;
    // cout<< multiD[0] <<endl;
    // cout<< multiD[0][0] <<endl;

    // //print VALUE
    // cout<< *(multiD[0][1]+1) <<endl;    //print 9
    // cout<< multiD[0][1]+1 <<endl;    //print 9



    //FUNCTION------------------
    int single[3] = {1, 2, 3};
    oneD(single);

    int two[2][2] = {{1, 2},
                    {3, 4}};
    twoD(two);

    int multi[2][3][2] = {{{1, 2}, {3, 4}, {5, 6}},
                        {{7, 8}, {9, 10}, {11, 12}}};
    multi_D(multi);

    return 0;
}

void oneD(int one[]){
    for(int i=0; i<3; i++){
        cout<<one[i]<<", ";
    }
    cout<<endl<<endl;
}
void twoD(int two[][2]){
    for(int i=0; i<2; i++){ //row
        for(int j=0; j<2; j++){  //column
            cout<<two[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void multi_D(int multi[][3][2]){
    for(int i=0; i<2; i++){ //3D(2 set of)
        for(int j=0; j<3; j++){ //row
            for(int k=0; k<2; k++){ //column
                cout<<multi[i][j][k]<<", ";
            }
            cout<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
}
