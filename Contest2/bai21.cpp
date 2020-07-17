// #include<bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

void stringPermutation(string str, int left, int right)
{
    if (left == right)
        cout << str << " ";
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(str[left], str[i]);
            stringPermutation(str, left + 1, right);
            swap(str[left], str[i]); //swap back for backtracking
        }
    }
}
//Driver Main Program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        stringPermutation(str, 0, str.size() - 1);
        cout << endl;
    }
    return 0;
}

//@Code by tieenslee