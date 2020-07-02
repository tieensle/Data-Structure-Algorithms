#include <iostream>
#include <vector>
using namespace std;

void Print(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int n, int a[])
{

    for (int i = 1; i < n; i++)
    {
        int j = i;
        int val = a[i];
        while (a[j - 1] > val && j > 0)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = val;
    }
}
int main()
{
    const int n = 20;
    int a[n] = {5, 123, 8, 3, 8, 56, 4, 3, 1234, 1, 45, 9, 2, 101, 10, 12, 43, 4, 1001, 65};
    InsertionSort(n, a);
    Print(n, a);
}

//@Code by tieenslee
