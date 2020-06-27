#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long sum = 0;
        int n, k;
        cin >> n >> k;
        int num[MAX];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        sort(num, num + n);

        for (int i = k; i < n; i++)
        {
            sum += num[i];
        }
        for (int i = 0; i < k; i++)
        {
            sum -= num[i];
        }
        cout << sum << endl;
    }

    return 0;
}