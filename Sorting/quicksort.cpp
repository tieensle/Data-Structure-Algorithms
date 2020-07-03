// #include<bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // taking the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

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

//Driver Main Program
int main()
{
    const int N = 20;
    int a[N] = {5, 123, 8, 3, 8, 56, 4, 3, 1234, 1, 45, 9, 2, 101, 10, 12, 43, 4, 1001, 65};
    quickSort(a, 0, N - 1);
    Print(N, a);
    return 0;
}

//@Code by tieenslee