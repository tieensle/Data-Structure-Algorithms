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

void SelectionSort(int n, int a[])
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                swap(a[i], a[j]);
            }
        }
    }
}
int main()
{
    const int n = 20;
    int a[n] = {5, 123, 8, 3, 8, 56, 4, 3, 1234, 1, 45, 9, 2, 101, 10, 12, 43, 4, 1001, 65};
    SelectionSort(n, a);
    Print(n, a);
}

//@Code by tieenslee
