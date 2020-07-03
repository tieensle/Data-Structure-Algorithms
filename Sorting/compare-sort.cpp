// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <chrono>
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

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
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

void Print(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

//Time to driver program
void drive_time()
{
    auto start1 = chrono::high_resolution_clock::now();

    auto finish1 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish1 - start1;
    cout << "elapsed: " << elapsed.count() << endl;
}

//Driver Main Program
int main()
{
    const int N = 20;
    int a[N] = {5, 123, 8, 3, 8, 56, 4, 3, 1234, 1, 45, 9, 2, 101, 10, 12, 43, 4, 1001, 65};
    Print(N, a);

    auto start = chrono::high_resolution_clock::now();
    // QuickSort(a, 0, N - 1);
    InsertionSort(N, a);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "elapsed: " << elapsed.count() << endl;

    Print(N, a);
    return 0;
}

//@Code by tieenslee