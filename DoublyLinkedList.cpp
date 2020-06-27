#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int value;
    Node *previous;
    Node *next;
} Node;

class DBList
{
private:
    Node *head;
    Node *tail;

public:
    DBList()
    {
        head = NULL;
        tail = NULL;
    }
    int front()
    {
        return head->value;
    }
    int back()
    {
        return tail->value;
    }
    bool empty()
    {
        return this->head == NULL;
    }
    int size()
    { //duyet tat ca cac node
        int count = 0;
        Node *tmp = head;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            count++;
        }
        return count;
    }
    void show()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            if (tmp == tail)
                cout << tmp->value << endl;
            else
                cout << tmp->value << " -> ";
            tmp = tmp->next;
        }
    }
    void push(int value)
    { // them node moi vao cuoi
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;
        newNode->previous = NULL;
        if (this->empty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop()
    { // xoa node cuoi cung cua list
        if (!this->empty())
        {
            tail = tail->previous;
            tail->next = NULL;
        }
    }
    void unshift(int value)
    { // them node vao dau cua list
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;
        newNode->previous = NULL;
        if (this->empty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void shift()
    { // xoa node dau tien cua list
        if (!this->empty())
        {
            head = head->next;
            head->previous = NULL;
        }
    }

    void insert(int value, int index)
    { // chen node moi vao vi tri index (bat dau tu 0)
        if (this->empty())
        {
            this->push(value);
        }
        else
        {
            index--;
            Node *tmp = head;
            while (index--)
            {
                tmp = tmp->next;
            }
            Node *newNode = new Node;
            newNode->value = value;
            newNode->next = tmp->next;
            newNode->previous = tmp;
            tmp->next->previous = newNode;
            tmp->next = newNode;
        }
    }
    void erase(int index)
    { // xoa node o vi tri index (bat dau tu 0)
        if (index > this->size() - 1)
            return;
        Node *tmp = head;
        index--;
        while (index--)
        {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        tmp = tmp->next;
        tmp->previous = tmp->previous->previous;
        // tmp->next->previous = tmp;
    }
    void clear()
    { //xoa toan bo node
        head = NULL;
        tail = NULL;
    }
};
int main()
{
    DBList dbl;
    dbl.push(1);
    dbl.push(2);
    dbl.push(3);
    dbl.unshift(0);
    int front = dbl.front();
    int back = dbl.back();
    cout << front << " " << back << endl;
    dbl.show();
    dbl.pop();
    dbl.show();
    dbl.insert(100, 2);
    dbl.show();
    dbl.erase(2);
    dbl.show();

    return 0;
}