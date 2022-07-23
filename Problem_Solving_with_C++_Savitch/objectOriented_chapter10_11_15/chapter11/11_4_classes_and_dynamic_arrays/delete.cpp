#include<iostream>

using namespace std;


class BaseClass{
    private:
        int baseVariable;
        
    public:
        int getBaseVar() const {return baseVariable;}
};

class DerivedClass : public BaseClass{
    private:
        int derivedVariable;
    
    public:
        DerivedClass& operator=(const BaseClass& baseTemp){
            derivedVariable = baseTemp.getBaseVar();
        }
};