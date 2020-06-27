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
string convertToBinary(string gray) {
  string binary = gray;
  for(int i = 1; i < gray.size(); i++) {
    binary[i] = XOR(gray[i], binary[i-1]);
  }
  return binary;
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    string gray;
    cin >> gray;
    string binary = convertToBinary(gray); 
    cout << binary << endl;
  }
}
