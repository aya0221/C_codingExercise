#include<iostream>
using namespace std;

class Vec2{
    public:
        int x, y;
        Vec2(int takenX, int takenY) : x(takenX), y(takenY) {}

        //---------  [ + - * / ]  ----------------------------------------------------------------------------------------------
        Vec2 operator+(const Vec2& givenVal) const{
            return Add(givenVal);
        }
        Vec2 Add(const Vec2& passedVal) const{    //CONST REFERENCE to avoid copying, mark the function as CONST because its not going to modify this class, but just create the new Vec2 with result
            return Vec2(x + passedVal.x , y + passedVal.y);
        }

        //----
        Vec2 operator*(const Vec2& givenVal) const{
            return Multiply(givenVal);
        }
        Vec2 Multiply(const Vec2& passedVal) const{    //CONST REFERENCE to avoid copying, mark the function as CONST because its not going to modify this class, but just create the new Vec2 with result
            return Vec2(x + passedVal.x , y + passedVal.y);
        }

        //---------  [ == ]  ----------------------------------------------------------------------------------------------
        bool operator==(const Vec2& other) const {
            // return x == other.x && y == other.y;
            return *this == other;
        }
        //----
        bool operator!=(const Vec2& other) const {
            // return x != other.x && y != other.y;
            return !(*this == other);
        }
};
};


//---------  [ << >> outside of class ]  ----------------------------------------------------------------------------------------------
ostream& operator<<(ostream& stream, const Vec2& other){
    stream << other.x <<endl;
    return stream;
}




int main(){
    Vec2 obj1(2, 4);
    Vec2 obj2(3, 5);
    Vec2 obj3(10, 100);

    Vec2 result1 = obj1 + obj2 * obj3;
    cout << result1 <<endl;

    Vec2 result2 = obj1 + obj2 * obj3;
    if(result1 == result2)
        cout <<"its same values!" <<endl;

    return 0;
}