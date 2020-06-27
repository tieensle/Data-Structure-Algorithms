#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> queue;
        int n;
        cin >> n;
        while (n--)
        {
            int query;
            cin >> query;
            switch (query)
            {
            case 1:
                cout << queue.size() << endl;
                break;
            case 2:
                if (queue.empty())
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                break;
            case 3:
                int num;
                cin >> num;
                queue.push_back(num);
                break;
            case 4:
                if (queue.empty())
                    break;
                queue.erase(queue.begin(), queue.begin() + 1);
                break;
            case 5:
                if (queue.empty())
                {
                    cout << "-1" << endl;
                    break;
                }
                cout << queue.front() << endl;
                break;
            case 6:
                if (queue.empty())
                {
                    cout << "-1" << endl;
                    break;
                }
                cout << queue.back() << endl;
                break;

            default:
                break;
            }
        }
    }
}