/*
        prev = temp;        //sharing the same memory address??
*/


// TRAVERSAL 
    //pre, in, post, level

#include<iostream>
#include<queue>
using namespace std;


template<class T>
class BSTNode{
    public:
        /* constructor*/
        BSTNode(T newdata = t(), BSTNode<T>* newParent = nullptr, BSTNode<T>* newLeft=nullptr, BSTNode<T>* newRight = nullptr
        : data(nedata), parent(newParent), left(newLeft), right(newRight){}

        /* freid another class */
        freiend class BST<T>;
        
        /*accessor*/
        int getSize()const;

    private:
        T data;
        BSTNode<T>* parent;
        BSTNode<T>* left;
        BSTNode<T>* right; 
};

template<class T>
int BSTNode<T>::getSize()const{
    int count = 1;
    
    /*RECURSION IN TREE*/
    if(left!= nullptr)
        count += left->getSize();
    if(right!= nullptr)
        count += right->getSize();
    return count;
}

template<class T>
class BST{
    public:
        void printInOrder(BSTNode<T>* node);
        void printPreOrder(BSTNode<T>* node);
        void printPostOrder(BSTNode<T>* node);

        void printLevelOrder(); 
        void insert(T item);    //insertion to a tree
        void remove(BSTNode<T>* temp);  //removal from a tree

    private:
};



/*  IN   */ //left - leftUp - right - node
template<class T>
void BST<T>::printInOrder(BSTNode<T>* node){
    if(node != nullptr){
        printInOrder(node->left);
        cout<< node->data <<",";
        printInOrder(node->right);
    }
}

/*  PRE   */ //node - leftUp - left - right
template<class T>
void BST<T>::printPreOrder(BSTNode<T>* node){
    if(node!= nullptr){
        cout<<node->data<<",";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

/*  POST   */   //left - right - LeftUp *2(right side) - node
template<class T>
void BST<T>::printPostOrder(BSTNode<T>* node){
    it(node != nullptr){
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout<<node->data<<",";
    }
}


/*  LEVEL   */  //node - leftUp - rightUp - left_2_bottom - right_2_bottom
template<class T>
void BST<T>::printLevelOrder(){
    queue<BSTNode<T>*>q;
    q.push(root);
    while(!q.empty()){
        BSTNode<T>* temp = q.front();
        q.pop();    //node
        cout<<temp->data<<",";

        if(temp->left !== nullptr)
            q.push(temp->left); //recursive
        if(temp->right != nullptr)
            q.push(temp->right);    //reursive
    }
}


/* ADDing elements to a BST (binary search tree) */
template<class T>
void BST<T>::insert(T iteam){
    /* base case */
    if(root == nullptr){  //if tree is empty
        root = new BSTNode<T>(item);
        return;
    }

    BSTNode<T>* temp = root;
    BSTNode<T>* prev = root;

    while(temp != nullptr){
        prev = temp;        //sharing the same memory address??
        if(item < temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }

        if(item < prev->data)
            prev->left = new BSTNode<T>(item, prev);
        else
            prev->right = new BSTNode<T>(item, prev);
    }
    if(item < prev->data){
        prev->left = new BSTNode<T>(item, prev);
    }
}


/* removal, Given the Node, No Children */
template<class T>
void BST<T>::remove(BSTNode<T>* temp){
    if(temp->left == nullptr && temp->right == nullptr){//if ther is NO children
        if(parent == nullptr)
            root = nullptr;
        else if(parent->left == temp)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete temp;
    }

    /* REMOVAL, Given the Node, ONE CHILD */
    // LEFT
    else if(temp->left ==nullptr){  
        BSTNode<T>* willBeCopied = temp->right;
        temp->data = willBeCopied->data;
        temp->left = willBeCopied->left;
        if(temp->left != nullptr)
            temp->left->parent = temp;
        temp->right = willBeCopied->right;
        if(temp->right != nullptr)
            temp->right->parent = temp;
        delete willBeCopied;
    }
    //RIGHT
    else if(temp->right == nullptr){    
        BSTNode<T>* willBeCopied = temp->left;
        temp->data = willBeCopied->data;//copy
        temp->left = willBeCopied->left;
        if(temp->left != nullptr)
            temp->left->parent = temp;
        temp->right = willBeCopied->right;
        if(temp->right != nullptr)
            temp->right->parent = temp;
        delete willBeCopied;
    }

    /* REMOVAL, GIVEN THE NODE, TWO CHILEDREN */
    else{
        BSTNode<T>* minOfRight = temp->right;
        while(minOfRight->left != nullptr)
            minOfRight = minOfRight->left;
        temp->data = minOfRight->data;
        //RECURSION
        remove(minOfRight);

    }
}

int main(){

    return 0;
}