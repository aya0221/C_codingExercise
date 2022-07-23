#include<iostram>
//vector does not have a fixed size


#include<vector>
using namespace std;

vector<int> v = {1, 2, 3};
//declare a variable v for a vector

v.push_back(5);
//add 5 at the next avilable position

v.size();
//#of elements in vector

v.capacity();
//#of elements which there is memory allocated

v.resize(25);
//resize vector to 25

v.reserve(v.size() + 10);
//reserve the capacity of the vector as the size of vector + 10

// unsigned int  : non negative integer

///////////////////////

vector<int> v(5);
for(unsigned int i=0; i<v.size(); i++){
    v[i] = i;
}
//is equivalent to 
for(auto i : v){
    cout<<i;
}

///////////////
