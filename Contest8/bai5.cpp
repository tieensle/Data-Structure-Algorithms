#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> queue;
        queue.push_back("1");
        int tmp = n;
        while (n)
        {
            string s = queue[tmp - n];
            cout << s << " ";
            n--;
            if (queue.size() >= tmp)
                continue;
            queue.push_back(s + "0");
            queue.push_back(s + "1");
        }
        cout << endl;
    }
}