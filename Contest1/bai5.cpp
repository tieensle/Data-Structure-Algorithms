#include <bits/stdc++.h>
#define MAX 16
using namespace std;

void nextCombination(int n, int k)
{

  int a[MAX];
  int done = false;
  for (int i = 0; i < k; i++)
  {
    a[i] = i + 1;
  }
  while (!done)
  {
    for (int j = 0; j < k; j++)
    {
      cout << a[j];
    }
    cout << " ";
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1)
    {
      i--;
    }
    if (i >= 0)
    {
      a[i] = a[i] + 1;
      for (int j = i + 1; j < k; j++)
      {
        a[j] = a[i] + j - i;
      }
    }
    else
    {
      done = true;
    }
  }
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    nextCombination(n, k);
    cout << endl;
  }
}
