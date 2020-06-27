#include <bits/stdc++.h>
#define MAX 11
using namespace std;

void abSpec(int n, int k)
{
    bool done = false;
    char x[MAX];
    memset(x, 'A', n);
    x[n] = '\0';
    while (!done)
    {
        
        int i = n - 1;
        while (i >= 0 && x[i] == 'B')
        {
            x[i] = 'A';
            i--;
        }
        if (i >= 0)
            x[i] = 'B';
        else
            done = true;
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n , k;
        cin >> n >> k;
        abSpec(n, k);
    }
    return 0;
}
