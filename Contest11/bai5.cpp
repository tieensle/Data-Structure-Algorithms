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
    Node *root();            // return root
    Node *parent(int value); // return parent of node

    void insert(int value); // insert to first empty node in tree
    void insertSpecial(int parent, int child, char d);
    Node *search(int value);

    void printLevelOrder(); // print use levelOrder (BFS)

    vector<Node *> getLevelOrder(); // return Nodes use BFS
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

void Tree::printLevelOrder()
{
    vector<Node *> nodes = this->getLevelOrder();
    for (int i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i]->value << " ";
    }
    cout << endl;
}

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

// void Tree::buildTree()
// {
// }

//Driver Main Program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Tree tree;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int parent, child;
            char x;
            cin >> parent >> child >> x;
            tree.insertSpecial(parent, child, x);
        }
        tree.printLevelOrder();
    }
    return 0;
}

//@Code by tieenslee
