// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define INF 99999
using namespace std;

const int n = 9;

int graph[n][n] = {{0, 7, 0, 9, 4, 0, 0, 0, 0},
                   {0, 0, 3, 0, -4, 0, 0, 0, 0},
                   {0, 0, 0, 0, -8, 0, -3, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, -4, 0},
                   {0, 0, 0, 5, 0, 2, 0, 3, 0},
                   {0, 0, 0, 0, 0, 0, 5, 0, 2},
                   {0, 0, 0, 0, 0, 0, 0, 0, -7},
                   {0, 0, 0, 0, 0, -2, 0, 0, -3},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};

int d[n][n];
int nex[n][n];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = (graph[i - 1][j - 1] == 0) ? INF : graph[i - 1][j - 1];
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
                if (d[i][j] > d[i][k] + d[k][j] && d[i][k] != INF && d[k][j] != INF)
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
    if (s == t)
        return;
    if (d[s][t] >= INF)
    {
        cout << "No path from " << s << " to " << t << endl;
        return;
    }
    cout << "Path from " << s << " to " << t << " : ";
    int weight = d[s][t];
    while (s != t)
    {
        cout << s << " -> ";
        s = nex[s][t];
    }
    cout << t << " (weight = " << weight << ")" << endl;
}

int main()
{

    init();
    floyd();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            print(i, j);
        }
    }
    return 0;
}