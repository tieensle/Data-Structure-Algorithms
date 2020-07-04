// #include<bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

//move disk
void moveDisk(int n, char col1, char col2)
{
    cout << "move disk " << n << " from column " << col1 << " to column " << col2 << endl;
}

//main algorithm (recursion)
void hanoiTower(int n, char from, char to, char aux)
{
    if (n == 1)
        moveDisk(1, from, to);
    else
    {
        hanoiTower(n - 1, from, aux, to);
        moveDisk(n, from, to);
        hanoiTower(n - 1, aux, to, from);
    }
    return;
}

//Driver Main Program
int main()
{
    cout << "Goal : move all disks from A to C: " << endl;
    int n;
    while (n != 0)
    {
        cout << "enter the number of disk (0 to quit): ";
        cin >> n;
        hanoiTower(n, 'A', 'C', 'B');
    }
    return 0;
}

/*
@Code by tieenslee
*/