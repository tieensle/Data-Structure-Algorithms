// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#define INF 99999

// #define INF 65 (if 65 refer to INF?)

using namespace std;

const int n = 7;
int d[n]; // array assign temporary label for vertice
int pre[n];
vector<int> T; // vector to store vertices have temporary label

int graph[n][n] = {
    {0, 11, 65, 17, 65, 65, 65},
    {65, 0, 12, 65, 65, 10, 16},
    {65, 65, 0, 13, 14, 65, 19},
    {65, 65, 65, 0, 65, 65, 18},
    {65, 65, 65, 65, 0, 65, 15},
    {65, 13, 18, 65, 65, 0, 10},
    {65, 65, 65, 65, 65, 65, 0}};

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
}
void print(int s)
{
    s = s - 1;
    cout << "Path from " << s + 1 << " to remain vertice: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == s)
            continue;
        if (d[i] >= INF)
        {
            cout << "No path from " << s + 1 << " to " << i + 1 << endl;
            continue;
        }
        int e = i;
        while (e != s)
        {
            cout << e + 1 << " <- ";
            e = pre[e];
        }
        cout << s + 1 << " (weight = " << d[i] << ")" << endl;
    }
}

int main()
{
    int start = 1;
    init(start);
    dijkstra(start);
    print(start);
}