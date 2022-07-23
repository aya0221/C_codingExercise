#include<iostream>
#include<vector>
using namespace std;

//CLASS TO ORGANIZE BST
template<class T>
class BST{
    public:
        //VALUE FOR THE NODE
        T val;

        //NODE PTR FOR LEFT AND RIGHT
        BST<T>* left;
        BST<T>* right;
        
        //CONSTRUCTOR 
        BST(const T& value = T(), BST<T>* left = nullptr, BST<T>* right = nullptr) //(default ptr:nullptr)
            : val(value), left(left), right(right){}
        
};


//FUNCTION TO COMARE IF ELEMENTS IN VECTOR AND BST ARE THE SAME
bool compare(const vector<int>& vec, BST<int>* rootNode, int start, int end){ //const:value cant be modified, &:pass by reference
    //BASE CASE (TERMINATE CASE)
    if(rootNode == nullptr){
        return true; //successfuly reach over the root node
    }

    //RECURSIVE CASE
        //DEVIDE INTO HALF
        int mid = (start + end) / 2;

        //CHECK MATCHING
        if(vec[mid] == rootNode->val){

            //LEFT TREE
            return compare(vec, rootNode->left, start, mid-1);  //need to RETURN bool

            //RIGHT TREE
            return compare(vec, rootNode->right, mid+1, end);

        }else{
            return false;
        }
}


int main(){
    //ELEMENTS: 7

    //1. -----CREATE VOCTOR
    vector<int>vec = {1, 3, 5, 7, 9, 11, 13};

    //2. -----CREATE BST
        // -- CREATE ROOT NODE
        BST<int>* rootNode = new BST<int>(7, //Root Node
            // -- CRATE LEFT NODE
            new BST<int>(3, //First Left Node (PTR)
                new BST<int>(1), // Left node of the First Left Node (PTR)
                new BST<int>(5)  //Right node of the First Left Node (PTR)
            ),
            // -- CRATE RIGHT NODE
            new BST<int>(11,//First Right Node
                new BST<int>(9), //Left node of the first right node
                new BST<int>(13) //Right node of the first right node
            )
        );

    //3. -----COMPARE / RESULT
        //PASS VECTOR, ROOT PTR
        bool res = compare(vec, rootNode, 0, vec.size());

    //4. print result
    if(res == 1){
        cout<<"matching\n";
    }else{
        cout<<"NOT motching\n";
    }

    return 0;
}