#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int value;
    Node *next;
} Node;

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    { // ham khoi tao head = tail = NULL
        head = NULL;
        tail = NULL;
    }
    bool empty()
    { // kiem tra rong
        return this->head == NULL;
    }
    int front()
    { // gia tri dau
        if (empty())
            return false;
        return head->value;
    }
    int back()
    { // gia tri cuoi
        if (this->empty())
            return false;
        return tail->value;
    }
    void push(int value)
    { // them node moi vao cuoi list
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;
        if (this->empty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void unshift(int value)
    { // them node moi vao dau list
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = head;
        if (this->empty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head = newNode;
        }
    }
    void pop()
    { // xoa node cuoi cung
        if (!this->empty())
        {
            tail = NULL;
        }
    }
    void shift()
    { // xoa node dau tien
        if (!this->empty())
        {
            head = head->next;
        }
    }
    void show()
    { //duyet tat ca cac node
        if (this->empty())
            return;
        Node *tmp = head;
        while (tmp != NULL)
        {
            if (tmp == tail)
                cout << tmp->value;
            else
                cout << tmp->value << " -> ";
            tmp = tmp->next;
        }

        cout << endl;
    }
    int size()
    { // do dai cua list
        int count = 0;
        Node *tmp = head;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            count++;
        }
        return count;
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
    }
    void clear()
    { //xoa toan bo node
        head = NULL;
        tail = NULL;
    }
};

int main()
{
    LinkedList l;
    l.push(1);
    l.push(2);
    l.push(4);
    l.insert(3, 2);
    l.erase(2);
    int front = l.front();
    int back = l.back();
    cout << front << " " << back << endl;
    l.show();
    l.clear();
    l.show();
}