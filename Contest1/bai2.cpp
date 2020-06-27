#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

void nextCombination(int a[], int n, int k) {
  int i = k-1;
  while(i >= 0 && a[i] == n-k+i+1) {
    i--;
  } 
  if(i >=  0) {
    a[i] = a[i] + 1;
    for(int j = i+1; j < k; j++) {
      a[j] = a[i]+j-i;
    }
  }
  else {
    for(int j = 0; j < k; j++) {
      a[j] = j+1;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    // vector<int> v;
    int a[MAX];
    for(int i = 0; i < k; i++) {
      cin >> a[i];
    }
    nextCombination(a, n, k);
    for(int i = 0; i < k; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
