#include <iostream>
#include <vector>

using namespace std;
int n = 13;
int connected = true;
bool *visited;

int graph[13][13] = { // undirected graph
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0}

};
int cloneGraph[13][13] = { // undirected graph
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0}};

//Init Method
void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = cloneGraph[i][j];
        }
    }
}

// check graph connected
void dfs(int start)
{
    visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<int> stack;
    stack.push_back(start);
    visited[start] = true;
    int count = 1;
    while (!stack.empty())
    {
        int s = stack.back();
        stack.pop_back();
        for (int i = 1; i <= n; i++)
        {
            if (graph[s - 1][i - 1] > 0 && visited[i] == false)
            {
                count++;
                stack.push_back(s);
                stack.push_back(i);
                visited[i] = true;
                break;
            }
        }
    }
    if (count < n)
        connected = false;
}

// check graph has euler circuit ?
bool checkCondition()
{
    dfs(1);
    if (!connected)
        return false;
    //? this is condition for undirected graph
    for (int i = 0; i < n; i++)
    {
        int degree = 0;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] > 0)
                degree++;
        }
        if (degree % 2 != 0)
            return false;
    }
    //? this is condition for directed graph
    // for (int i = 0; i < n; i++)
    // {
    //     int degreeIn = 0;
    //     int degreeOut = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (graph[i][j] > 0)
    //             degreeOut++;
    //         if (graph[j][i] > 0)
    //             degreeIn++;
    //     }
    //     if (degreeIn != degreeOut)
    //         return false;
    // }
    return true;
}

// find euler circuit start from u vertice
void eulerCircuit(int u)
{
    init();
    vector<int> ce;
    vector<int> stack;
    stack.push_back(u);
    while (!stack.empty())
    {
        int s = stack.back();
        int i = 0;
        for (; i < n; i++)
        {
            if (graph[s][i] > 0)
            {
                stack.push_back(i);
                graph[s][i] = 0;
                graph[i][s] = 0; // if input is directed graph delete this line
                i--;
                break;
            }
        }
        if (i == n)
        {
            int t = stack.back();
            stack.pop_back();
            ce.push_back(t);
        }
    }
    for (int i = ce.size() - 1; i >= 0; i--)
    {
        cout << ce[i] + 1 << " ";
    }
    cout << endl;
}

// find all euler circuit in graph
void findEulerCircuit()
{
    if (checkCondition())
    {
        for (int i = 0; i < n; i++)
        {
            cout << "euler_circuit(" << i + 1 << "): ";
            eulerCircuit(i);
        }
    }
}

//Driver Main Program
int main()
{
    findEulerCircuit();
    return 0;
}

//@Code by tieenslee