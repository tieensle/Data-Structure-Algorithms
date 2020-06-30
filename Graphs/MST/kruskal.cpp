// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int n = 6; // size of matrix
int graph[n][n] = {
    {0, 3, 0, 0, 6, 5},
    {3, 0, 1, 0, 0, 4},
    {0, 1, 0, 6, 0, 4},
    {0, 0, 6, 0, 8, 5},
    {6, 0, 0, 8, 0, 2},
    {5, 4, 4, 5, 2, 0}};
// int graph[n][n] = { // graph
//     {0, 2, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {2, 0, 2, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0},
//     {1, 2, 0, 4, 0, 5, 0, 0, 0, 0, 0, 0, 0},
//     {3, 0, 4, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 5, 0, 6, 0, 0, 0, 6, 0, 0, 0},
//     {0, 5, 5, 5, 6, 0, 6, 6, 6, 6, 0, 0, 0},
//     {0, 5, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 6, 6, 0, 7, 0, 0, 7, 7},
//     {0, 0, 0, 0, 0, 6, 0, 7, 0, 7, 7, 0, 0},
//     {0, 0, 0, 0, 6, 6, 0, 0, 7, 0, 7, 7, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 8, 0},
//     {0, 0, 0, 0, 0, 0, 0, 7, 0, 7, 8, 0, 8},
//     {0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 8, 0}};

vector<pair<int, pair<int, int>>> Tree;  // Vector store MST weight and edge
int d = 0;                               // Total weight of MST
vector<pair<int, pair<int, int>>> edges; // Vector to store sorted edge with ascending weight
int root[n];                             // array root of vertice

void init()
{
    Tree.clear();
    for (int i = 0; i < n; i++)
    {
        root[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] > 0)
            {
                pair<int, int> edge = make_pair(i, j);
                pair<int, pair<int, int>> weight = make_pair(graph[i][j], edge);
                edges.push_back(weight);
            }
        }
    }
    sort(edges.begin(), edges.end());
}
void print()
{
    cout << "Edges of graph: " << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        int weight = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        cout << "edge(" << u + 1 << "," << v + 1 << ") : " << weight << endl;
    }
}
void kruskal()
{
    for (int i = 0; i < edges.size(); i++)
    {
        int weight = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (root[u] != root[v])
        {
            // cout << "before: " << endl;
            // cout << "root(" << u + 1 << ") : " << root[u] + 1 << endl;
            // cout << "root(" << v + 1 << ") : " << root[v] + 1 << endl;

            pair<int, int> edge = make_pair(u, v);
            pair<int, pair<int, int>> p = make_pair(weight, edge);
            Tree.push_back(p);
            d += weight;
            // cout << "In pending: " << endl;
            int currRoot = root[v];
            for (int j = 0; j < n; j++)
            {
                // cout << "root(" << j + 1 << ") : " << root[j] + 1 << " = " << currRoot + 1 << "?" << endl;

                if (root[j] == currRoot)
                {
                    // cout << "root(" << j + 1 << ") from " << root[j] + 1;
                    root[j] = root[u];
                    // cout << " to " << root[j] + 1 << endl;
                }
            }
            // cout << "after" << endl;
            // cout << "root(" << u + 1 << ") : " << root[u] + 1 << endl;
            // cout << "root(" << v + 1 << ") : " << root[v] + 1 << endl;
        }
    }
    cout << "size of MST: " << Tree.size() << endl;
    cout << "edges of MST: " << endl;
    for (int i = 0; i < Tree.size(); i++)
    {
        int weight = Tree[i].first;
        int u = Tree[i].second.first;
        int v = Tree[i].second.second;
        cout << "edge(" << u + 1 << "," << v + 1 << ") : " << weight << endl;
    }
    cout << "Total weight: " << d << endl;
}
int main()
{
    init();
    print();
    kruskal();
    return 0;
}