#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    int *a;
    while (t--)
    {
        cin >> n;
        a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < n; i += 2)
        {
            if (a[i] == 0)
            {
                i--;
                continue;
            }
            num1 = num1 * 10 + a[i];
            if (i + 1 < n)
                num2 = num2 * 10 + a[i + 1];
        }
        cout << num1 + num2 << endl;
    }
}