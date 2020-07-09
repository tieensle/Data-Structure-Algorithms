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

    void postOrder(Node *node); // method to get nodes Left-Node-Right

public:
    Tree()
    {
        rt = NULL;
    }
    Node *root();              // return root
    void insert(string value); // insert to first

    //TODO:

    void printPostOrder(); // print Left-Right-Node

    //return elements
    vector<Node *> getPostOrder(); // return elements Left-Node-Right
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
            string s;
            cin >> s;
            tree.insert(s);
        }
        vector<Node *> nodes = tree.getPostOrder();
        cout << result(nodes) << endl;
    }

    return 0;
}

//@Code by tieenslee
