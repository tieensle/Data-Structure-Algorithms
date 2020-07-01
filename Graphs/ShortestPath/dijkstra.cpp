// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#define INF 9999

using namespace std;

const int n = 9;
int d[n]; // array assign temporary label for vertice
int pre[n];
vector<int> T; // vector to store vertices have temporary label

int graph[n][n] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                   {4, 0, 8, 0, 0, 0, 0, 11, 0},
                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
                   {0, 0, 4, 14, 10, 0, 2, 0, 0},
                   {0, 0, 0, 0, 0, 2, 0, 1, 6},
                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
                   {0, 0, 2, 0, 0, 0, 6, 7, 0}};

void init(int s)
{ // s is start node
    T.clear();
    s = s - 1; // -1 because index start from 0
    // d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != s)
        {
            T.push_back(i);
        }

        if (graph[s][i] == 0)
            d[i] = INF;
        else
            d[i] = graph[s][i];

        pre[i] = s;
    }
}

void dijkstra(int node)
{
    init(node);
    while (!T.empty())
    {
        int du = INF;
        int u;
        int pos = 0; // position of U in T
        for (int i = 0; i < T.size(); i++)
        {
            if (d[T[i]] < du)
            {
                u = T[i];
                du = d[u];
                pos = i;
            }
        }
        T.erase(T.begin() + pos, T.begin() + pos + 1); // remove vertice from T
        // cout << "T remain: " << endl;
        // for (int i = 0; i < T.size(); i++)
        // {
        //     cout << T[i] + 1 << " ";
        // }
        // cout << endl;
        for (int i = 0; i < T.size(); i++)
        {
            int v = T[i];
            int a = graph[u][v] == 0 ? INF : graph[u][v];
            if (d[v] > du + a)
            {
                d[v] = du + a;
                pre[v] = u;
            }
        }
    }
    // cout << "prev array: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << " prev " << pre[i] + 1 << " ";
    //     cout << " label " << d[i] << endl;
    // }
}
void print(int s)
{
    s = s - 1;
    cout << "Path from " << s + 1 << " to remain vertice: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == s || d[i] == INF)
            continue;
        int e = i;
        while (e != s)
        {
            cout << e + 1 << " <- ";
            e = pre[e];
        }
        cout << s + 1 << endl;
    }
}

int main()
{
    int node = 1;
    dijkstra(node);
    print(node);
}