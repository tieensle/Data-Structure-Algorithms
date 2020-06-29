// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int n = 13;
// int graph[n][n] = {
//     {0, 3, 0, 0, 6, 5},
//     {3, 0, 1, 0, 0, 4},
//     {0, 1, 0, 6, 0, 4},
//     {0, 0, 6, 0, 8, 5},
//     {6, 0, 0, 8, 0, 2},
//     {5, 4, 4, 5, 2, 0}};
int graph[n][n] = {
    {0, 2, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0},
    {1, 2, 0, 4, 0, 5, 0, 0, 0, 0, 0, 0, 0},
    {3, 0, 4, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 5, 0, 6, 0, 0, 0, 6, 0, 0, 0},
    {0, 5, 5, 5, 6, 0, 6, 6, 6, 6, 0, 0, 0},
    {0, 5, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 6, 6, 0, 7, 0, 0, 7, 7},
    {0, 0, 0, 0, 0, 6, 0, 7, 0, 7, 7, 0, 0},
    {0, 0, 0, 0, 6, 6, 0, 0, 7, 0, 7, 7, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 8, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 0, 7, 8, 0, 8},
    {0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 8, 0}};

vector<pair<int, int>> Tree;
int d = 0;
vector<pair<int, pair<int, int>>> edges;
vector<int> verticesOut;
vector<int> vertices;

int root[n];

void init()
{
    Tree.clear();
    for (int i = 0; i < n; i++)
    {
        root[i] = i;
        vertices.push_back(i);
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
    cout << "do thi gom nhung canh: " << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        int weight = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        cout << "edge(" << u + 1 << "," << v + 1 << ") : " << weight << endl;
    }
}

void prim()
{
}

int main()
{
    init();
    print();
}