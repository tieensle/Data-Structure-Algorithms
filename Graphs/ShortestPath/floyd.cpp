// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define INF 999
using namespace std;

const int n = 4;

// int graph[n][n] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
//                    {4, 0, 8, 0, 0, 0, 0, 11, 0},
//                    {0, 8, 0, 7, 0, 4, 0, 0, 2},
//                    {0, 0, 7, 0, 9, 14, 0, 0, 0},
//                    {0, 0, 0, 9, 0, 10, 0, 0, 0},
//                    {0, 0, 4, 14, 10, 0, 2, 0, 0},
//                    {0, 0, 0, 0, 0, 2, 0, 1, 6},
//                    {8, 11, 0, 0, 0, 0, 1, 0, 7},
//                    {0, 0, 2, 0, 0, 0, 6, 7, 0}};

int graph[n][n] = {{0, 1, 1, 0},
                   {0, 0, 0, -3},
                   {0, -1, 0, -1},
                   {3, 0, 0, 0}};

int d[n][n];
int nex[n][n];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = graph[i - 1][j - 1] == 0 ? INF : graph[i - 1][j - 1];
            nex[i][j] = j;
        }
    }
}
void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    nex[i][j] = nex[i][k];
                }
            }
        }
    }
}
void print(int s, int t)
{
    if (d[s][t] >= INF)
    {
        cout << "No path from " << s << " to " << t << endl;
        return;
    }
    cout << "Path from " << s << " to " << t << " : ";
    while (s != t)
    {
        cout << s << " -> ";
        s = nex[s][t];
    }
    cout << t << endl;
}

int main()
{

    init();
    floyd();
    print(1, 4);
    print(3, 4);
    return 0;
}