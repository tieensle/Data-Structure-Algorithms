#include <bits/stdc++.h>

using namespace std;

int minOperations(int x, int y)
{
    // To keep track of visited numbers
    // in BFS.
    set<int> visit;

    // Create a queue and enqueue x into it.
    queue<node> q;
    node n = {x, 0};
    q.push(n);

    // Do BFS starting from x
    while (!q.empty())
    {
        // Remove an item from queue
        node t = q.front();
        q.pop();

        // If the removed item is target
        // number y, return its level
        if (t.val == y)
            return t.level;

        // Mark dequeued number as visited
        visit.insert(t.val);

        // If we can reach y in one more step
        if (t.val * 2 == y || t.val - 1 == y)
            return t.level + 1;

        // Insert children of t if not visited
        // already
        if (visit.find(t.val * 2) == visit.end())
        {
            n.val = t.val * 2;
            n.level = t.level + 1;
            q.push(n);
        }
        if (t.val - 1 >= 0 && visit.find(t.val - 1) == visit.end())
        {
            n.val = t.val - 1;
            n.level = t.level + 1;
            q.push(n);
        }
    }
}

int convert_number(int a, int b)
{
    vector<int> queue;
    queue.push_back(a);
    int i = 0;
    int count = 0;
    long sum = 0;
    int j = 0;
    while (true)
    {

        if (queue[queue.size() - 2] == b)
            break;
        if (queue.back() == b)
            break;

        int currNum = queue[i];
        queue.push_back(currNum * 2);
        queue.push_back(currNum - 1);
        i++;
    }

    for (int i = 0; i < queue.size(); i++)
    {
        sum += pow(2, i);
        if (sum < queue.size())
            count++;
        else
            break;
    }
    cout << count << endl;
}

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        int s, t;
        cin >> s >> t;
        if (s >= t)
            convert_number(t, s);
        else
            convert_number(s, t);
    }
    return 0;
}