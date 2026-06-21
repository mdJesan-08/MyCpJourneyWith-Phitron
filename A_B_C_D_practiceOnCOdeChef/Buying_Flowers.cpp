#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
	{
	    int N;
	    cin >> N;

	    if( N%3 == 0 || N%3 == 2)
	    {
	        cout << (N/3)*5 + ((N%3)/2)*4 << "\n";
	    }

	    else
	    {
	    //    if(N%2 == 0)  cout << (N/2)*4 << "\n";
	       
	       {
	           cout << ((N/3) -1)*5 + 4*2 << "\n";
	       }
	    }
	}
 return 0;
}
