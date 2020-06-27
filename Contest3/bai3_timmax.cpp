// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
#define ll long long
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    ll *a;
    while (t--)
    {
        cin >> n;
        a = new ll[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            res += (i * a[i]);
            res = res % MOD;
        }
        cout << res << endl;
    }
}