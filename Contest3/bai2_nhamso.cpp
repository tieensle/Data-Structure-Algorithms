#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num1, num2;
        cin >> num1 >> num2;
        int tmp1 = 0;
        int tmp2 = 0;
        long long sum = num1 + num2;
        int count = 0;
        while (num1 > 0)
        {
            int digit = num1 % 10;
            num1 /= 10;
            if (digit == 5)
            {
                tmp1 = pow(10, count) + tmp1;
            }
            if (digit == 6)
            {
                tmp2 = pow(10, count) + tmp2;
            }
            count++;
        }
        count = 0;
        while (num2 > 0)
        {
            int digit = num2 % 10;
            num2 /= 10;
            if (digit == 5)
            {
                tmp1 += pow(10, count);
            }
            if (digit == 6)
            {
                tmp2 = pow(10, count) + tmp2;
            }
            count++;
        }
        cout << sum - tmp2 << " " << sum + tmp1 << endl;
    }
    return 0;
}