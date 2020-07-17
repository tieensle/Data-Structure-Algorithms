// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#define MAX 11
using namespace std;

int n;
int a[MAX][MAX];
bool hasPath = false;

void maze(string s, int u, int v)
{
    if (u == n - 1 && v == n - 1)
    {
        cout << s << " ";
        hasPath = true;
    }
    else
    {
        if (a[u + 1][v] == 1 && u + 1 < n)
        {
            a[u + 1][v] = 0;
            maze(s + 'D', u + 1, v);
            a[u + 1][v] = 1;
        }
        if (a[u][v + 1] == 1 && v + 1 < n)
        {
            a[u][v + 1] = 0;
            maze(s + 'R', u, v + 1);
            a[u][v + 1] = 1;
        }
        if (a[u - 1][v] == 1 && u - 1 >= 0)
        {
            a[u - 1][v] = 0;
            maze(s + 'U', u - 1, v);
            a[u - 1][v] = 1;
        }
        if (a[u][v - 1] == 1 && v - 1 >= 0)
        {
            a[u][v - 1] = 0;
            maze(s + 'L', u, v - 1);
            a[u][v - 1] = 1;
        }
    }
}
//Driver Main Program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        hasPath = false;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        maze("", 0, 0);
        if (!hasPath)
            cout << -1;
        cout << endl;
    }
    return 0;
}

//@Code by tieenslee