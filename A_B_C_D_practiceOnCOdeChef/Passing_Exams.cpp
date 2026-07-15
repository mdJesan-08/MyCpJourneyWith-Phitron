#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	
	cin >> T;
	
	while(T--)
	{
	    int X, Y, Z;
	    
	    cin >> X >> Y >> Z;
	    
	    int passCnt = 0;
	    
	    int passMark = 50;
	    
	    if(X >= passMark) passCnt++;
	    if(Y >= passMark) passCnt++;
	    if( Z >= passMark) passCnt++;
	    
	    // cout << passCnt << "\n";
	    cout << ((passCnt >= 2)? "YES" : "NO") << "\n";
	}
	
	return 0;

}
