// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// template <typename T>
typedef struct Node
{
    int value;
    Node *left;
    Node *right;
} Node;

class Tree
{
private:
    Node *rt;                       // root of tree
    Node *create(int value);        // create new node
    vector<Node *> preOrderNodes;   // vector to store nodes use preOrder
    vector<Node *> inOrderNodes;    // vector to store nodes use inOrder
    vector<Node *> postOrderNodes;  // vector to store nodes use postOrder
    vector<Node *> spiralOrderNode; // vector to store nodes use spiralOrder

    void preOrder(Node *node);  // method to drive push node to vector preOrderNodes
    void inOrder(Node *node);   // method to drive push node to vector inOrderNodes
    void postOrder(Node *node); // method to drive push node to vector postOrderNodes

public:
    Tree()
    {
        rt = NULL;
    }
    Node *root();            // return root
    Node *parent(int value); // return parent of node

    void insert(int value); // insert to first empty node in tree

    void insertSpecial(int parent, int child, char d); // insert with input is parent , child and d('L'-LEFT OR 'R'-RIGHT)

    void insertBinary(int value); // insert with rules of binary search tree

    Node *search(int value);

    //? Print
    void printPreOrder();    // print node use preOrder (Node-Left-Right)
    void printInOrder();     // print node use inOrder (Left-Node-Right)
    void printPostOrder();   // print node use postOrder (Left-Right-Node)
    void printLevelOrder();  // print use levelOrder (BFS)
    void printSpiralOrder(); // print level but with spiralOrder

    //return Nodes
    vector<Node *> getPreOrder();  // return Nodes Node-Left-Right
    vector<Node *> getInOrder();   // return Nodes Left-Node-Right
    vector<Node *> getPostOrder(); // return Nodes Left-Right-Node

    vector<Node *> getLevelOrder();  // return Nodes use levelOrder (BFS)
    vector<Node *> getSpiralOrder(); // return Nodes use spiralOrder

    //TODO:

    void remove(int value);      // remove node has node = value
    void removeAll(int value);   // remove all node has value = value
    void min();                  // find min of tree
    void max();                  // find max of tree
    Node *leftChild(int value);  // return left child
    Node *rightChild(int value); // return right child

    int height();            // return height of tree
    int heightOf(int value); // return height of node
    int depthOf(int value);  // return depth of node

    void buildBinaryTree(vector<int> v); // build binary tree from a array

    //! Some special method
    void buildTreePostOrder(string s); // build a expression (postOrder) from string input (ex: "ab+ef*g*-" -> a + b - e * f * g )
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
    if (this->root() == NULL)
        return NULL;
    vector<Node *> queue;
    queue.push_back(this->root());
    Node *n;
    while (!queue.empty() || n != NULL)
    {
        n = queue.front();
        queue.erase(queue.begin(), queue.begin() + 1);
        if (n->left == NULL)
            return NULL;
        if (n->left->value == value)
            return n;
        queue.push_back(n->left);
        if (n->right == NULL)
            return NULL;
        if (n->right->value == value)
            return n;
        queue.push_back(n->left);
    }
    return NULL;
}

Node *Tree::search(int value)
{
    vector<Node *> queue; // vector to find node by level
    if (this->root() == NULL)
        return NULL;
    queue.push_back(this->root());
    while (!queue.empty())
    {
        Node *currNode = queue.front();
        queue.erase(queue.begin(), queue.begin() + 1);
        if (currNode->value == value)
            return currNode;
        if (currNode->left != NULL)
            queue.push_back(currNode->left);
        if (currNode->right != NULL)
            queue.push_back(currNode->right);
    }

    return NULL;
}
void Tree::insert(int value)
{
    Node *newNode = create(value);
    if (this->root() == NULL)
    {
        this->rt = newNode;
        return;
    }
    vector<Node *> queue;
    queue.push_back(this->root());
    while (true)
    {
        Node *n = queue.front();
        queue.erase(queue.begin(), queue.begin() + 1);
        if (n->left == NULL)
        {
            n->left = newNode;
            return;
        }
        else
            queue.push_back(n->left);
        if (n->right == NULL)
        {
            n->right = newNode;
            return;
        }
        else
            queue.push_back(n->right);
    }
}

void Tree::insertSpecial(int parent, int child, char d)
{
    Node *parentNode = search(parent); // search parent node
    if (parentNode == NULL)
    {
        insert(parent);
        parentNode = search(parent); // after insert search again
    }
    if (d == 'L')
    {
        parentNode->left = create(child);
    }
    else if (d == 'R')
    {
        parentNode->right = create(child);
    }
}

