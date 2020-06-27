#include <bits/stdc++.h>
#define MAX 17
using namespace std;

void kBit1(int n, int k) {
  char x[MAX];
  bool done = false;
  for(int i = 0; i < n; i++) {
	  x[i] = '0';
  }
  x[n] = '\0';
  int count = 0;
  while(!done) {
    if(count == k) cout << x <<endl;
    int i = n-1;
    while(i >= 0 && x[i] == '1') {
      x[i] = '0';
      if(count > 0) count--;
      i--;
    }
    if(i >= 0) {
      x[i] = '1';
      count++;
    }
    else done = true;
  }

}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    kBit1(n, k);
  }
}
