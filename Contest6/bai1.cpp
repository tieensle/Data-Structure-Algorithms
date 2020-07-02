#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[MAX];
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < n / 2; i++)
        {
            res.push_back(a[n - 1 - i]);
            res.push_back(a[i]);
        }
        if (n % 2 != 0)
        {
            res.push_back(a[n / 2]);
        }
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}