//! LEVEL ORDER
vector<Node *> Tree::getLevelOrder()
{
    vector<Node *> res;
    if (this->root() == NULL)
        return res;
    vector<Node *> queue;
    queue.push_back(this->root());
    while (!queue.empty())
    {
        Node *n = queue.front();
        queue.erase(queue.begin(), queue.begin() + 1);
        res.push_back(n);
        if (n->left != NULL)
            queue.push_back(n->left);
        if (n->right != NULL)
            queue.push_back(n->right);
    }
    return res;
}

void Tree::printLevelOrder()
{
    vector<Node *> nodes = this->getLevelOrder();
    for (int i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i]->value << " ";
    }
    cout << endl;
}

//! SPIRAL ORDER
vector<Node *> Tree::getSpiralOrder()
{
    vector<Node *> res;
    if (this->root() == NULL)
        return res;
    vector<Node *> queue;
    queue.push_back(this->root());
    while (!queue.empty())
    {
        Node *n = queue.front();
        queue.erase(queue.begin(), queue.begin() + 1);
        res.push_back(n);
        if (n->left != NULL)
            queue.push_back(n->left);
        if (n->right != NULL)
            queue.push_back(n->right);
    }
    return res;
}

void Tree::printSpiralOrder()
{
}

//! PRE ORDER
void Tree::preOrder(Node *node)
{
    if (node == NULL)
        return;
    this->preOrderNodes.push_back(node);
    preOrder(node->left);
    preOrder(node->right);
}

void Tree::printPreOrder()
{
    preOrder(this->root());
    for (int i = 0; i < this->preOrderNodes.size(); i++)
    {
        cout << this->preOrderNodes[i]->value << " ";
    }
    cout << endl;
}

vector<Node *> Tree::getPreOrder()
{
    preOrder(this->root());
    return this->preOrderNodes;
}

//! IN ORDER
void Tree::inOrder(Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    this->inOrderNodes.push_back(node);
    inOrder(node->right);
}
void Tree::printInOrder()
{
    inOrder(this->root());
    for (int i = 0; i < this->inOrderNodes.size(); i++)
    {
        cout << this->inOrderNodes[i]->value << " ";
    }
    cout << endl;
}
vector<Node *> Tree::getInOrder()
{
    inOrder(this->root());
    return this->inOrderNodes;
}

//! POST ORDER

void Tree::postOrder(Node *node)
{
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    this->postOrderNodes.push_back(node);
}

void Tree::printPostOrder()
{
    postOrder(this->root());
    for (int i = 0; i < this->postOrderNodes.size(); i++)
    {
        cout << this->postOrderNodes[i]->value << " ";
    }
    cout << endl;
}

vector<Node *> Tree::getPostOrder()
{
    postOrder(this->root());
    return this->postOrderNodes;
}

// input is string output is tree
void Tree::buildTreePostOrder(string s)
{                         // input is string -> change all type int -> char
    vector<Node *> stack; // stack to push node
    for (int i = 0; i < s.size(); i++)
    {
        Node *newNode = create(s[i]);
        if (s[i] == '+' || s[i] == '-' ||
            s[i] == '*' || s[i] == '/')
        {
            newNode->right = stack.back(); // get top node in stack
            stack.pop_back();
            newNode->left = stack.back();
            stack.pop_back();
            stack.push_back(newNode);
        }
        else
            stack.push_back(newNode);
    }
    this->rt = stack.back();
}

void Tree::insertBinary(int value)
{
    Node *newNode = create(value);
    if (this->root() == NULL)
    {
        this->rt = newNode;
        return;
    }
    Node *currNode = this->root();

    while (true)
    {
        if (value <= currNode->value)
        {
            if (currNode->left == NULL)
            {
                currNode->left = newNode;
                return;
            }
            else
                currNode = currNode->left;
        }
        else if (value > currNode->value)
        {
            if (currNode->right == NULL)
            {
                currNode->right = newNode;
                return;
            }
            else
                currNode = currNode->right;
        }
    }
}

void Tree::buildBinaryTree(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        insertBinary(v[i]);
    }
}

//Driver Main Program
int main()
{
    Tree tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int parent, child;
        char d;
        cin >> parent >> child >> d;
        tree.insertSpecial(parent, child, d);
    }
    tree.printLevelOrder();
    tree.printSpiralOrder();
    return 0;
}

//@Code by tieenslee
