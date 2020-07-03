// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
// class Node
// {
// private:
//     int value;
//     Node *left;
//     Node *right;
//     Node *parent;

// public:
// Node *create(int value); // create new node

//     Node *create(int value); // create new node
//     void printPreOrder();       // print Node-Left-Right
//     void printInOrder();        // print Left-Node-Right
//     void printPostOrder();      // print Left-Right-Node
//     void printLevelOrder();     // print use BFS
//     void insert(int value);     // insert to first
//     void remove(int value);     // remove node has node = value
//     void removeAll(int value);  // remove all node has value = value
//     void findMin();             // find min of tree
//     void findMax();             // find max of tree
//     void parent(int value);     // return parent of node
//     void leftChild(int value);  // return left child
//     void rightChild(int value); // return right child

//     void search(int value);
// };

typedef struct Node
{
    int value;
    Node *left;
    Node *right;
};

class Tree
{
private:
    Node *rt;

public:
    Node *root();            // return root
    Node *create(int value); // create new node
    void insert(int value);  // insert to first
    //TODO:
    void printPreOrder();        // print Node-Left-Right
    void printInOrder();         // print Left-Node-Right
    void printPostOrder();       // print Left-Right-Node
    void printLevelOrder();      // print use BFS
    void remove(int value);      // remove node has node = value
    void removeAll(int value);   // remove all node has value = value
    void findMin();              // find min of tree
    void findMax();              // find max of tree
    Node *parent(int value);     // return parent of node
    Node *leftChild(int value);  // return left child
    Node *rightChild(int value); // return right child

    void search(int value);
};

Node *Tree::root()
{
    return this->rt;
}
Node *Tree::create(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *Tree::parent(int value)
{
    vector<Node *> stack;
    stack.push_back(this->root());
    Node *l = root()->left;
    Node *r = root()->right;
    while (l != NULL && r != NULL)
}
void Tree::insert(int value)
{
    Node *newNode = create(value);
}

template <class T>
//drive code
int main()
{
    set<T> test;
    test.insert(2);
    test.insert(4);
    test.insert(2);
    test.insert(7);

    return 0;
}
