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
    Node *rt;                      // root of tree
    Node *create(int value);       // create new node
    vector<Node *> preOrderNodes;  // vector to store nodes use preOrder
    vector<Node *> inOrderNodes;   // vector to store nodes use inOrder
    vector<Node *> postOrderNodes; // vector to store nodes use postOrder

    void preOrder(Node *node);  // method to drive push node to vector preOrderNodes
    void inOrder(Node *node);   // method to drive push node to vector inOrderNodes
    void postOrder(Node *node); // method to drive push node to vector postOrderNodes

public:
    Tree()
    {
        rt = NULL;
    }
    Node *root(); // return root

    void insertBinary(int value); // insert with rules of binary search tree

    void printPostOrder(); // print node use postOrder (Left-Right-Node)

    vector<Node *> getPostOrder(); // return Nodes Left-Right-Node

    void buildBinaryTree(vector<int> v); // build binary tree from a array
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
    int t;
    cin >> t;
    while (t--)
    {
        Tree tree;
        vector<int> v;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        tree.buildBinaryTree(v);
        tree.printPostOrder();
    }

    return 0;
}

//@Code by tieenslee
