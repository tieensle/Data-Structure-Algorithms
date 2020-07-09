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
    vector<Node *> inOrderNodes;

    void inOrder(Node *node); // method to get nodes Left-Right-Node

public:
    Tree()
    {
        rt = NULL;
    }
    Node *root();               // return root
    Node *parent(string value); // return parent of node
    void insert(string value);  // insert to first

    //TODO:

    void printInOrder(); // print Left-Node-Right

    vector<Node *> getInOrder(); // return elements Left-Right-Node

    Node *buildTree(vector<string> in, vector<string> pre, int start, int end); // build a tree from string (postOrder & inOrder);
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

int preIndex = 0;
Node *Tree::buildTree(vector<string> in, vector<string> pre, int start, int inEnd)
{

    if (start > inEnd)
        return NULL;

    /* Pick current node from Preorder 
    traversal using preIndex  
    and increment preIndex */
    Node *tNode = create(pre[preIndex]);
    if (preIndex == 0)
    {
        this->rt = tNode;
    }
    preIndex++;

    /* If this node has no children then return */
    if (start == inEnd)
        return tNode;

    /* Else find the index of this node in Inorder traversal */
    // int inIndex = search(in, start, inEnd, tNode->data);
    int inIndex = 0;
    for (int i = start; i <= inEnd; i++)
    {
        if (in[i] == tNode->value)
        {
            inIndex = i;
        }
    }

    /* Using index in Inorder traversal, construct left and  
    right subtress */
    tNode->left = buildTree(in, pre, start, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

//Driver Main Program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        preIndex = 0;
        Tree tree;
        int n;
        cin >> n;
        vector<string> in;
        vector<string> pre;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            in.push_back(s);
        }
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            pre.push_back(s);
        }
        tree.buildTree(in, pre, 0, n - 1);
        tree.printInOrder();
    }

    return 0;
}

/*
8
4 2 5 1 6 7 3 8
1 2 4 5 3 7 6 8
5
3 9 20 15 7
9 3 15 20 7
*/

//@Code by tieenslee
