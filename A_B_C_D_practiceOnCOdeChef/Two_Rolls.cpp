#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
	{
	    int curLocation, start;
	    cin >> curLocation >> start;
	    
	    int maxvalOnDice = start + 5;
	    
	    int target = 50;
	    int gap = target - curLocation ; 
	   // first check is it possible to reach with the maximum value 
	   
	    int maxObtain = maxvalOnDice + maxvalOnDice;
	    bool isFound = false;

	   //possible, and possoible way to be true
	   if(gap <= maxObtain)
	   {
	      for(int i = start; i <= maxvalOnDice; i++)
          {
            if(isFound == true) break;
            for(int j = i; j <= maxvalOnDice; j++)
            {
                // cout << "(" << i << "," << j << ")" << endl;
                if((i+j) == gap) 
                {
                    cout << "Yes" << "\n";
                    isFound = true;
                }
            }

          } 
	   }


       if(isFound == false ) cout << "No" << "\n";
	   
	    
	}
	
	return 0;

}
