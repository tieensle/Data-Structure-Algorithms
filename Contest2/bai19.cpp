// #include<bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void triangle(vector<int> arr)
{

    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
        {
            cout << arr[i];
            break;
        }
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    if (arr.size() == 1)
        return;
    vector<int> res;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        res.push_back(arr[i] + arr[i + 1]);
    }
    return triangle(res);
}

//Driver Main Program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            v.push_back(t);
        }
        triangle(v);
    }
    return 0;
}

//@Code by tieenslee