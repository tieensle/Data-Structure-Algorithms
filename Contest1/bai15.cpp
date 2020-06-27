#include <bits/stdc++.h>

using namespace std;

string nextPermutationNumber(string s)
{
  for (int i = 0; i < s.length();)
  {
    if (s[i] == '0')
    {
      s.erase(i, 1);
      continue;
    }
    else
      break;
  }
  int n = s.size();
  // if (n == 0)
  //   return "BIGGEST";
  int i = n - 2;
  while (i >= 0 && (int)(s[i]) >= (int)(s[i + 1]))
    i--;
  if (i >= 0)
  {
    int k = n - 1;
    while (k > i && (int)(s[k]) <= (int)(s[i]))
      k--;
    swap(s[i], s[k]);
    int left = i + 1;
    int right = n - 1;
    while (left < right)
    {
      swap(s[left], s[right]);
      left++;
      right--;
    }
    return s;
  }
  else
    return "BIGGEST";
}

int main()
{
  int t;
  cin >> t;
  int id = 1;
  while (t--)
  {
    cout << id << " ";
    string s;
    cin >> s;
    cout << id << " " << nextPermutationNumber(s) << endl;
    id++;
  }
}
