#include <iostream>
#define MAX 100000
using namespace std;

int binary_search(int arr[], int val, int left, int right)
{
    if (left == right - 1 && left != val && right != val)
        return -1;
    int mid = (right + left) / 2;
    if (arr[mid] == val)
    {
        return mid + 1;
    }
    if (arr[mid] < val)
        return binary_search(arr, val, mid, right);
    else
        return binary_search(arr, val, left, mid);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        int arr[MAX];
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int pos = binary_search(arr, k, 0, n - 1);
        if (pos == -1)
            cout << "NO" << endl;
        else
            cout << pos << endl;
    }
    return 0;
}