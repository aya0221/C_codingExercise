#include<iostream>
using namespace std;

const int MAX_LIST_SIZE = 50;

class TemperatureList{
    public:
        TemperatureList();
        void addTemperatureList(double temperature);

        bool full() const;

        friend ostream& operator <<(ostream& outs, TemperatureList& theObjectSize);
        friend bool operator <(const TemperatureList& first, const TemperatureList& second);
        
        int getSize() const;  //returns the numbe of temperatures on the list

        double getTemperature(int a);

    private:
        double list[MAX_LIST_SIZE];
        int size;

};
TemperatureList::TemperatureList()
:size(0)
{
}

void TemperatureList::addTemperatureList(double temperature){
    if(full()){
        exit(1);
    }else{
        list[size]=temperature;
        size = size + 1;
    }
}
bool TemperatureList::full() const{
    return (size == MAX_LIST_SIZE);
}

double TemperatureList::getTemperature(int a){
    if((a >= size) || (a < 0)){
        exit(1);
    }else{
        return list[a];
    }
}

int TemperatureList::getSize() const{
    return size;
}

bool operator < (const TemperatureList& first, const TemperatureList& second){
    return(first.size < second.size);
}
ostream& operator <<(ostream& outs, TemperatureList& theObjectSize){
    for(int i=0; i < theObjectSize.size; i++){
        outs << theObjectSize.list[i];
    }
    return outs;
}

int main(){

    TemperatureList temp;
    temp.addTemperatureList(21);
    cout<<temp.getTemperature(0);
    return 0;
}