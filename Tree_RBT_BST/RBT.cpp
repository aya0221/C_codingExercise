/*
singleCCR => RR (single counterclockwise)
doubleCR => LR (double clockwise)
singleCR => LL (single closkwise)
doubleCCR => RL (double counterclockwise)
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point); //RR (single counterclockwise)
    void doubleCR(RBTNode<T> *&point); //LR (double clockwise)
    void singleCR(RBTNode<T> *&point);//LL (single closkwise)
    void doubleCCR(RBTNode<T> *&point);//RL (double counterclockwise)

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }

    void applyRule(RBTNode<T>* point);


};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {//RL
    singleCR(point->right);//LL
    singleCCR(point);//RR
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {//LR
    singleCCR(point->left);//RR
    singleCR(point);//LL
}

/* LL  - RIGHT-ROTATION  - CLOCKWISE*/
template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) { //passed GRANDPARENT_NODE

    /* 1. define GRANDPARENT, PARENT, GRANDCHILD */
    RBTNode<T> *grandparent = point;//redefine the name 
    RBTNode<T> *parent = point->left;// LL
    RBTNode<T> *grandchild = point->left->left;// LL

                // TODO: ADD "RIGHT" ROTATION CODE HERE    

    /* 2. take care of NEW_NODE's SIBLING */
    grandparent->left = parent->right; //sibling will be attached under grandparent
    if(parent->right != nullptr){
        parent->right->parent = grandparent;//grandparent's kid
    }

    /* 3. provide NEW-PARENT for PARENT */
    parent->parent = grandparent->parent;

    /* 4. check if grandparent is ROOT */
    if(grandparent->parent == nullptr){//if grandparent was already ROOT
        this->root = parent; //next root will be PARENT
    

    /* 5. make PARENT connect with GRAND-GRAND PARENT */
    }else if(grandparent == grandparent->parent->left){ //LEFT KID
        grandparent->parent->left = parent;
    
    }else if(grandparent == grandparent->parent->right){//RIGHT KID
        grandparent->parent->right = parent;
    }

    /* 6. put GRANDPARENT under the PARENT  */
    parent->right = grandparent;
    grandparent->parent = parent;
    
}



/* RR  - LEFT-ROTATION  - COUNTER_CLOCKWISE*/
template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {//RR
    /* 1. define GRANDPARENT, PARENT, GRANDCHILD */
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
        // TODO: ADD "LEFT" ROTATION CODE HERE
    RBTNode<T> *grandchild = point->right->right;

    /* 2. take care of SIBLING */
    //assign child under grandparent
    grandparent->right = parent->left;
    if(parent->left != nullptr){
        //assign PARENT
        parent->left->parent = grandparent;
    }

    /* 3.provide NEW-PARENT for PARENT */
    parent->parent = grandparent->parent;

    /* 4. check if grandparent is ROOT */
    if(grandparent->parent == nullptr){//if grandparent is already root
        this->root = parent;
    }

    /* 5. make PARENT connect with GRAND_GRAND PARENT */
    else if(grandparent == grandparent->parent->left){//left child
        grandparent->parent->left = parent;
    }
    else if(grandparent == grandparent->parent->right){//right child
        grandparent->parent->right = parent;
    }

    /* 6. put GRANDPARENT under the PARENT */
    parent->left = grandparent;
    grandparent->parent = parent;

}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
        // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        applyRule(curr_node);
    } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::applyRule(RBTNode<T> *point) {

     /* 4. IF PARENT OF NEWNODE IS RED, THEN CHECK THE COLOR OF PARENT'S SIBLING OF NEWNODE */
    while (getColor(point->parent) == RED) {
        if(point->parent == point->parent->parent->right) {

            RBTNode<T> *uncle = point->parent->parent->left;

            /* 4-1. IF PARENT's SIBLING's COLOR IS BLACK OR NULL, THEN DO ROTATION & RECOLOR */
            if((getColor(uncle) == BLACK) ||  (point->parent->parent->left == nullptr)){
                if(point == point->parent->left) {
                /* RL */
                    point = point->parent;
                    singleCR(point);
                //CHANGE COLOR 
                    swapColor(point->parent);
                    swapColor(point->parent->parent);

                /* RR */
                    singleCCR(point->parent->parent);

                }else{
                    //CHANGE COLOR 
                    swapColor(point->parent);
                    swapColor(point->parent->parent);
                    /* RR */
                    singleCCR(point->parent->parent);
                }
            /* 4-2. IF COLOR IS RED THEN RECOLOR & ALSO CHECK IF PARENT'S PARENT OF NEWNODE IS NOT ROOT NODE, THEN RECOLOR IT & RECHECK */
            }else if(getColor(uncle) == RED) {
                swapColor(point->parent);
                swapColor(uncle);
                swapColor(point->parent->parent);
                point = point->parent->parent;
            }
        }else if (point->parent == point->parent->parent->left) {

            RBTNode<T> *uncle = point->parent->parent->right;

             /* 4-1. IF PARENT's SIBLING's COLOR IS BLACK OR NULL, THEN DO ROTATION & RECOLOR */
            if((getColor(uncle) == BLACK) ||  (point->parent->parent->left == nullptr)){
                if(point == point->parent->right) {
                /* LR */        //??how to simply call double and still change the color...?!
                    point = point->parent;
                    singleCCR(point);
                    
                    //CHANGE COLOR 
                    swapColor(point->parent);
                    swapColor(point->parent->parent);

                    /* LL */
                    singleCR(point->parent->parent);
                }

                //CHANGE COLOR 
                swapColor(point->parent);
                swapColor(point->parent->parent);
                
                /* LL */
                singleCR(point->parent->parent);
            
            /* 4-2. IF COLOR IS RED THEN RECOLOR & ALSO CHECK IF PARENT'S PARENT OF NEWNODE IS NOT ROOT NODE, THEN RECOLOR IT & RECHECK */
            }else if(getColor(uncle) == RED) {
                swapColor(point->parent);
                swapColor(uncle);
                swapColor(point->parent->parent);
                point = point->parent->parent;
            }
        }
    }

    // RULE: the ROOT is always BLACK
    root->color = BLACK;
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}




