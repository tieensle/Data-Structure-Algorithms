#include <bits/stdc++.h>
using namespace std;

int milatary(int nums[], int n, int k) {
  bool *check = new bool[k];
  memset(check, 0, n);
  int count = 0;
  for(int i = 0; i < k; i++) {
    check[nums[i]] = 1;
  }
  int i = k - 1;
  while(i >= 0 && nums[i] == n-k+i+1) i--;
  if(i >= 0) {
    nums[i]++;
    for(int j = i+1; j < k; j++) {
      nums[j] = nums[i] + j - i;
    }
  }
  else return k;
  for(int i = 0; i < k; i++) {
    if(check[nums[i]]==0) count++;
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    int nums[k];
    for(int i = 0; i < k; i++) {
      cin >> nums[i];
    }
    cout << milatary(nums, n, k) << endl;
  }
}
