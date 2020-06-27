#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> k;
        if (k == 0)
        {
            cout << 0 << endl;
            continue;
        }
        vector<long long> queue;
        queue.push_back(1);
        int i = 0;
        while (true)
        {
            if (queue.back() >= k)
                break;
            long long currNum = queue[i];
            queue.push_back(currNum * 10);
            queue.push_back(currNum * 10 + 1);
            i++;
        }
        if (queue.back() > k && queue.back() - 1 == k)
            cout << queue.size() - 1 << endl;
        else if (queue.back() - 1 > k)
            cout << queue.size() - 2 << endl;
        else
            cout << queue.size() << endl;
    }

    return 0;
}