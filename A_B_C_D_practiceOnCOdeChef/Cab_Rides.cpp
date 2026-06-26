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
	    
        int rem = N % 4;
        
        int cost = (N / 4) * 400;

        if(N/4 == 0)
        {
                if(rem == 1 || rem == 2) cost = 200;
                else cost = 300;
          
        }
        else 
        {
            if (rem > 0)
            {
                if(rem == 1) cost += 100;
                else if(rem == 2) cost+= 200;
                else cost+= 300;
            }
        }

        
        cout << cost << "\n";
	}
	
	return 0;

}
