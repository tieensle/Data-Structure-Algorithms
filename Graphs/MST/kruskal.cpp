// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int n = 6;
int cost[n][n] = {
    {0, 3, 0, 0, 6, 5},
    {3, 0, 1, 0, 0, 4},
    {0, 1, 0, 6, 0, 4},
    {0, 0, 6, 0, 8, 5},
    {6, 0, 0, 8, 0, 2},
    {5, 4, 4, 5, 2, 0}};

vector<int> Tree;
int d = 0;
vector<pair<int, pair<int, int>>> edges;

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] > 0)
            {
                pair<int, int> edge = make_pair(i, j);
                pair<int, pair<int, int>> weight = make_pair(cost[i][j], edge);
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
        cout << "edge(" << u << "," << v << ") : " << weight << endl;
    }
}
int main()
{
    init();
    print();

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