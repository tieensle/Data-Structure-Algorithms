// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> stack;
    while (stack.size() <= 200)
    {
        string query;
        cin >> query;
        if (query == "push")
        {
            int n;
            cin >> n;e
            stack.push_back(n);
        }
        if (query == "pop")
        {
            if (!stack.empty())
            {
                stack.pop_back();
            }
        }
        if (query == "show")
        {
            if (stack.empty())
            {
                cout << "empty";
            }
            else
            {
                for (int i = 0; i < stack.size(); i++)
                {
                    cout << stack[i] << " ";
                }
                cout << endl;
            }
        }
    }
}