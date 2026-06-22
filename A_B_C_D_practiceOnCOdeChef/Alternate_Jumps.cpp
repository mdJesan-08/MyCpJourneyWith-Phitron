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
	    int pos = N;
	    for(int i = 1; i <=N-1; i++)
	    {
	        if(i%2 != 0) pos = pos - (N-i);
	        else pos = pos + (N-i);
	    }
	    
	    cout << pos << "\n";
	}

}
