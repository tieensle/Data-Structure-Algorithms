#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int num[MAX];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        sort(num, num + n);
        cout << endl;
        long num1 = 0;
        long num2 = 0;
        int i = 0;
        while (num[i] == 0)
        {
            i++;
        }
        for (i; i < n; i += 2)
        {
            num1 = num1 * 10 + num[i];
            if (i + 1 < n)
            {
                num2 = num2 * 10 + num[i + 1];
            }
        }
        cout << num1 + num2 << endl;
    }
}