// #include<bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void moveDisk(int n, char col1, char col2)
{
    cout << "move disk " << n << " from column " << col1 << " to column " << col2 << endl;
}

void hanoiTower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        moveDisk(n, a, c);
        return;
    }
    hanoiTower(n - 1, a, c, b);
    moveDisk(n, a, c);
    hanoiTower(n - 1, b, c, a);
}

//Driver Main Program
int main()
{
    int n;
    while (n != 0)
    {
        cout << "enter the number of disk (0 to quit): ";
        cin >> n;
        hanoiTower(n, 'A', 'B', 'C');
    }
    return 0;
}

/*
@Code by tieenslee
*/