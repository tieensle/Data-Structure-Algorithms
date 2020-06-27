// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

int v, e;
vector<pair<int, int>> edgeList;
vector<int> adjList[MAX];

void input()
{
    int m, n;
    for (int i = 0; i < e; i++)
    {
        cin >> m >> n;
        pair<int, int> p = make_pair(m, n);
        edgeList.push_back(p);
    }
}

// convert edge list to adj list
void convert()
{
    for (int i = 0; i < edgeList.size(); i++)
    {
        int first = edgeList[i].first;
        int second = edgeList[i].second;
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }
}

void print(int vertice)
{
    for (int i = 1; i <= vertice; i++)
    {
        cout << i << ": ";
        for (auto x : adjList[i])
        {
            cout << " " << x;
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> v >> e;
        input();
        convert();
        print(v);

        edgeList.clear();
    }
    return 0;
}