/*
1. 
can I write "using namespace std" before starting main function?(as global declaration)
so that I do not have to worry about it later?
I have seen some codes metion it only in a main function...

2.

getTotal(a[plantNumber-1]); 
*/

/*
Reads data and displays a bar graph showing productivity for each plant.
*/

#include<iostream>
#include<cmath>

const int NUMBER_OF_PLANTS = 4;

//function declaration-----------------------------------------------------------------------------
void inputData(int a[], int lastPlantNumber);

void getTotal(int& sum);

void scale(int a[], int size);

void graph(const int asteriskCount[], int lastPlantNumber);


int roundNum(double number);

void printAsterisks(int n);
//-----------------------------------------------------------------------------

int main(){
    using namespace std;

    int production[NUMBER_OF_PLANTS];
    
    cout << "This program displays a graph showing\n"
        << "production for each plant in the company.\n";
    
    //call functions----------------
    inputData(production, NUMBER_OF_PLANTS);

    scale(production, NUMBER_OF_PLANTS);

    graph(production, NUMBER_OF_PLANTS);
    //----------------

    cout << endl;
    return 0;
}

//INPUT / SUMUP / STORE THE VALUE IN ARRAY---------------

void inputData(int a[], int lastPlantNumber)  //cout, call/use "getTotal" function
{
    using namespace std;

    for(int plantNumber = 1; plantNumber <= lastPlantNumber; plantNumber++)
    {
        cout << endl
             << "Enter production data for plant number " << plantNumber <<endl;
        
        getTotal(a[plantNumber-1]);   //argument: INDEXED VARIABLE 
    }
}

void getTotal(int& sum)  //sum:INDEXED VARIABLE    //cin and sum the data
{
    using namespace std;
    sum = 0;
    int next;

    cout << "Enter number of units produced by each department.\n"
         << "Append a negative number to the end of the list.\n";
    
    cin >> next;  //cin the first input

    while(next >= 0)
    {
        sum += next;
        cin >> next;
    }

    cout << "Total = " << sum << endl;
}

//DIVIDE the value of a[index] by 1000 and ROUND the result to the nearest whole number---------------
void scale(int a[], int size)
{
    for(int index = 0; index < size; index++)
    {
        a[index]= roundNum(a[index] / 1000);  //!! assign the NEW VALUE in a[index]
    }
}

int roundNum(double number)
{
    using namespace std;
    return static_cast<int>(floor(number + 0.5));   //round
}

//COUT "*"---------------
void graph(const int asteriskCount[], int lastPlantNumber)
{
    using namespace std;

    cout << "\nUnits produced in thousands of units:\n";

    for(int plantNumber = 1; plantNumber <= lastPlantNumber; plantNumber++)
    {
        cout << "Plant #" << plantNumber << " ";
        printAsterisks(asteriskCount[plantNumber -1]); //pass the argument (indexed value)
        cout << endl;
    }
}

void printAsterisks(int n) //n:value of each index
{
    using namespace std;

    for(int count = 1; count <= n; count++)
    {
        cout << "*";
    }
}