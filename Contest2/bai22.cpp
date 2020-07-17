// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#define MAX 11
using namespace std;

bool hasPath = false;

void maze(int a[MAX][MAX], int n, string s, int u, int v)
{
    if (u == n - 1 && v == n - 1)
    {
        cout << s << " ";
        hasPath = true;
    }
    else
    {
        if (a[u + 1][v] == 1 && u + 1 < n)
            maze(a, n, s + 'D', u + 1, v);
        if (a[u][v + 1] == 1 && v + 1 < n)
            maze(a, n, s + 'R', u, v + 1);
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
        int n;
        int a[MAX][MAX];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        maze(a, n, "", 0, 0);
        if (!hasPath)
            cout << -1;
        cout << endl;
    }
    return 0;
}

//@Code by tieenslee