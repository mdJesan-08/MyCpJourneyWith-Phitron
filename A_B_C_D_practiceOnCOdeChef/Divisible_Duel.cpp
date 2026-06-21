#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int T;
	cin >> T;
	
	while(T--)
	{
	    int X, Y;
	    cin >> X >> Y;
	    int s_even = 0, s_odd = 0;

	    for(int i = X; i <= Y ; i=i+X) 
			(i % 2 == 0)? s_even += i  : s_odd +=i;
		
		cout << ((s_even >= s_odd)? "Yes" : "No") << "\n";

	}
	
	return 0;

}
