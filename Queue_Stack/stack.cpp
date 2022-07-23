/*
Stack (LIFO)
*/

#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;

bool pairStack(ifstream& instream);
void res(bool boolRes);

int main (){
    /* file-stream */
    ifstream instream;

    /* check pair-matching */
    bool resBool = pairStack(instream);

    /* print result */
    res(resBool);

    return 0;
}


bool pairStack(ifstream& instream){
    /* open txt-file */
    instream.open("data.txt");
    if(!instream){
        cout<<"error reading file. \n";
        exit(1);
    }

    /* get entire line in a file */
    string lineStr, totalStr;
    while (getline(instream,lineStr)){
        totalStr += lineStr;
    }

    cout<<"The original line of text in the file: "<<totalStr<<endl;

    stack<char>chStack; //LIFO(last in first out)
    char ch;
    bool doSymbolsMatch = true;
    int i=8;

    while(instream >> lineStr){
        if(!(lineStr == "begin" && totalStr.substr(totalStr.length()- 4 ,3) == "end"))
            doSymbolsMatch = false;
        else{
            while(i < totalStr.length()){
                ch = totalStr[i++];
                    switch(ch){
                            case '{':
                                chStack.push(ch);
                                break;

                            case '(':
                                chStack.push(ch);
                                break;

                            case '[':
                                chStack.push(ch);
                                break;
                            /*-------------------*/
                            case '}':
                                if(chStack.empty() || chStack.top() != '{'){
                                    doSymbolsMatch = false;
                                }
                                chStack.pop(); //pop out the pair
                                break;

                            case ')':
                                if(chStack.empty() || chStack.top() != '('){
                                        doSymbolsMatch = false;
                                    }
                                chStack.pop();
                                break;

                            case ']':
                                if(chStack.empty() || chStack.top() != '['){
                                    doSymbolsMatch = false;
                                }
                                chStack.pop();
                                break;

                            default:
                                break;
                    }
                
            }
        }
    }
    return doSymbolsMatch;
    instream.close();
}

void res(bool boolRes){
    cout<<"do symbols match? -> ";
    if(boolRes == 1)
        cout<<"yes";
    else
        cout<<"no";
    cout<<endl;
}