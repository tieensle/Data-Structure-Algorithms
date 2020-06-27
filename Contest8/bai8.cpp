#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }

        vector<long long> queue;
        queue.push_back(1);
        queue.push_back(10);
        int i = 0;
        while (true)
        {

            if ((queue[queue.size() - 2] % n == 0))
            {
                cout << queue[queue.size() - 2] << endl;
                break;
            }
            if (queue.back() % n == 0)
            {
                cout << queue.back() << endl;
                break;
            }

            long long currNum = queue[i];
            queue.push_back(currNum * 10);
            queue.push_back(currNum * 10 + 1);
            i++;
        }
    }

    return 0;
}