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

void BubbleSort(int n, int a[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag++;
            }
        }
        if (flag == 0) // if flag no increase -> sorted (optimized)
            break;
    }
}
int main()
{
    const int n = 20;
    int a[n] = {5, 123, 8, 3, 8, 56, 4, 3, 1234, 1, 45, 9, 2, 101, 10, 12, 43, 4, 1001, 65};
    BubbleSort(n, a);
    Print(n, a);
}

//@Code by tieenslee