#include <iostream>
#include <vector>

using namespace std;

void jumping_num(int n)
{
    vector<int> stack;
    if (n <= 10)
    {
        for (int i = 0; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i <= 10; i++)
    {
        stack.push_back(i);
    }
    int c = 1;
    while (stack.back() < n)
    {
        int curr = stack[c];
        int digit = curr % 10 + 1;
        int left = curr * 10 + digit - 2;
        int right = curr * 10 + digit;
        if (digit > 2)
        {
            stack.push_back(left);
        }
        if (digit < 10)
        {
            stack.push_back(right);
        }
        c++;
    }
    if (stack.back() > n)
    {
        stack.pop_back();
        if (stack.back() > n)
        {
            stack.pop_back();
        }
    }
    for (int i = 0; i < stack.size(); i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        jumping_num(n);
    }
}