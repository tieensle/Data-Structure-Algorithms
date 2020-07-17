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

int d[n];
int pre[n];

void init(int s)
{ // s is start node
    for (int i = 1; i <= n; i++)
    {
        d[i] = (graph[s - 1][i - 1] == 0) ? INF : graph[s - 1][i - 1];
        pre[i] = s;
    }
}

void bellman_ford(int s)
{
    for (int k = 1; k <= n - 1; k++)
    {
        for (int v = 1; v <= n; v++)
        {
            if (v == s)
                continue;
            for (int u = 1; u <= n; u++)
            {
                if (d[v] > d[u] + graph[u - 1][v - 1] && d[u] != INF && graph[u - 1][v - 1] != 0)
                {
                    d[v] = d[u] + graph[u - 1][v - 1];
                    pre[v] = u;
                }
            }
        }
    }
}
void print(int s)
{
    cout << "Path from " << s << " to remain vertice: " << endl;
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            continue;
        if (d[i] >= INF)
        {
            cout << "No path from " << s << " to " << i << endl;
            continue;
        }
        int e = i;
        while (e != s)
        {
            cout << e << " <- ";
            e = pre[e];
        }
        cout << s << " (weight = " << d[i] << ")" << endl;
    }
}

int main()
{
    int start = 5; // node start
    init(start);
    bellman_ford(start);
    print(start);
    return 0;
}