#include <bits/stdc++.h>
#define MAX 11

using namespace std;

int nextPermutation(int n)
{
}
int sumOfNums(int n)
{
    int nums[MAX];
    int sum;
    memset(nums, 0, n - 1);
    nums[n - 1] = 1;
    cout << "(" << n << ")";
    int i = 0;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        sumOfNums(n);
    }
    return 0;
}
