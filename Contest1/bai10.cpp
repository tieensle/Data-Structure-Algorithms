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


int main() {
  int t;
  cin >> t;
  while(t--) {
    string binary;
    cin >> binary;
    string gray = convertToGray(binary); 
    cout << gray << endl;
  }
}
