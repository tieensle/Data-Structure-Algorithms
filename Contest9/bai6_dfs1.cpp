// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int v, e, n;
vector<pair<int, int>> edgeList;
bool *visited;

void input()
{
    cin >> v >> e >> n;
    for (int i = 0; i < e; i++)
    {
        int m, n;
        cin >> m >> n;
        pair<int, int> p = make_pair(m, n);
        edgeList.push_back(p);
    }
}
void init()
{
    visited = new bool[e];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
}
void clear()
{
    edgeList.clear();
}

void dfs(int node)
{
    vector<int> stack;
    visited[node] = 1;
    stack.push_back(node);
    cout << node << " ";
    while (!stack.empty())
    {
        int s = stack.back();
        stack.pop_back();
        for (int i = 0; i < e; i++)
        {
            if (edgeList[i].first == s && visited[edgeList[i].second] == 0)
            {
                int t = edgeList[i].second;
                visited[t] = 1;
                stack.push_back(s);
                stack.push_back(t);
                cout << t << " ";
                break;
            }
            else if (edgeList[i].second == s && visited[edgeList[i].first] == 0)
            {
                int t = edgeList[i].first;
                visited[t] = 1;
                stack.push_back(s);
                stack.push_back(t);
                cout << t << " ";
                break;
            }
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        input();
        init();
        dfs(n);
        clear();
    }
}