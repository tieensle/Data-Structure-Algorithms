#include <bits/stdc++.h>

#define MAX 1001
using namespace std;

void next_bit(char x[])
{
    int n = strlen(x);
    int i = n - 1;
    while (i >= 0 && x[i] == '1')
    {
        x[i] = '0';
        i--;
    }
    if (i >= 0)
        x[i] = '1';
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char x[MAX];
        cin >> x;
        next_bit(x);
        cout << x << endl;
    }
}