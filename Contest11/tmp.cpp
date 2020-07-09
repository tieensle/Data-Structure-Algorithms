// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct Node
{
    string value;
    Node *left;
    Node *right;
} Node;

class Tree
{
private:
    Node *rt;
    Node *create(string value); // create new node
    vector<Node *> preOrderNodes;
    vector<Node *> inOrderNodes;
    vector<Node *> postOrderNodes;

    void preOrder(Node *node);  // method to get nodes Node-Left-Right
    void postOrder(Node *node); // method to get nodes Left-Node-Right
    void inOrder(Node *node);   // method to get nodes Left-Right-Node

public:
    Tree()
    {
        rt = NULL;
    }
    Node *root();               // return root
    Node *parent(string value); // return parent of node
    void insert(string value);  // insert to first

    //TODO:

    //? Print
    void printPreOrder();   // print Node-Left-Right
    void printInOrder();    // print Left-Node-Right
    void printPostOrder();  // print Left-Right-Node
    void printLevelOrder(); // print use BFS

    //return elements
    vector<Node *> getPreOrder();  // return elements Node-Left-Right
    vector<Node *> getPostOrder(); // return elements Left-Node-Right
    vector<Node *> getInOrder();   // return elements Left-Right-Node
    vector<Node *> levelOrder();   // return elements use BFS

    void buildTreePreOrder(string s);  // build a tree from string (preOrder);
    void buildTreeInOrder(string s);   // build a tree from string (inOrder)
    void buildTreePostOrder(string s); // build a tree from string (postOrder);
};

Node *Tree::root()
{
    return this->rt;
}
Node *Tree::create(string value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *Tree::parent(string value)
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
void Tree::insert(string value)
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

vector<Node *> Tree::levelOrder()
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
    vector<Node *> nodes = this->levelOrder();
    for (int i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i]->value << " ";
    }
    cout << endl;
}

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

vector<Node *> Tree::getPreOrder()
{
    preOrder(this->root());
    return this->preOrderNodes;
}

vector<Node *> Tree::getInOrder()
{
    inOrder(this->root());
    return this->inOrderNodes;
}

vector<Node *> Tree::getPostOrder()
{
    postOrder(this->root());
    return this->postOrderNodes;
}

bool isOperator(string c)
{
    if (c == "+" || c == "-" ||
        c == "*" || c == "/")
        return true;
    return false;
}

int calculate(string c, int num1, int num2)
{
    if (c == "+")
    {
        return num1 + num2;
    }
    if (c == "-")
    {
        return num1 - num2;
    }
    if (c == "*")
    {
        return num1 * num2;
    }
    return num1 / num2;
}

int result(vector<Node *> nodes)
{
    vector<int> stack;
    for (int i = 0; i < nodes.size(); i++)
    {
        if (!isOperator(nodes[i]->value))
        {

            stack.push_back(stoi(nodes[i]->value));
        }
        else
        {
            int num1 = stack.back();
            stack.pop_back();
            int num2 = stack.back();
            stack.pop_back();
            int res = calculate(nodes[i]->value, num2, num1);
            stack.push_back(res);
        }
    }

    return stack.back();
}

// void Tree::buildTreePostOrder(string s)
// {
//     vector<Node *> stack; // stack to push node
//     for (int i = 0; i < s.size(); i++)
//     {
//         Node *newNode = create(s[i]);
//         if (isOperator(s[i]))
//         {
//             newNode->right = stack.back(); // get top node in stack
//             stack.pop_back();
//             newNode->left = stack.back();
//             stack.pop_back();
//             stack.push_back(newNode);
//         }
//         else
//             stack.push_back(newNode);
//     }
//     this->rt = stack.back();
// }

// 6
// 4 2 5 1 3 6
// 1 2 4 5 3 6

void Tree::buildTreePreOrder(string s)
{
}

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
        string str = "";
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            str += s;
        }
        tree.buildTreePreOrder(str);
        tree.printPostOrder();
    }

    return 0;
}

//@Code by tieenslee
