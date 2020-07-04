// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

vector<pair<int, pair<int, int>>> Tree;  // Vector store MST weight and edge
int d = 0;                               // Total weight of MST
vector<pair<int, pair<int, int>>> edges; // Vector to store sorted edge with ascending weight
int root[MAX];                           // array root of vertice
int vertices, e;

void init()
{
    d = 0;
    Tree.clear();
    edges.clear();
    cin >> vertices >> e;
    for (int i = 0; i < vertices; i++)
    {
        root[i] = i;
    }

    while (e--)
    {
        int i, j, weight;
        cin >> i >> j >> weight;
        pair<int, int> edge = make_pair(i - 1, j - 1);
        pair<int, pair<int, int>> p = make_pair(weight, edge);
        edges.push_back(p);
    }
    sort(edges.begin(), edges.end());
}

void kruskal()
{
    for (int i = 0; i < edges.size(); i++)
    {
        if (Tree.size() == vertices - 1)
            break;
        int weight = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (root[u] != root[v])
        {
            pair<int, int> edge = make_pair(u, v);
            pair<int, pair<int, int>> p = make_pair(weight, edge);
            Tree.push_back(p);
            d += weight;
            int currRoot = root[v];
            for (int j = 0; j < vertices; j++)
            {
                if (root[j] == currRoot)
                {
                    root[j] = root[u];
                }
            }
        }
    }
    for (int i = 0; i < Tree.size(); i++)
    {
        int weight = Tree[i].first;
        int u = Tree[i].second.first;
        int v = Tree[i].second.second;
    }
    cout << d << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        kruskal();
    }
    return 0;
}

// 3 3
// 1 2 4
// 1 3 2
// 2 3 2

// 5 5
// 1 2 3
// 2 3 4
// 3 4 5
// 4 5 6
// 1 5 2