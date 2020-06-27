#include <bits/stdc++.h>
#define MAX 11
using namespace std;

void nextAb(int n)
{
	bool done = false;
	char x[MAX];
	for(int i = 0; i < n; i++) {
		x[i] = 'A';
	} 
	x[n] = '\0';
	while(!done) {
	    cout << x << " ";
	    int i = n - 1;
	    while (i >= 0 && x[i] == 'B')
	    {
	        x[i] = 'A';
	        i--;
	    }
	    if (i >= 0) x[i] = 'B';
	    else done = true;
	}
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        nextAb(n);
        cout << endl;
    }
}
