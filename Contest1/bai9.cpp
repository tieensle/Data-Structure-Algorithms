#include <bits/stdc++.h>
#define MAX 11
using namespace std;

char XOR(char a, char b) {
  if(a == '0') {
    if(b == '0') return '0';
    if(b == '1') return '1';
  }
  if(a == '1') {
    if(b == '0') return '1';
    if(b == '1') return '0';
  }
}
string convertToGray(string binary) {	
  string gray = binary;
  for(int i = 1; i < binary.size(); i++) {
    gray[i] = XOR(binary[i], binary[i-1]);
  }
  return gray;
}

void codeGray(int n) {
  char x[MAX];
  for(int i = 0; i < n; i++) {
    x[i] = '0';
  }
  x[n] = '\0';
  bool done = false;
  while(!done) {
    string s = convertToGray(x);
    cout << s << " ";
    int i = n-1;
    while(i >= 0 && x[i] == '1') {
      x[i] = '0';
      i--;
    } 
    if(i >= 0) x[i] = '1';
    else done = true;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    codeGray(n);
    cout << endl;
  }
}
