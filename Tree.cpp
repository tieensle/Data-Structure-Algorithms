// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Node
{
    int value;
    Node *left;
    Node *right;
} Node;

class Tree
{
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }
    void init(int value)
    {
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    }
    void add_left(int value)
    {
    }
};
// Tree::create() {

// }

//drive code
int main()
{

    return 0;
}
