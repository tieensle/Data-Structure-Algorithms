#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

void nextPermutation(int n, int a[]) {
  int i = n-2;
  while(i > 0 && a[i] > a[i+1]) {
    i--;
  }
  if(i >= 0) {
    int k = n-1;
    while(a[k] < a[i] && k > i) k--;
    swap(a[i], a[k]);
    int left = (k==0) ? i : i+1;
    int right = n-1;
    while(left < right) {
      swap(a[left], a[right]);
      left++;
      right--;
    }
  }


}
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    int a[MAX];
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    nextPermutation(n, a);
    for(int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
