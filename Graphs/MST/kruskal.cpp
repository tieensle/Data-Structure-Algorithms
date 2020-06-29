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
int root[n];

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
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (root[u] != root[v])
        {
            cout << "truoc duyet: " << endl;
            cout << "root cua " << u + 1 << " la " << root[u] + 1 << endl;
            cout << "root cua " << v + 1 << " la " << root[v] + 1 << endl;

            pair<int, int> p = make_pair(u, v);
            Tree.push_back(p);
            cout << "trong khi duyet: " << endl;
            int currRoot = root[v];
            for (int j = 0; j < n; j++)
            {
                cout << "root cua " << j + 1 << " la " << root[j] + 1 << " co = " << currRoot + 1 << " khong? " << endl;

                if (root[j] == currRoot)
                {
                    cout << "root cua " << j + 1 << " chuyen tu " << root[j] + 1;
                    root[j] = root[u];
                    cout << " thanh " << root[j] + 1 << endl;
                }
            }
            cout << "sau duyet: " << endl;
            cout << "root cua " << u + 1 << " la " << root[u] + 1 << endl;
            cout << "root cua " << v + 1 << " la " << root[v] + 1 << endl;
        }
    }
    cout << "sau khi duyet xong root cua cac canh la: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "root cua " << i + 1 << " la " << root[i] + 1 << endl;
    }
    cout << "so canh trong cay khung: " << Tree.size() << endl;
    cout << "cay khung gom nhung canh: " << endl;
    for (int i = 0; i < Tree.size(); i++)
    {
        int u = Tree[i].first;
        int v = Tree[i].second;
        cout << "edge(" << u + 1 << "," << v + 1 << ")" << endl;
    }
}
int main()
{
    init();
    print();
    kruskal();
    return 0;
}

// class UF {
//   vector<int> root;
//   UF(int n) { // n la so phan tu
//     for(int i = 0; i <= n; i++) {
//       root.push_back(i);
//     }
//     return root;
//   }
//   void union(int p, int q) {
//     if(root[p] == root[q]) return;
//     if(root[p] < root[q]) {
//       root[q] = root[p];
//     }
//     else root[q] = root[q];
//   }
//   bool connected(int p, int q) {
//     return root[p] == root[q];
//   }
//   int find(int p) {
//     return root[p];
//   }
// }
