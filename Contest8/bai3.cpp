#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> queue;
    while (t--)
    {
        string query;
        cin >> query;
        if (query == "PUSHFRONT")
        {
            int n;
            cin >> n;
            queue.insert(queue.begin(), n);
        }
        else if (query == "PRINTFRONT")
        {
            if (!queue.empty())
                cout << queue.front() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (query == "POPFRONT")
        {
            if (!queue.empty())
                queue.erase(queue.begin(), queue.begin() + 1);
        }
        else if (query == "PUSHBACK")
        {
            int n;
            cin >> n;
            queue.push_back(n);
        }
        else if (query == "PRINTBACK")
        {
            if (!queue.empty())
                cout << queue.back() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (query == "POPBACK")
        {
            if (!queue.empty())
                queue.pop_back();
        }
    }
    return 0;
}
