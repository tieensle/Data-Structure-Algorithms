#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> queue;
    while (n--)
    {
        string query;
        cin >> query;
        if (query == "POP")
        {
            if (!queue.empty())
                queue.erase(queue.begin(), queue.begin() + 1);
        }
        else if (query == "PRINTFRONT")
        {
            if (!queue.empty())
            {
                cout << queue.front() << endl;
            }
            else
                cout << "NONE" << endl;
        }
        else if (query == "PUSH")
        {
            int n;
            cin >> n;
            queue.push_back(n);
        }
    }
    return 0;
}