// /*
// template <class T>
// void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
//     /* ==========[INSERTION RULES] ==========*/
    
//     if (point == nullptr) {               // leaf location is found so insert node

//         /* 1. IF TREE IS EMPTY, CREATE NEW-NODE AS ROOT NODE WITH COLOR:BLACK */
//         if(parent->parent == nullptr){
//             point = new RBTNode<T>(toInsert);
//             swapColor(point);//change the color to black(root)
//             return;
//         }

//         /* 2. IF TREE IS NOT EMPTY, CREATE NEWNODE AS LEAF NODE WITH COLOR RED */
//         point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
//                                           // is passed by reference
//         point->parent = parent;
//         point->color = RED;
        
//         RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree        
        
//         /* 3. IF PARENT OF NEWNODE IS BLACK, THEN EXIT */
//         if(curr_node->parent->color == BLACK){
//             return;
//         }

//         /* 4. IF PARENT OF NEWNODE IS RED, THEN CHECK THE COLOR OF PARENT'S SIBLING OF NEWNODE */
//         if(curr_node->parent->color == RED){

//             /* check if this contains only child and parent */
//             if(curr_node->parent->parent == nullptr){
//                 insert(toInsert, point, curr_node->parent); 
//             }

//             /* 4-1. IF PARENT's SIBLING's COLOR IS BLACK OR NULL, THEN DO ROTATION & RECOLOR */
//             RBTNode<T>*grandparent = curr_node->parent->parent;

//             if(curr_node->parent == grandparent->right){//if parent is the right child of grandparent
//                 if(grandparent->left->color == BLACK || grandparent->left == nullptr){
//                     //rotation
    
//                     if(curr_node == curr_node->parent->right){
//                         singleCCR(grandparent);
//                         curr_node = grandparent->parent->right;
//                         grandparent->color = RED;
//                         insert(toInsert, point, curr_node->parent); 
//                     }else{
//                         doubleCCR(grandparent); 
//                         curr_node = grandparent->parent->left;
//                         grandparent->color = RED;
//                         insert(toInsert, point, curr_node->parent); 
//                     }
//                 }
//             }else if(curr_node->parent == grandparent->left){//if parent is the left child of grandparent
//                 if(grandparent->right->color == BLACK || grandparent->right == nullptr){
//                     //rotation
//                     if(curr_node == curr_node->parent->right){
//                         doubleCR(grandparent);
//                         curr_node = grandparent->parent->right;
//                         grandparent->color = RED;
//                         insert(toInsert, point, curr_node->parent); 
//                     }else{
//                         singleCR(grandparent);
//                         curr_node = grandparent->parent->left;
//                         grandparent->color = RED;
//                         insert(toInsert, point, curr_node->parent); 
//                     }
//                 }
//             }

//             /* 4-2. IF COLOR IS RED THEN RECOLOR & ALSO CHECK IF PARENT'S PARENT OF NEWNODE IS NOT ROOT NODE, THEN RECOLOR IT & RECHECK */
//             else if(curr_node->parent == grandparent->left){//if parent is the left child of grandparent
//                 if(grandparent->right == RED){
//                     //change color
//                     curr_node->parent->color = BLACK;
//                     grandparent->right->color = BLACK;
//                     grandparent->color = RED;
//                     insert(toInsert, point, curr_node->parent); 
//                 }
//             }
//             else if(curr_node->parent == grandparent->right){//if parent is the left child of grandparent
//                 if(grandparent->left == RED){
//                     //change color
//                     curr_node->parent->color = BLACK;
//                     grandparent->left->color = BLACK;
//                     grandparent->color = RED;
//                     insert(toInsert, point, curr_node->parent); 
//                 }
//             }


//     /* RECURSIVE CASE = going down to the leaf*/
//     } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
//         insert(toInsert, point->left, point);
//     } else { // recurse down the tree to right to find correct leaf location
//         insert(toInsert, point->right, point);
//     }
// }
// }
// */


/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions. 
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/
