#include <bits/stdc++.h>
#define MAX 11
using namespace std;

void nextPermutation(int n) {
  int a[MAX];
  int done = false;
  for(int i = 0; i < n; i++) {
    a[i] = i+1;
  }
  while(!done) {
    for(int j = 0; j < n; j++) {
      cout << a[j];
    }
    cout << " ";
    int i = n-2;
    while(i >= 0 && a[i] > a[i+1]) i--;
    if(i >= 0) {
      int k = n-1;
      while(k > i && a[k] < a[i]) k--;
      swap(a[i], a[k]);
      int left = i+1;
      int right = n-1;
      while(left < right) {
        swap(a[left], a[right]);
        left++;
        right--;
      }
    }
    else {
      done = true;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    nextPermutation(n);
    cout << endl;
  }
}
