//dataStructure p133

#include<iostream>
using namespace std;

template<typename T>
class BinarySearchTree{
    public:
        /* constructor */
        BinarySearchTree();
        /* COPY constructor */
        BinarySearchTree(const BinarySearchTree & rhs);
        /* constructor */
        BinarySearchTree(BinarySearchTree && rhs);
        /* deconstructor */
        ~BinarySearchTree(){makeEmpty();}
        
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
        /* private member variable */
        BinaryNode* root;

    /*==============NODE STRUCT =================*/
                struct BinaryNode{
               //   struct member variables 
                T element;
                BinaryNode *left;
                BinaryNode *right;

                //  constructor 
                BinaryNode(cosnt T & theElement, BinaryNode *lt, BinaryNode *rt):element{theElement}, left{lt}, right{rt}{}
                BinaryNode(T && theElement, BinaryNode * lt, BinaryNode* rt,):element{theElement}, left{lt}, right{rt}{}
            };
    /*==========================================*/


        /*-------- private member function ---------*/
        /**
        *  - x is the iteam to insert
        *  - t is the node that roots the subtree
        *       ->Set the new root of the subtree
        */
            void insert(const T &x, BinaryNode *&t);   //*&: reference to pointer
        void insert(T && x, BinaryNode *& t);


        void remove(const T &x, BinaryNode *&t);  

        /**
        *  find the smallest item in a subtree t
        *  return node containing the smallest item 
        *       using recursion
        */
        BinaryNode* findMin(BinaryNode *t) const{
            /* base case */
            if(t == nullptr)
                return nullptr;
            /* actual return value */
            if(t->left == nullptr)
                return t;
            /* recursive call */
            return findMin(t->left);
        }

        /**
        *  find the smallest item in a subtree t
        *  return node containing the largest item 
        *      Nonrecursive implementation
        */
        BinaryNode* findMax(BinaryNode *t) const{
            if(t != nullptr)
                while(t->right != nullptr)
                    t = t->right;
            return t;
        }
            bool contains(const T &x, BinaryNode* t) const;
        void makeEmpty(BinaryNode*&t);
        void printTree(BinaryNode *&t, ostream& out) const;

        /**
        *  
        *  recursive CLONE member function
        */
        BinaryNode* clone(BinaryNode* t) const{//called by copy constructor(passed the BinarySearchTree& rhs)
            if(t == nullptr)
                return nullptr
            else 
                return new BinaryNode{t->element, clone(t->left), clone(t->right)};
        } 
};

/**
 *   
 *   DESTRUCTOR for the tree
 */
template<typename T>
void BinarySearchTree<T>::makeEmpty(BinaryNode *& t){
    if(t != nullptr){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

/* COPY constructor */
template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree & rhs)
:root(rhs){
    root = clone(rhs.root);
}

/* method to lone subtree called in copy constructor */
template<typename T>
BinaryNode* BinarySearchTree<T>::clone(BinaryNode* t) cosnt{    //!!!!!!!!!!!!!!!!! how to seperately define this function outside of the calss?

} 


/**
 *  return true if x is found in the tree 
 *      O(log N)
 */
template<typename T>
bool BinarySearchTree<T>::contains(const T&x)const{
    return contains(x, root);
}
template<typename T>
bool BinarySearchTree<T>::contains(const T &x, BinaryNode* t)const{
    if(t == nullptr)
        reutnr false;
    else if(x < t->element)
        return contains(x, t->right);
    else if(x > t->element)
        return contains(x, t->right);
    else
        return true;    // if(x==t->element)
}

/**
 *  Insert x into the tree; duplicates are ignored 
 */
template<typename T>
void BinarySearchTree<T>::insert(const T& x){
    insert(x, root);
}

/**
 *  remove x from the tree. nothing is done if x is not found 
 */
template<typename T>
void BinarySearchTree<T>::remove(const T& x){
    remove(x, root);
}

        /*-------- DELETION ---------*/
        /*
        *  - x is the iteam to remove
        *  - t is the node that roots the subtree
        *       ->Set the new root of the subtree
        */
template<typename T>
void BinarySearchTree<T>::remove(const T & x, BinaryNode *& t){
    if(t == nullptr)
        return; //item not found; do nothing
        
    if(x < t->element)
        remove(x, t->left);
    else if(x > t->element)
        remove(x, t->right);
    else if(t->left != nullptr && t->right != nullptr){
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else{
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}


        /*-------- private member function ---------*/
        /**
        *  - x is the iteam to insert
        *  - t is the node that roots the subtree
        *       ->Set the new root of the subtree
        */
template<typename T>
void BinarySearchTree<T>::insert(const T &x, BinaryNode *&t){   //*&: reference to pointer
    if(t == nullptr)
        t = new BinaryNode{x, nullptr, nullptr};
    else if(x < t->element)
        insert(x, t->left);
    else if(x > t->element)
        insert(x, t->right);
    else
        ;   //duplicate. do nothing
} 

template<typename T>
void BinarySearchTree<T>::insert(T && x, BinaryNode*& t){
    if(t == nullptr)
        t = new BinaryNode{std::move(x), nullptr, nullptr};
    else if(x < t->element)
        insert(std::move(x), t->left)
    else if(x > t->element)
        insert(std::move(x), t->right);
    else
        ;   //duplicate; do nothing
}


int main(){
    return 0;
}