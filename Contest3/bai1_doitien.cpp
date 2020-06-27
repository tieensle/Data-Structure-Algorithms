#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int money[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    while (t--)
    {
        int n;
        cin >> n;
        int i = 9;
        int count = 0;
        while (n > 0)
        {
            // cout << n << " ";
            if (n < money[i])
                i--;
            else
            {
                n -= money[i];
                count++;
            }
        }
        cout << count << endl;
    }
}