//dataStructure p133

#include<iostream>
using namespace std;

template<typename T>
class BinarySearchTree{
    public:
        /* constructor */
        BinarySearchTree();
        /* constructor */
        BinarySearchTree(const BinarySearchTree & rhs);
        /* constructor */
        BinarySearchTree(BinarySearchTree && rhs);
        /* deconstructor */
        ~BinarySearchTree();
        
        /* const-func */
        const T &findMin() const;
        const T &findMax() const;

        bool contains(const T & x) const;
        bool isEmpty() const;
        void printTree( ostream& out = cout) const;

        /* edition-func */
        void makeEmpty();
        void insert(const T & x);
        void insert(T && x);
        void remove(const T & x);

        /* overloading operator */
        BinarySearchTree & operator=(const BinarySearchTree & rhs);
        BinarySearchTree & operator = (BinarySearchTree && rhs);

    private;

        /* --- NODE --- */
        struct BinaryNode{
            /* struct member variables */
            T element;
            BinaryNode *left;
            BinaryNode *right;

            /* constructor */
            BinaryNode(cosnt T & theElement, BinaryNode *lt, BinaryNode *rt):element{theElement}, left{lt}, right{rt}{}
            BinaryNode(T && theElement, BinaryNode * lt, BinaryNode* rt,):element{theElement}, left{lt}, right{rt}{}
        };

        /* private member variable */
        BinaryNode* root;

        /* private member function */
        void isnert(consts T &x, BinaryNode *&t); //*&: reference to pointer
        void insert(T && x, BinaryNode *& t);
        void remove(const T &x, BinaryNode *&t);
        BinaryNode* findMin(BinaryNode *t) const;
        BinaryNode* findMax(BinaryNode *t) const;
        bool contains(const T &x, BinaryNode* t) const;
        void makeEmpty(BinaryNode*&t);
        void printTree(BinaryNode *&t, ostream& out) const;
        BinaryNode* clone(BinaryNode* t) const;
};

int main(){
    return 0;
}