
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){


cout << "*" << setw(5) << 123 << "*" << 123 << "*" << endl;
cout.setf(ios::showpos); 
cout << "*" << setw(5) << 123 << "*" << 123 << "*" << endl;
cout.unsetf(ios::showpos);
cout.setf(ios::left);
cout << "*" << setw(5) << 123 << "*" << setw(5) << 123 << "*" << endl;

return 0;
}


/*  OUTPUT

*  123*123*
* +123*+123*
*123  *123  *

*/