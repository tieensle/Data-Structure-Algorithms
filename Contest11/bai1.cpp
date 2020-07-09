// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct Node
{
    char value;
    Node *left;
    Node *right;
} Node;

class Tree
{
private:
    Node *rt;
    Node *create(char value); // create new node
    vector<Node *> inOrderRes;

public:
    Tree()
    {
        rt = NULL;
    }
    Node *root(); // return root

    //TODO:

    void printInOrder(); // print Left-Node-Right

    void inOrder(Node *node); // return elements Left-Right-Node

    void buildTreePostOrder(string s); // build a tree from string postOrder
};

Node *Tree::root()
{
    return this->rt;
}
Node *Tree::create(char value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void Tree::inOrder(Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    this->inOrderRes.push_back(node);
    inOrder(node->right);
}

void Tree::printInOrder()
{
    inOrder(this->root());
    for (int i = 0; i < this->inOrderRes.size(); i++)
    {
        cout << this->inOrderRes[i]->value << " ";
    }
    cout << endl;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
        c == '*' || c == '/')
        return true;
    return false;
}

void Tree::buildTreePostOrder(string s)
{
    vector<Node *> stack; // stack to push node
    for (int i = 0; i < s.size(); i++)
    {
        Node *newNode = create(s[i]);
        if (isOperator(s[i]))
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

//Driver Main Program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Tree tree;
        string p;
        cin >> p;
        tree.buildTreePostOrder(p);
        tree.printInOrder();
    }

    return 0;
}

//@Code by tieenslee
